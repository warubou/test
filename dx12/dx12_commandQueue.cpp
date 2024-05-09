#include "dx12_commandQueue.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		CommandQueue::CommandQueue() {}
		CommandQueue::~CommandQueue() {}

		// ==============================================
		// コマンドキューの作成
		// ==============================================
		HRESULT CommandQueue::Create(void)
		{
			D3D12_COMMAND_QUEUE_DESC cmdQueueDesc = {};
			cmdQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;																//タイムアウトなし
			cmdQueueDesc.NodeMask = 0;
			cmdQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;													//プライオリティ特に指定なし
			cmdQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;																//コマンドリストと同値
			return DX12Device::getInstance().Get()->CreateCommandQueue(&cmdQueueDesc, IID_PPV_ARGS(&_cmdQueue));//コマンドキュー生成
		}

		// ==============================================
		// コマンドキューの取得
		// ==============================================
		ID3D12CommandQueue* CommandQueue::Get(void)
		{
			return _cmdQueue;
		}

		// ==============================================
		// 解放
		// ==============================================
		void CommandQueue::Release(void)
		{
			if (_cmdQueue)_cmdQueue->Release();
		}
	}
}