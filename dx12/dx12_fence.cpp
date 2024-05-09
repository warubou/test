#include "dx12_fence.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		Fence::Fence() {}
		Fence::~Fence() {}

		// ==============================================
		// フェンスの作成
		// ==============================================
		HRESULT Fence::Create(void)
		{
			return DX12Device::getInstance().Get()->CreateFence(_fenceVal, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&_fence));
		}

		// ==============================================
		// フェンスオブジェクトの取得
		// ==============================================
		ID3D12Fence* Fence::Get(void)const
		{
			return _fence;
		}

		// ==============================================
		// フェンス値の取得
		// ==============================================
		const UINT64& Fence::GetFenceValue(void)const
		{
			return _fenceVal;
		}

		// ==============================================
		// フェンス値増加
		// ==============================================
		void Fence::IncrementFenceValue(void)
		{
			_fenceVal++;
		}

		// ==============================================
		// 解放
		// ==============================================
		void Fence::Release(void)
		{
			if (_fence)_fence->Release();
		}
	}
}