#pragma once
#ifndef DX12_DISCRIPTOR_HEAP_H_
#define DX12_DISCRIPTOR_HEAP_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class DescriptorHeap
		{
		public:
			DescriptorHeap();
			DescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC& helperHeapDesc);
			~DescriptorHeap();

			// ==============================================
			// ディスクリプターヒープの作成
			// ==============================================
			HRESULT Create(const D3D12_DESCRIPTOR_HEAP_DESC& heapDesc);

			// ==============================================
			// ディスクリプターヒープの取得
			// ==============================================
			ID3D12DescriptorHeap* Get(void)const;

			// ==============================================
			// ディスクリプターヒープのポインターのポインターの取得
			// ==============================================
			ID3D12DescriptorHeap** GetPointer(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			ID3D12DescriptorHeap* _descriptorHeap = nullptr;
		};
	}
}

#endif // DX12_DISCRIPTOR_HEAP_H_