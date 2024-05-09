#include "dx12_swapChain.h"
#include "dx12_dxgiFactory.h"

namespace ko
{
	namespace dx12
	{
		SwapChain::SwapChain() {}
		SwapChain::~SwapChain() {}

		// ==============================================
		// スワップチェーンの作成
		// ==============================================
		HRESULT SwapChain::Create(ID3D12CommandQueue* cmdQueue, HWND* hWnd,const UINT& width,const UINT& height)
		{
			DXGI_SWAP_CHAIN_DESC1 swapchainDesc = {};
			swapchainDesc.Width = width;
			swapchainDesc.Height = height;
			swapchainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			swapchainDesc.Stereo = false;
			swapchainDesc.SampleDesc.Count = 1;
			swapchainDesc.SampleDesc.Quality = 0;
			swapchainDesc.BufferUsage = DXGI_USAGE_BACK_BUFFER;
			swapchainDesc.BufferCount = 2;
			swapchainDesc.Scaling = DXGI_SCALING_STRETCH;
			swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
			swapchainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
			swapchainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;


			return DxgiFactory::getInstance().Get()->CreateSwapChainForHwnd(
				cmdQueue,
				*hWnd,
				&swapchainDesc,
				nullptr,
				nullptr,
				reinterpret_cast<IDXGISwapChain1**>(&_swapChain));
		}

		// ==============================================
		// スワップチェーンの取得
		// ==============================================
		IDXGISwapChain4* SwapChain::Get(void)
		{
			return _swapChain;
		}

		// ==============================================
		// 解放
		// ==============================================
		void SwapChain::Release(void)
		{
			if (_swapChain)_swapChain->Release();
		}
	}
}