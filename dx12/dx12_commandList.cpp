#include "dx12_commandList.h"
#include "dx12_device.h"
#include "dx12_commandAllocator.h"

namespace ko
{
	namespace dx12
	{
		CommandList::CommandList() {}
		CommandList::~CommandList() {}

		// ==============================================
		// �R�}���h���X�g�̍쐬
		// ==============================================
		HRESULT CommandList::Create(ID3D12CommandAllocator* cmdAllocator)
		{
			return DX12Device::getInstance().Get()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, cmdAllocator, nullptr, IID_PPV_ARGS(&_cmdList));
		}

		// ==============================================
		// �R�}���h���X�g�̎擾
		// ==============================================
		ID3D12GraphicsCommandList* CommandList::Get(void)const
		{
			return _cmdList;
		}

		// ==============================================
		// ���
		// ==============================================
		void CommandList::Release(void)
		{
			if (_cmdList)_cmdList->Release();
		}
	}
}