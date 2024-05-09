#include "dx12_WVP.h"

namespace ko
{
	namespace dx12
	{
		HRESULT WVP::Init(UINT settingBaseShaderRegister)
		{
			_pConstantBuffer = new ConstantBuffer;
			return _pConstantBuffer->Create(sizeof(DirectX::XMMATRIX), settingBaseShaderRegister);
		}

		const D3D12_DESCRIPTOR_RANGE& WVP::GetDescriptorRange(void)
		{
			return _pConstantBuffer->GetDescriptorRange();
		}

		const D3D12_ROOT_PARAMETER& WVP::GetRootParameter(void)
		{
			return _pConstantBuffer->GetRootParameter();
		}

		void WVP::CreateCBV(const D3D12_CPU_DESCRIPTOR_HANDLE& descHandle)
		{
			_pConstantBuffer->CreateCBV(descHandle);
		}
	}
}