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
			// コマンドリストの作成
			// ==============================================
			HRESULT Create(ID3D12CommandAllocator* commandAllocator);

			// ==============================================
			// コマンドリストの取得
			// ==============================================
			ID3D12GraphicsCommandList* Get(void)const;

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			ID3D12GraphicsCommandList* _cmdList = nullptr;
		};
	}
}

#endif // DX12_COMMAND_LIST_H_
