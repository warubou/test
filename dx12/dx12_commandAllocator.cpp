#include "dx12_commandAllocator.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		CommandAllocator::CommandAllocator() {}
		CommandAllocator::~CommandAllocator(){}

		// ==============================================
		// コマンドアロケータの作成
		// ==============================================
		HRESULT CommandAllocator::Create(void)
		{
			return DX12Device::getInstance().Get()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&_cmdAllocator));
		}

		// ==============================================
		// コマンドアロケータの取得
		// ==============================================
		ID3D12CommandAllocator* CommandAllocator::Get(void)
		{
			return _cmdAllocator;
		}

		// ==============================================
		// 解放
		// ==============================================
		void CommandAllocator::Release(void)
		{
			_cmdAllocator->Release();
		}

	}
}