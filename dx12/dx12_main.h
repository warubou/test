#pragma once
#ifndef DX12_MAIN_H_
#define DX12_MAIN_H_

#include "dx12_header.h"
#include "dx12_resourceBuffer.h"
#include "dx12_device.h"
#include "dx12_swapChain.h"
#include "dx12_commandAllocator.h"
#include "dx12_commandList.h"
#include "dx12_commandQueue.h"
#include "dx12_fence.h"
#include "dx12_defaultRTV.h"
#include "dx12_inputLayout.h"
#include "dx12_shader.h"
#include "dx12_graphicsPipeline.h"
#include "dx12_rootSignature.h"
#include "dx12_viewPort.h"
#include "dx12_scissorRect.h"
#include "dx12_vertexBuffer.h"
#include "dx12_indexBuffer.h"

namespace ko
{
	namespace dx12
	{
		class DX12Main
		{
		public:
			DX12Main();
			~DX12Main();

			HRESULT MainInitialize(HWND* hWnd,const UINT& width,const UINT& height);
			void InitializeRendereTest(void);
			void BeginDraw(void);
			void EndDraw(void);

		private:
			DX12Device _device;
			SwapChain _swapChain;
			CommandAllocator _cmdAllocator;
			CommandList _cmdList;
			CommandQueue _cmdQueue;
			Fence _fence;
			RTV _rtv;
			ViewPort _viewPort;
			ScissorRect _scissorRect;
			InputLayout _inputLayout;
			Shader _shader;
			GraphicsPipeline _gpipeline;
			RootSignature _rootSignature;
			VertexBuffer _vertexBuffer;
			IndexBuffer _indexBuffer;

			const size_t _VERTEX_NUM = 4;
			UINT bbIdx = 0;
		};
	}
}

#endif // DX12_MAIN_H_