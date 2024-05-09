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
			// �f�B�X�N���v�^�[�q�[�v�̍쐬
			// ==============================================
			HRESULT Create(const D3D12_DESCRIPTOR_HEAP_DESC& heapDesc);

			// ==============================================
			// �f�B�X�N���v�^�[�q�[�v�̎擾
			// ==============================================
			ID3D12DescriptorHeap* Get(void)const;

			// ==============================================
			// �f�B�X�N���v�^�[�q�[�v�̃|�C���^�[�̃|�C���^�[�̎擾
			// ==============================================
			ID3D12DescriptorHeap** GetPointer(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			ID3D12DescriptorHeap* _descriptorHeap = nullptr;
		};
	}
}

#endif // DX12_DISCRIPTOR_HEAP_H_