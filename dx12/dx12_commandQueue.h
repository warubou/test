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
			// コマンドキューの作成
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// コマンドキューの取得
			// ==============================================
			ID3D12CommandQueue* Get(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			ID3D12CommandQueue* _cmdQueue = nullptr;
		};
	}
}

#endif // DX12_COMMAND_QUEUE_H_
