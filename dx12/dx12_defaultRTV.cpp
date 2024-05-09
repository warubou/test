#include "dx12_defaultRTV.h"
#include "dx12_device.h"
#include "dx12_swapChain.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		RTV::RTV() {}
		RTV::~RTV() {}

		// ==============================================
		// RTVの作成
		// ==============================================
		HRESULT RTV::Create(IDXGISwapChain1* swapChain)
		{
			_descriptorHeap = new DescriptorHeap();
			HRESULT hr = _descriptorHeap->Create(HELPER_D3D12_DESCRIPTOR_HEAP_DESC(_RTV, 2));

			// 失敗したらhrがreturnされる
			ERROR_CHECK_HRESULT(hr);
			
			DXGI_SWAP_CHAIN_DESC swcDesc = {};
			hr = swapChain->GetDesc(&swcDesc);

			_backBuffers.reserve(swcDesc.BufferCount);
			_backBuffers.resize(swcDesc.BufferCount);
			D3D12_CPU_DESCRIPTOR_HANDLE handle = _descriptorHeap->Get()->GetCPUDescriptorHandleForHeapStart();

			//SRGBレンダーターゲットビュー設定
			D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
			rtvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
			rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;

			for (int i = 0; i < swcDesc.BufferCount; ++i) {
				hr = swapChain->GetBuffer(i, IID_PPV_ARGS(&_backBuffers[i]));
				DX12Device::getInstance().Get()->CreateRenderTargetView(_backBuffers[i], &rtvDesc, handle);
				handle.ptr += DX12Device::getInstance().Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
			}

			return hr;
		}

		// ==============================================
		// ID3D12DescriptorHeapの取得
		// ==============================================
		ID3D12DescriptorHeap* RTV::Get(void)const
		{
			return _descriptorHeap->Get();
		}

		// ==============================================
		// _backBuffersの取得
		// ==============================================
		std::vector<ID3D12Resource*> RTV::GetBackBuffers(void)const
		{
			return _backBuffers;
		}

		// ==============================================
		// 解放
		// ==============================================
		void RTV::Release(void)
		{
			if (_descriptorHeap)
			{
				_descriptorHeap->Release();
				delete _descriptorHeap;
				_descriptorHeap = nullptr;
			}
		}
	}
}