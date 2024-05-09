#pragma once
#ifndef DX12_GRAPHICS_PIPELINE_H_
#define DX12_GRAPHICS_PIPELINE_H_

#include "dx12_header.h"
#include <d3dcompiler.h>

namespace ko
{
	namespace dx12
	{
		class GraphicsPipeline
		{
		public:
			GraphicsPipeline();
			~GraphicsPipeline();

			HRESULT Create();

			// デフォルトでセット
			void SetDefaultAll(ID3DBlob* vs, ID3DBlob* ps, D3D12_INPUT_ELEMENT_DESC* inputLayout, const UINT& arraySize, ID3D12RootSignature* rootSignature);
			void SetShader(ID3DBlob* vs, ID3DBlob* ps);
			void SetShader(const char* vsBufferFirstPointer, const char* psBufferFirstPointer, size_t vsBufferSize, size_t psBufferSize);
			void SetGeometryShader(ID3DBlob* gs);
			void SetGeometryShader(const char* gsBufferFirstPointer, size_t gsBufferSize);
			void SetSamplerState(const UINT& samplerMask);
			void SetRaeterizerState(bool enableAntiAliasing,const D3D12_CULL_MODE& cullMode,const D3D12_FILL_MODE& fillMode);
			void SetDepthStencil(bool depthEnable, bool stencilEnable);
			void SetBlendState(const D3D12_BLEND_DESC& bDesc);
			void SetInputLayout(D3D12_INPUT_ELEMENT_DESC* inputLayout,const UINT& arraySize);
			void SetIBStripCutValue(const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE& value);
			void SetPrimitiveTopology(const D3D12_PRIMITIVE_TOPOLOGY_TYPE& primitveType);
			void SetOneRendereTarget(void);		// まぁまぁRTVの数に依存するため可変の可能性あり
			void SetRootSignature(ID3D12RootSignature* rootSignature);

			ID3D12PipelineState* Get(void)const;

		private:
			D3D12_GRAPHICS_PIPELINE_STATE_DESC _gpipeline = {};
			ID3D12PipelineState* _pipelineState = nullptr;
		};
	}
}

#endif // DX12_GRAPHICS_PIPELINE_H_