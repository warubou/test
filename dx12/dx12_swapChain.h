#pragma once
#ifndef DX12_SWAP_CHAIN_H_
#define DX12_SWAP_CHAIN_H_

#include "dx12_header.h"
#include "singleton.h"

namespace ko
{
	namespace dx12
	{
		class SwapChain
		{
		public:
			SwapChain();
			~SwapChain();

			// ==============================================
			// スワップチェーンの作成
			// ==============================================
			HRESULT Create(ID3D12CommandQueue* cmdQueue, HWND* hWnd,const UINT& width,const UINT& height);

			// ==============================================
			// スワップチェーンの取得
			// ==============================================
			IDXGISwapChain4* Get(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			IDXGISwapChain4* _swapChain = nullptr;
		};
	}
}
#endif // DX12_SWAP_CHAIN_H_