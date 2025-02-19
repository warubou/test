#pragma once
#ifndef DX12_RTV_H_
#define DX12_RTV_H_

#include "dx12_header.h"
#include "dx12_descriptorHeap.h"
#include <vector>

namespace ko
{
	namespace dx12
	{
		class RTV
		{
		public:
			RTV();
			~RTV();

			// ==============================================
			// RTVの作成
			// ==============================================
			HRESULT Create(IDXGISwapChain1* swapChain);

			// ==============================================
			// ID3D12DescriptorHeapの取得
			// ==============================================
			ID3D12DescriptorHeap* Get(void)const;

			// ==============================================
			// _backBuffersの取得
			// ==============================================
			std::vector<ID3D12Resource*> GetBackBuffers(void)const;

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			DescriptorHeap* _descriptorHeap = nullptr;
			std::vector<ID3D12Resource*> _backBuffers;
		};
	}
}

#endif // DX12_RTV_H_