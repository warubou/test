#pragma once
#ifndef DX12_SINGLETON_COMMAND_OBJECT_H_
#define DX12_SINGLETON_COMMAND_OBJECT_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class SingletonDX12CommandObject
		{
		public:

			static SingletonDX12CommandObject* getInstance(void);

			void SetAll(ID3D12CommandAllocator* cmdAllocator = nullptr, ID3D12GraphicsCommandList* graphicsCmdList = nullptr, ID3D12CommandQueue* cmdQueue = nullptr, ID3D12CommandList* cmdList = nullptr);
			void SetCommandAllocator(ID3D12CommandAllocator* cmdAllocator);
			void SetCommandList(ID3D12CommandList* cmdList);
			void SetGraphicsCommandList(ID3D12GraphicsCommandList* graphicsCmdList);
			void SetCommandQueue(ID3D12CommandQueue* cmdQueue);

			ID3D12CommandAllocator* GetCommandAllocator(void)const;
			ID3D12CommandList* GetCommandList(void)const;
			ID3D12GraphicsCommandList* GetGraphicsCommandList(void)const;
			ID3D12CommandQueue* GetCommandQueue(void)const;

		private:
			SingletonDX12CommandObject(){}
			~SingletonDX12CommandObject() {}

			static SingletonDX12CommandObject* instance;

			ID3D12CommandAllocator* _cmdAllocator;
			ID3D12CommandList* _cmdList;
			ID3D12GraphicsCommandList* _graphicsCmdList;
			ID3D12CommandQueue* _cmdQueue;

		};
	}
}

#endif // DX12_SINGLETON_COMMAND_OBJECT_H_