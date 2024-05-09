#pragma once
#ifndef DX12_COMMAND_ALLOCATOR_H_
#define DX12_COMMAND_ALLOCATOR_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class CommandAllocator
		{
		public:
			CommandAllocator();
			~CommandAllocator();

			// ==============================================
			// �R�}���h�A���P�[�^�̍쐬
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// �R�}���h�A���P�[�^�̎擾
			// ==============================================
			ID3D12CommandAllocator* Get(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			ID3D12CommandAllocator* _cmdAllocator = nullptr;
		};
	}
}

#endif // DX12_COMMAND_ALLOCATOR_H_