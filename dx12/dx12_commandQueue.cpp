#include "dx12_commandQueue.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		CommandQueue::CommandQueue() {}
		CommandQueue::~CommandQueue() {}

		// ==============================================
		// �R�}���h�L���[�̍쐬
		// ==============================================
		HRESULT CommandQueue::Create(void)
		{
			D3D12_COMMAND_QUEUE_DESC cmdQueueDesc = {};
			cmdQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;																//�^�C���A�E�g�Ȃ�
			cmdQueueDesc.NodeMask = 0;
			cmdQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;													//�v���C�I���e�B���Ɏw��Ȃ�
			cmdQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;																//�R�}���h���X�g�Ɠ��l
			return DX12Device::getInstance().Get()->CreateCommandQueue(&cmdQueueDesc, IID_PPV_ARGS(&_cmdQueue));//�R�}���h�L���[����
		}

		// ==============================================
		// �R�}���h�L���[�̎擾
		// ==============================================
		ID3D12CommandQueue* CommandQueue::Get(void)
		{
			return _cmdQueue;
		}

		// ==============================================
		// ���
		// ==============================================
		void CommandQueue::Release(void)
		{
			if (_cmdQueue)_cmdQueue->Release();
		}
	}
}