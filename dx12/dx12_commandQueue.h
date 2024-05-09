#pragma once
#ifndef DX12_COMMAND_QUEUE_H_
#define DX12_COMMAND_QUEUE_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class CommandQueue
		{
		public:
			CommandQueue();
			~CommandQueue();

			// ==============================================
			// �R�}���h�L���[�̍쐬
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// �R�}���h�L���[�̎擾
			// ==============================================
			ID3D12CommandQueue* Get(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			ID3D12CommandQueue* _cmdQueue = nullptr;
		};
	}
}

#endif // DX12_COMMAND_QUEUE_H_
