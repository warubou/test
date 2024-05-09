#pragma once
#ifndef DX12_FENCE_H_
#define DX12_FENCE_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class Fence
		{
		public:
			Fence();
			~Fence();

			// ==============================================
			// フェンスの作成
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// フェンスオブジェクトの取得
			// ==============================================
			ID3D12Fence* Get(void)const;

			// ==============================================
			// フェンス値の取得
			// ==============================================
			const UINT64& GetFenceValue(void)const;

			// ==============================================
			// フェンス値増加
			// ==============================================
			void IncrementFenceValue(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			ID3D12Fence* _fence = nullptr;
			UINT64 _fenceVal = 0;
		};
	}
}

#endif // DX12_FENCE_H_