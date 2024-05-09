#pragma once
#ifndef DX12_ROOT_SIGNATURE_H_
#define DX12_ROOT_SIGNATURE_H_

#include "dx12_header.h"
#include "dx12_texture.h"

namespace ko
{
	namespace dx12
	{
		class RootSignature
		{
		public:
			RootSignature();
			~RootSignature();

			HRESULT Create(void);
			HRESULT Create(D3D12_DESCRIPTOR_RANGE* arrayRange, D3D12_ROOT_PARAMETER* arrayParam, size_t arraySize);
			ID3D12RootSignature* Get(void)const;

		private:
			ID3D12RootSignature* _rootSignature = nullptr;
			Texture _texture;
		};
	}
}

#endif // DX12_ROOT_SIGNATURE_H_