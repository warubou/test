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
			// �t�F���X�̍쐬
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// �t�F���X�I�u�W�F�N�g�̎擾
			// ==============================================
			ID3D12Fence* Get(void)const;

			// ==============================================
			// �t�F���X�l�̎擾
			// ==============================================
			const UINT64& GetFenceValue(void)const;

			// ==============================================
			// �t�F���X�l����
			// ==============================================
			void IncrementFenceValue(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			ID3D12Fence* _fence = nullptr;
			UINT64 _fenceVal = 0;
		};
	}
}

#endif // DX12_FENCE_H_