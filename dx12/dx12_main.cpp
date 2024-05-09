#include "dx12_main.h"
#include "dx12_helperStruct.h"
#include "../vector/vector.h"
#include "dx12_singletonCommandObject.h"

namespace ko
{
	namespace dx12
	{
		DX12Main::DX12Main() {}
		DX12Main::~DX12Main() {}

		HRESULT DX12Main::MainInitialize(HWND* hWnd,const UINT& width,const UINT& height)
		{
			HRESULT hr = _device.Create();
			ERROR_CHECK_HRESULT(hr);
			hr = _cmdAllocator.Create();
			ERROR_CHECK_HRESULT(hr);
			hr = _cmdList.Create(_cmdAllocator.Get());
			ERROR_CHECK_HRESULT(hr);
			hr = _cmdQueue.Create();
			ERROR_CHECK_HRESULT(hr);
			hr = _swapChain.Create(_cmdQueue.Get(), hWnd, width, height);
			ERROR_CHECK_HRESULT(hr);
			hr = _fence.Create();
			ERROR_CHECK_HRESULT(hr);
			hr = _rtv.Create(_swapChain.Get());
			ERROR_CHECK_HRESULT(hr);
			hr = _vertexBuffer.Create(sizeof(Vertex) * _VERTEX_NUM);
			ERROR_CHECK_HRESULT(hr);
			_vertexBuffer.Map();
			_vertexBuffer.Unmap();
			_vertexBuffer.SetResourceView();
			unsigned short indices[] = { 0,1,2,3 };
			hr = _indexBuffer.Create(indices, _countof(indices));
			ERROR_CHECK_HRESULT(hr);
			_indexBuffer.Map();
			_indexBuffer.Unmap();
			_indexBuffer.SetResourceView();

			_viewPort.Set(HELPER_D3D12_VIEWPORT(1920.0f, 1080.0f));
			_scissorRect.Set(HELPER_D3D12_RECT(1920, 1080));

			D3D12_INPUT_ELEMENT_DESC il[] =
			{
				{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
			};
			_inputLayout.Set(il, _countof(il));
			hr = _shader.CompileShader(L"../shader/shader.hlsl", "VSMain", "vs_5_0",
				L"../shader/shader.hlsl", "PSMain", "ps_5_0");
			//_shader.ReadPreCompileShaderBinary("../shader/vsShader.fx", _VS);
			//_shader.ReadPreCompileShaderBinary("../shader/psShader.fx", _PS);

			ERROR_CHECK_HRESULT(hr);
			hr = _rootSignature.Create();
			ERROR_CHECK_HRESULT(hr);

			_gpipeline.SetBlendState(HELPER_D3D12_BLEND_DESC(_MODE_NONE));
			_gpipeline.SetRaeterizerState(false, D3D12_CULL_MODE_NONE, D3D12_FILL_MODE_SOLID);
			_gpipeline.SetDepthStencil(false, false);
			_gpipeline.SetSamplerState(D3D12_DEFAULT_SAMPLE_MASK);
			_gpipeline.SetOneRendereTarget();
			_gpipeline.SetIBStripCutValue(D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED);
			_gpipeline.SetInputLayout(_inputLayout.Get(), static_cast<UINT>(_inputLayout.GetSize()));
			_gpipeline.SetShader(_shader.GetVSBlob(),_shader.GetPSBlob());
			//_gpipeline.SetShader(_shader.GetVSCompileBinaryData().c_str(), _shader.GetPSCompileBinaryData().c_str(), _shader.GetVSCompileBinaryDataSize(), _shader.GetPSCompileBinaryDataSize());
			_gpipeline.SetPrimitiveTopology(D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE);
			_gpipeline.SetRootSignature(_rootSignature.Get());
			hr = _gpipeline.Create();
			ERROR_CHECK_HRESULT(hr);

			static_cast<void>(SingletonDX12CommandObject::getInstance());
			SingletonDX12CommandObject::getInstance()->SetAll(_cmdAllocator.Get(), _cmdList.Get(), _cmdQueue.Get());

			return hr;
		}

		void DX12Main::InitializeRendereTest(void)
		{
			//DirectX処理
		//バックバッファのインデックスを取得
			bbIdx = _swapChain.Get()->GetCurrentBackBufferIndex();

			D3D12_RESOURCE_BARRIER BarrierDesc = {};
			BarrierDesc.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
			BarrierDesc.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
			BarrierDesc.Transition.pResource = _rtv.GetBackBuffers()[bbIdx];
			BarrierDesc.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
			BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
			_cmdList.Get()->ResourceBarrier(1, &BarrierDesc);
			_cmdList.Get()->SetPipelineState(_gpipeline.Get());

			//レンダーターゲットを指定
			auto rtvH = _rtv.Get()->GetCPUDescriptorHandleForHeapStart();
			rtvH.ptr += bbIdx * _device.Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
			_cmdList.Get()->OMSetRenderTargets(1, &rtvH, false, nullptr);

			//画面クリア
			float clearColor[] = { 1.0f,1.0f,0.0f,1.0f };//黄色
			_cmdList.Get()->ClearRenderTargetView(rtvH, clearColor, 0, nullptr);

			BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
			BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
			_cmdList.Get()->ResourceBarrier(1, &BarrierDesc);

			_cmdList.Get()->RSSetViewports(1, &_viewPort.Get());
			_cmdList.Get()->RSSetScissorRects(1, &_scissorRect.Get());

			_cmdList.Get()->SetGraphicsRootSignature(_rootSignature.Get());

			_cmdList.Get()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
			_cmdList.Get()->IASetVertexBuffers(0, 1, &_vertexBuffer.Get());
			_cmdList.Get()->IASetIndexBuffer(&_indexBuffer.Get());

			// インデックスバッファーを参照しない
			_cmdList.Get()->DrawInstanced(4, 1, 0, 0);

		}

		void DX12Main::BeginDraw(void)
		{
			//DirectX処理
			//バックバッファのインデックスを取得
			bbIdx = _swapChain.Get()->GetCurrentBackBufferIndex();

			D3D12_RESOURCE_BARRIER BarrierDesc = {};
			BarrierDesc.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
			BarrierDesc.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
			BarrierDesc.Transition.pResource = _rtv.GetBackBuffers()[bbIdx];
			BarrierDesc.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
			BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
			_cmdList.Get()->ResourceBarrier(1, &BarrierDesc);
			//_cmdList.Get()->SetPipelineState(_gpipeline.Get());

			//レンダーターゲットを指定
			auto rtvH = _rtv.Get()->GetCPUDescriptorHandleForHeapStart();
			rtvH.ptr += bbIdx * _device.Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
			_cmdList.Get()->OMSetRenderTargets(1, &rtvH, false, nullptr);

			//画面クリア
			float clearColor[] = { 1.0f,1.0f,0.0f,1.0f };//黄色
			_cmdList.Get()->ClearRenderTargetView(rtvH, clearColor, 0, nullptr);

			BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
			BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
			_cmdList.Get()->ResourceBarrier(1, &BarrierDesc);

			_cmdList.Get()->RSSetViewports(1, &_viewPort.Get());
			_cmdList.Get()->RSSetScissorRects(1, &_scissorRect.Get());
		}

		void DX12Main::EndDraw(void)
		{
			//D3D12_RESOURCE_BARRIER BarrierDesc = {};
			//BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
			//BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
			//BarrierDesc.Transition.pResource = _rtv.GetBackBuffers()[bbIdx];
			//BarrierDesc.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			//BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
			//BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

			//_cmdList.Get()->ResourceBarrier(1, &BarrierDesc);

			//命令のクローズ
			_cmdList.Get()->Close();

			//コマンドリストの実行
			ID3D12CommandList* cmdlists[] = { _cmdList.Get() };
			_cmdQueue.Get()->ExecuteCommandLists(1, cmdlists);
			////待ち
			_fence.IncrementFenceValue();
			_cmdQueue.Get()->Signal(_fence.Get(), _fence.GetFenceValue());

			if (_fence.Get()->GetCompletedValue() != _fence.GetFenceValue()) {
				auto event = CreateEvent(nullptr, false, false, nullptr);
				_fence.Get()->SetEventOnCompletion(_fence.GetFenceValue(), event);
				WaitForSingleObject(event, INFINITE);
				CloseHandle(event);
			}
			_cmdAllocator.Get()->Reset();//キューをクリア
			_cmdList.Get()->Reset(_cmdAllocator.Get(), nullptr);//再びコマンドリストをためる準備

			//フリップ
			_swapChain.Get()->Present(1, 0);
		}
	}
}