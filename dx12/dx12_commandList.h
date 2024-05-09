#pragma once
#ifndef DX12_COMMAND_LIST_H_
#define DX12_COMMAND_LIST_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class CommandList
		{
		public:
			CommandList();
			~CommandList();

			// ==============================================
			// �R�}���h���X�g�̍쐬
			// ==============================================
			HRESULT Create(ID3D12CommandAllocator* commandAllocator);

			// ==============================================
			// �R�}���h���X�g�̎擾
			// ==============================================
			ID3D12GraphicsCommandList* Get(void)const;

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			ID3D12GraphicsCommandList* _cmdList = nullptr;
		};
	}
}

#endif // DX12_COMMAND_LIST_H_
