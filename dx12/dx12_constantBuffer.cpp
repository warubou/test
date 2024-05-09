#include "dx12_constantBuffer.h"
#include "dx12_device.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		HRESULT ConstantBuffer::Create(size_t size, UINT baseShaderRagister)
		{
			_descRange = HELPER_D3D12_DESCRIPTOR_RANGE(_CBV, baseShaderRagister);
			return ResourceBuffer::Create(_CONSTANT_HEAP, (size + 0xff) & ~0xff);
		}

		const D3D12_DESCRIPTOR_RANGE& ConstantBuffer::GetDescriptorRange(void)
		{
			return _descRange;
		}

		const D3D12_ROOT_PARAMETER& ConstantBuffer::GetRootParameter(void)
		{
			return HELPER_D3D12_ROOT_PARAMETER(_VS, &_descRange, 1);
		}

		void ConstantBuffer::CreateCBV(D3D12_CPU_DESCRIPTOR_HANDLE descHandle)
		{
			D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
			cbvDesc.BufferLocation = _resource->GetGPUVirtualAddress();
			cbvDesc.SizeInBytes = _resource->GetDesc().Width;

			DX12Device::getInstance().Get()->CreateConstantBufferView(&cbvDesc, descHandle);
		}
	}
}