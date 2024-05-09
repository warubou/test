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
			// RTV�̍쐬
			// ==============================================
			HRESULT Create(IDXGISwapChain1* swapChain);

			// ==============================================
			// ID3D12DescriptorHeap�̎擾
			// ==============================================
			ID3D12DescriptorHeap* Get(void)const;

			// ==============================================
			// _backBuffers�̎擾
			// ==============================================
			std::vector<ID3D12Resource*> GetBackBuffers(void)const;

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			DescriptorHeap* _descriptorHeap = nullptr;
			std::vector<ID3D12Resource*> _backBuffers;
		};
	}
}

#endif // DX12_RTV_H_