#include "dx12_sprite.h"
#include "dx12_singletonCommandObject.h"
#include "dx12_device.h"
#include "dx12_singletonGraphicsPipeline.h"

namespace ko
{
	namespace dx12
	{
		HRESULT Sprite::Init(const std::wstring& filePath)
		{
			_pGpipeline = new GraphicsPipeline();
			_pRootSignature = new RootSignature();
			_pShader = new Shader();
			_pInputLayout = new InputLayout();
			_pVertexBuffer = new VertexBuffer();

			HRESULT hr = _pVertexBuffer->Create(sizeof(Vertex));
			ERROR_CHECK_HRESULT(hr);
			_pVertexBuffer->SetPoint();

			D3D12_INPUT_ELEMENT_DESC il[] =
			{
				{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
				{"TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
			};
			_pInputLayout->Set(il, _countof(il));
			hr = _pShader->CompileShader(L"../shader/vshader.hlsl", "VSMain", "vs_5_0",
				L"../shader/pshader.hlsl", "PSMain", "ps_5_0");
			hr = _pShader->CompileGeometryShader(L"../shader/gshader.hlsl");
			//_shader.ReadPreCompileShaderBinary("../shader/vsShader.fx", _VS);
			//_shader.ReadPreCompileShaderBinary("../shader/psShader.fx", _PS);
			ERROR_CHECK_HRESULT(hr);

			// ディスクリプタレンジの設定
			D3D12_DESCRIPTOR_RANGE* dRange = new D3D12_DESCRIPTOR_RANGE[_VIEW_NUM];
			dRange[0] = HELPER_D3D12_DESCRIPTOR_RANGE(_SRV);
			dRange[1] = HELPER_D3D12_DESCRIPTOR_RANGE(_CBV);

			// ルートパラメータの設定
			D3D12_ROOT_PARAMETER* rootParam = new D3D12_ROOT_PARAMETER[_VIEW_NUM];
			int index = 0;
			while (index < _VIEW_NUM_FOR_VS)
				rootParam[index++] = HELPER_D3D12_ROOT_PARAMETER(_VS, &dRange[index], 1);
			index = 0;
			while (index < _VIEW_NUM_FOR_PS)
				rootParam[_VIEW_NUM_FOR_VS + index++] = HELPER_D3D12_ROOT_PARAMETER(_PS, &dRange[_VIEW_NUM_FOR_VS + index], 1);
			index = 0;
			while (index < _VIEW_NUM_FOR_GS)
				rootParam[_VIEW_NUM_FOR_PS + index++] = HELPER_D3D12_ROOT_PARAMETER(_GS, &dRange[_VIEW_NUM_FOR_PS + index], 1);
			

			hr = _pRootSignature->Create(dRange, rootParam, _VIEW_NUM);
			ERROR_CHECK_HRESULT(hr);

			delete[]dRange;
			delete[]rootParam;

			_pGpipeline->SetDefaultAll(_pShader->GetVSBlob(),
				_pShader->GetPSBlob(),
				_pInputLayout->Get(),
				static_cast<UINT>(_pInputLayout->GetSize()),
				_pRootSignature->Get());
			_pGpipeline->SetGeometryShader(_pShader->GetGSBlob());
			_pGpipeline->SetPrimitiveTopology(D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT);

			hr = _pGpipeline->Create();
			ERROR_CHECK_HRESULT(hr);

			SingletonGraphicsPipeline::getInstance()->Add(SingletonGraphicsPipeline::_SPRITE2D, _pGpipeline->Get());

			_pTexture = new Texture(filePath,
				SingletonDX12CommandObject::getInstance()->GetCommandAllocator(),
				SingletonDX12CommandObject::getInstance()->GetGraphicsCommandList(),
				SingletonDX12CommandObject::getInstance()->GetCommandQueue()
			);

			// ディスクリプタの作成(SRVとCBVの2つ)
			_descriptor = new DescriptorHeap(HELPER_D3D12_DESCRIPTOR_HEAP_DESC(_CBV_SRV_UAV, 2));
			// SRV
			auto descHandle = _descriptor->Get()->GetCPUDescriptorHandleForHeapStart();
			_pTexture->CreateSRV(descHandle);

			// CBを作成
			_pConstantBuffer = new ConstantBuffer();
			hr = _pConstantBuffer->Create(sizeof(UtilitySpriteC));

			// CBの中身を変える
			UtilitySpriteC* usc = nullptr;
			ID3D12Resource* tmp = _pConstantBuffer->GetResource();
			tmp->Map(0, nullptr, (void**)&usc);
			usc->texScale._x = 0.2f;
			usc->texScale._y = 0.2f;
			tmp->Unmap(0, nullptr);

			// CBVの作成
			descHandle.ptr += DX12Device::getInstance().Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
			_pConstantBuffer->CreateCBV(descHandle);
			return hr;
		}

		void Sprite::Update(void)
		{

		}

		void Sprite::Draw(void)
		{
			ID3D12CommandAllocator* cmdAllocator = SingletonDX12CommandObject::getInstance()->GetCommandAllocator();
			ID3D12GraphicsCommandList* cmdList = SingletonDX12CommandObject::getInstance()->GetGraphicsCommandList();
			ID3D12CommandQueue* cmdQueue = SingletonDX12CommandObject::getInstance()->GetCommandQueue();
			cmdList->SetPipelineState(_pGpipeline->Get());

			cmdList->SetGraphicsRootSignature(_pRootSignature->Get());

			cmdList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
			cmdList->IASetVertexBuffers(0, 1, &_pVertexBuffer->Get());

			// ヒープをセット
			cmdList->SetDescriptorHeaps(1, _descriptor->GetPointer());

			// テーブルをセット
			auto descHandle = _descriptor->Get()->GetGPUDescriptorHandleForHeapStart();
			int index = 0;
			while (index < _VIEW_NUM)
			{
				cmdList->SetGraphicsRootDescriptorTable(index++, descHandle);
				descHandle.ptr += DX12Device::getInstance().Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
			}

			// インデックスバッファーを参照しない
			cmdList->DrawInstanced(1, 1, 0, 0);
		}

		void Sprite::Release(void)
		{

		}

	}
}