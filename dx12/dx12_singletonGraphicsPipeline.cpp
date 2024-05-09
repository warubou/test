#include "dx12_singletonGraphicsPipeline.h"
#include "dx12_device.h"
#include "dx12_header.h"
#include "dx12_helperStruct.h"
#include "dx12_shader.h"
#include "dx12_rootSignature.h"

namespace ko
{
	namespace dx12
	{
		SingletonGraphicsPipeline* SingletonGraphicsPipeline::instance = nullptr;

		HRESULT SingletonGraphicsPipeline::Init(void)
		{

		}

		SingletonGraphicsPipeline* SingletonGraphicsPipeline::getInstance(void)
		{
			if (!instance)
				instance = new SingletonGraphicsPipeline();

			return instance;
		}

		void SingletonGraphicsPipeline::Add(USES_PIPELINE_TYPE type, ID3D12PipelineState* pipelineState)
		{			
			_pipelineStatus[type] = pipelineState;
		}

		ID3D12PipelineState* SingletonGraphicsPipeline::Get(USES_PIPELINE_TYPE type)
		{
			return _pipelineStatus[type];
		}

		void SingletonGraphicsPipeline::createSprite2D(void)
		{
			ID3D12PipelineState* pipelineState = nullptr;
			D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc = {};
			Shader* shader = new Shader();
			RootSignature* rootSignature = new RootSignature();

			D3D12_INPUT_ELEMENT_DESC il[] =
			{
				{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
				{"TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
			};

			HRESULT hr = shader->CompileShader(L"../shader/vshader.hlsl", "VSMain", "vs_5_0",
				L"../shader/pshader.hlsl", "PSMain", "ps_5_0");
			hr = shader->CompileGeometryShader(L"../shader/gshader.hlsl");

			// ディスクリプタレンジの設定
			D3D12_DESCRIPTOR_RANGE* dRange = new D3D12_DESCRIPTOR_RANGE[2];
			dRange[0] = HELPER_D3D12_DESCRIPTOR_RANGE(_SRV);
			dRange[1] = HELPER_D3D12_DESCRIPTOR_RANGE(_CBV);

			// ルートパラメータの設定
			D3D12_ROOT_PARAMETER* rootParam = new D3D12_ROOT_PARAMETER[2];
			
				rootParam[0] = HELPER_D3D12_ROOT_PARAMETER(_PS, &dRange[0], 1);
				rootParam[1] = HELPER_D3D12_ROOT_PARAMETER(_GS, &dRange[1], 1);

			hr = rootSignature->Create(dRange, rootParam, 2);

			delete[]dRange;
			delete[]rootParam;

			pipelineDesc.BlendState = HELPER_D3D12_BLEND_DESC(_MODE_ALFABLEND);
			pipelineDesc.RasterizerState.AntialiasedLineEnable = static_cast<BOOL>(false);
			pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
			pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
			pipelineDesc.RasterizerState.DepthClipEnable = true;
			pipelineDesc.RasterizerState.FrontCounterClockwise = true;
			pipelineDesc.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
			pipelineDesc.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
			pipelineDesc.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
			pipelineDesc.RasterizerState.AntialiasedLineEnable = false;
			pipelineDesc.RasterizerState.ForcedSampleCount = 0;
			pipelineDesc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
			pipelineDesc.DepthStencilState.DepthEnable = false;
			pipelineDesc.DepthStencilState.StencilEnable = false;
			pipelineDesc.SampleDesc.Count = 1;
			pipelineDesc.SampleDesc.Quality = 0;
			pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK;
			pipelineDesc.NumRenderTargets = 1;
			pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
			pipelineDesc.IBStripCutValue = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
			pipelineDesc.InputLayout.pInputElementDescs = il;
			pipelineDesc.InputLayout.NumElements = _countof(il);
			pipelineDesc.VS.pShaderBytecode = shader->GetVSBlob()->GetBufferPointer();
			pipelineDesc.VS.BytecodeLength = shader->GetVSBlob()->GetBufferSize();
			pipelineDesc.PS.pShaderBytecode = shader->GetPSBlob()->GetBufferPointer();
			pipelineDesc.PS.BytecodeLength = shader->GetPSBlob()->GetBufferSize();
			pipelineDesc.GS.pShaderBytecode = shader->GetGSBlob()->GetBufferPointer();
			pipelineDesc.GS.BytecodeLength = shader->GetGSBlob()->GetBufferSize();
			pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT;
			pipelineDesc.pRootSignature = rootSignature->Get();

			HRESULT hr = DX12Device::getInstance().Get()->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&_pipelineStatus[_SPRITE2D]));
		}

		void SingletonGraphicsPipeline::createSprite3D(void)
		{

		}

		void SingletonGraphicsPipeline::createModel(void)
		{

		}

	}
}