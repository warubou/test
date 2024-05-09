#include "dx12_descriptorHeap.h"
#include "dx12_device.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		DescriptorHeap::DescriptorHeap() {}
		DescriptorHeap::DescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC& helperHeapDesc)
		{
			Create(helperHeapDesc);
		}
		DescriptorHeap::~DescriptorHeap() {}

		// ==============================================
		// �f�B�X�N���v�^�[�q�[�v�̍쐬
		// ==============================================
		HRESULT DescriptorHeap::Create(const D3D12_DESCRIPTOR_HEAP_DESC& heapDesc)
		{
			return DX12Device::getInstance().Get()->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&_descriptorHeap));
		}

		// ==============================================
		// �f�B�X�N���v�^�[�q�[�v�̎擾
		// ==============================================
		ID3D12DescriptorHeap* DescriptorHeap::Get(void)const
		{
			return _descriptorHeap;
		}

		// ==============================================
		// �f�B�X�N���v�^�[�q�[�v�̃|�C���^�[�̃|�C���^�[�̎擾
		// ==============================================
		ID3D12DescriptorHeap** DescriptorHeap::GetPointer(void)
		{
			return &_descriptorHeap;
		}

		// ==============================================
		// ���
		// ==============================================
		void DescriptorHeap::Release(void)
		{
			if (_descriptorHeap)_descriptorHeap->Release();
		}
	}
}