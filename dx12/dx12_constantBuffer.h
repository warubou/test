#pragma once
#ifndef DX12_CONSTANT_BUFFER_H_
#define DX12_CONSTANT_BUFFER_H_

#include "dx12_header.h"
#include "dx12_resourceBuffer.h"

namespace ko
{
	namespace dx12
	{
		class ConstantBuffer : public ResourceBuffer
		{
		public:
			ConstantBuffer() {}
			ConstantBuffer(size_t size, UINT baseShaderRagister = 0U) { Create(size, baseShaderRagister); }
			~ConstantBuffer() {}

			HRESULT Create(size_t size, UINT baseShaderRagister = 0U);
			const D3D12_DESCRIPTOR_RANGE& GetDescriptorRange(void);
			const D3D12_ROOT_PARAMETER& GetRootParameter(void);
			void CreateCBV(D3D12_CPU_DESCRIPTOR_HANDLE descHandle);
		private:
			D3D12_DESCRIPTOR_RANGE _descRange;
		};
	}
}

#endif // DX12_CONSTANT_BUFFER_H_