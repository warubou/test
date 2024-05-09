#include "dx12_rootSignature.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		RootSignature::RootSignature() {}
		RootSignature::~RootSignature() {}

		HRESULT RootSignature::Create(void)
		{
			D3D12_STATIC_SAMPLER_DESC samplerDesc = {};
			samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;	// ボーダーは黒
			samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;				// 補完しない
			samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;								// ミップマップ最大値
			samplerDesc.MinLOD = 0.0f;											// ミップマップ最小値
			samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;		// ピクセルシェーダーから見える
			samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;			// リサンプリングしない

			D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
			rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

			ID3DBlob* rootSigBlob = nullptr;
			ID3DBlob* errorBlob = nullptr;

			HRESULT hr = D3D12SerializeRootSignature(
				&rootSignatureDesc,
				D3D_ROOT_SIGNATURE_VERSION_1_0,
				&rootSigBlob,
				&errorBlob
			);
			ERROR_CHECK_HRESULT(hr);

			hr = DX12Device::getInstance().Get()->CreateRootSignature(0,
				rootSigBlob->GetBufferPointer(),
				rootSigBlob->GetBufferSize(),
				IID_PPV_ARGS(&_rootSignature)
			);
			ERROR_CHECK_HRESULT(hr);

			if (rootSigBlob)
				rootSigBlob->Release();
			if (errorBlob)
				errorBlob->Release();

			return hr;
		}

		HRESULT RootSignature::Create(D3D12_DESCRIPTOR_RANGE* arrayRange, D3D12_ROOT_PARAMETER* arrayParam, size_t arraySize)
		{
			D3D12_DESCRIPTOR_RANGE* pDRange = new D3D12_DESCRIPTOR_RANGE[arraySize];
			D3D12_ROOT_PARAMETER* pRootParam = new D3D12_ROOT_PARAMETER[arraySize];

			for (int i = 0; i < arraySize; i++)
			{				
				pDRange[i] = arrayRange[i];
				pRootParam[i] = arrayParam[i];
			}

			D3D12_STATIC_SAMPLER_DESC samplerDesc = {};
			samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;				// 端から折り返し
			samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;	// ボーダーは黒
			samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;				// リニア補完
			samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;								// ミップマップ最大値
			samplerDesc.MinLOD = 0.0f;											// ミップマップ最小値
			samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;		// ピクセルシェーダーから見える
			samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;			// リサンプリングしない

			D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
			rootSignatureDesc.pParameters = pRootParam;
			rootSignatureDesc.NumParameters = arraySize;
			rootSignatureDesc.pStaticSamplers = &samplerDesc;
			rootSignatureDesc.NumStaticSamplers = 1;
			rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

			ID3DBlob* rootSigBlob = nullptr;
			ID3DBlob* errorBlob;

			HRESULT hr = D3D12SerializeRootSignature(
				&rootSignatureDesc,
				D3D_ROOT_SIGNATURE_VERSION_1_0,
				&rootSigBlob,
				&errorBlob
			);
			ERROR_CHECK_HRESULT(hr);

			hr = DX12Device::getInstance().Get()->CreateRootSignature(0,
				rootSigBlob->GetBufferPointer(),
				rootSigBlob->GetBufferSize(),
				IID_PPV_ARGS(&_rootSignature)
			);
			ERROR_CHECK_HRESULT(hr);

			if (rootSigBlob)
				rootSigBlob->Release();
			if (errorBlob)
				errorBlob->Release();

			delete[] pDRange;
			delete[] pRootParam;
			return hr;
		}

		ID3D12RootSignature* RootSignature::Get(void)const
		{
			return _rootSignature;
		}
	}
}