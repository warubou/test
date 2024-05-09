#include "dx12_graphicsPipeline.h"
#include "dx12_device.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		GraphicsPipeline::GraphicsPipeline() {}
		GraphicsPipeline::~GraphicsPipeline() {}

		HRESULT GraphicsPipeline::Create()
		{
			return DX12Device::getInstance().Get()->CreateGraphicsPipelineState(&_gpipeline, IID_PPV_ARGS(&_pipelineState));
		}

		void GraphicsPipeline::SetDefaultAll(ID3DBlob* vs, ID3DBlob* ps, D3D12_INPUT_ELEMENT_DESC* inputLayout, const UINT& arraySize, ID3D12RootSignature* rootSignature)
		{
			SetBlendState(HELPER_D3D12_BLEND_DESC(_MODE_ALFABLEND));
			SetRaeterizerState(false, D3D12_CULL_MODE_NONE, D3D12_FILL_MODE_SOLID);
			SetDepthStencil(false, false);
			SetSamplerState(D3D12_DEFAULT_SAMPLE_MASK);
			SetOneRendereTarget();
			SetIBStripCutValue(D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED);
			SetInputLayout(inputLayout, arraySize);
			SetShader(vs, ps);
			SetPrimitiveTopology(D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE);
			SetRootSignature(rootSignature);
		}

		void GraphicsPipeline::SetShader(ID3DBlob* vs, ID3DBlob* ps)
		{
			_gpipeline.VS.pShaderBytecode = vs->GetBufferPointer();
			_gpipeline.VS.BytecodeLength = vs->GetBufferSize();
			_gpipeline.PS.pShaderBytecode = ps->GetBufferPointer();
			_gpipeline.PS.BytecodeLength = ps->GetBufferSize();
		}

		void GraphicsPipeline::SetShader(const char* vsBufferFirstPointer, const char* psBufferFirstPointer, size_t vsBufferSize, size_t psBufferSize)
		{
			_gpipeline.VS.pShaderBytecode = vsBufferFirstPointer;
			_gpipeline.VS.BytecodeLength = vsBufferSize;
			_gpipeline.PS.pShaderBytecode = psBufferFirstPointer;
			_gpipeline.PS.BytecodeLength = psBufferSize;
		}

		void GraphicsPipeline::SetGeometryShader(ID3DBlob* gs)
		{
			_gpipeline.GS.pShaderBytecode = gs->GetBufferPointer();
			_gpipeline.GS.BytecodeLength = gs->GetBufferSize();
		}

		void GraphicsPipeline::SetGeometryShader(const char* gsBufferFirstPointer, size_t gsBufferSize)
		{
			_gpipeline.GS.pShaderBytecode = gsBufferFirstPointer;
			_gpipeline.GS.BytecodeLength = gsBufferSize;
		}

		void GraphicsPipeline::SetSamplerState(const UINT& samplerMask)
		{
			_gpipeline.SampleDesc.Count = 1;
			_gpipeline.SampleDesc.Quality = 0;
			_gpipeline.SampleMask = samplerMask;
		}

		void GraphicsPipeline::SetRaeterizerState(bool enableAntiAliasing,const D3D12_CULL_MODE& cullMode,const D3D12_FILL_MODE& fillMode)
		{
			_gpipeline.RasterizerState.AntialiasedLineEnable = static_cast<BOOL>(enableAntiAliasing);
			_gpipeline.RasterizerState.CullMode = cullMode;
			_gpipeline.RasterizerState.FillMode = fillMode;
			_gpipeline.RasterizerState.DepthClipEnable = true;

			_gpipeline.RasterizerState.FrontCounterClockwise = true;
			_gpipeline.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
			_gpipeline.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
			_gpipeline.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
			_gpipeline.RasterizerState.AntialiasedLineEnable = false;
			_gpipeline.RasterizerState.ForcedSampleCount = 0;
			_gpipeline.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
		}

		void GraphicsPipeline::SetDepthStencil(bool depthEnable, bool stencilEnable)
		{
			_gpipeline.DepthStencilState.DepthEnable = depthEnable;
			_gpipeline.DepthStencilState.StencilEnable = stencilEnable;
		}

		void GraphicsPipeline::SetBlendState(const D3D12_BLEND_DESC& bDesc)
		{
			_gpipeline.BlendState = bDesc;
		}

		void GraphicsPipeline::SetInputLayout(D3D12_INPUT_ELEMENT_DESC* inputLayout,const UINT& arraySize)
		{
			_gpipeline.InputLayout.pInputElementDescs = inputLayout;
			_gpipeline.InputLayout.NumElements = arraySize;
		}

		void GraphicsPipeline::SetIBStripCutValue(const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE& value)
		{
			_gpipeline.IBStripCutValue = value;
		}

		void GraphicsPipeline::SetPrimitiveTopology(const D3D12_PRIMITIVE_TOPOLOGY_TYPE& primitveType)
		{ 
			_gpipeline.PrimitiveTopologyType = primitveType;
		}

		void GraphicsPipeline::SetOneRendereTarget(void)
		{
			_gpipeline.NumRenderTargets = 1;
			_gpipeline.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
		}

		void GraphicsPipeline::SetRootSignature(ID3D12RootSignature* rootSignature)
		{
			_gpipeline.pRootSignature = rootSignature;
		}

		ID3D12PipelineState* GraphicsPipeline::Get(void)const
		{
			return _pipelineState;
		}
	}
}