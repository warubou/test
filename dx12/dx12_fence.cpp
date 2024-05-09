#include "dx12_fence.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		Fence::Fence() {}
		Fence::~Fence() {}

		// ==============================================
		// �t�F���X�̍쐬
		// ==============================================
		HRESULT Fence::Create(void)
		{
			return DX12Device::getInstance().Get()->CreateFence(_fenceVal, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&_fence));
		}

		// ==============================================
		// �t�F���X�I�u�W�F�N�g�̎擾
		// ==============================================
		ID3D12Fence* Fence::Get(void)const
		{
			return _fence;
		}

		// ==============================================
		// �t�F���X�l�̎擾
		// ==============================================
		const UINT64& Fence::GetFenceValue(void)const
		{
			return _fenceVal;
		}

		// ==============================================
		// �t�F���X�l����
		// ==============================================
		void Fence::IncrementFenceValue(void)
		{
			_fenceVal++;
		}

		// ==============================================
		// ���
		// ==============================================
		void Fence::Release(void)
		{
			if (_fence)_fence->Release();
		}
	}
}