#include "dx12_singletonCommandObject.h"

namespace ko
{
	namespace dx12
	{
		// =============================================
		// 静的オブジェクトの初期化
		// =============================================
		SingletonDX12CommandObject* SingletonDX12CommandObject::instance = nullptr;

		SingletonDX12CommandObject* SingletonDX12CommandObject::getInstance(void)
		{
			if (!instance)
			{
				instance = new SingletonDX12CommandObject;
			}

			return instance;
		}

		void SingletonDX12CommandObject::SetAll(ID3D12CommandAllocator* cmdAllocator, ID3D12GraphicsCommandList* graphicsCmdList, ID3D12CommandQueue* cmdQueue, ID3D12CommandList* cmdList)
		{
			_cmdAllocator = cmdAllocator;
			_graphicsCmdList = graphicsCmdList;
			_cmdQueue = cmdQueue;
			_cmdList = cmdList;
		}

		void SingletonDX12CommandObject::SetCommandAllocator(ID3D12CommandAllocator* cmdAllocator)
		{
			_cmdAllocator = cmdAllocator;
		}

		void SingletonDX12CommandObject::SetCommandList(ID3D12CommandList* cmdList)
		{
			_cmdList = cmdList;
		}

		void SingletonDX12CommandObject::SetGraphicsCommandList(ID3D12GraphicsCommandList* graphicsCmdList)
		{
			_graphicsCmdList = graphicsCmdList;
		}

		void SingletonDX12CommandObject::SetCommandQueue(ID3D12CommandQueue* cmdQueue)
		{
			_cmdQueue = cmdQueue;
		}

		ID3D12CommandAllocator* SingletonDX12CommandObject::GetCommandAllocator(void)const
		{
			return _cmdAllocator;
		}

		ID3D12CommandList* SingletonDX12CommandObject::GetCommandList(void)const
		{
			return _cmdList;
		}

		ID3D12GraphicsCommandList* SingletonDX12CommandObject::GetGraphicsCommandList(void)const
		{
			return _graphicsCmdList;
		}

		ID3D12CommandQueue* SingletonDX12CommandObject::GetCommandQueue(void)const
		{
			return _cmdQueue;
		}
	}
}