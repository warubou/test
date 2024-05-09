#pragma once
#ifndef DX12_WVP_H_
#define DX12_WVP_H_

#include <DirectXMath.h>
#include "dx12_header.h"
#include "dx12_device.h"
#include "dx12_constantBuffer.h"

namespace ko
{
	namespace dx12
	{
		class WVP
		{
		public:
			HRESULT Init(UINT settingBaseShaderRegister);

			const D3D12_DESCRIPTOR_RANGE& GetDescriptorRange(void);
			const D3D12_ROOT_PARAMETER& GetRootParameter(void);

			void CreateCBV(const D3D12_CPU_DESCRIPTOR_HANDLE& descHandle);

			virtual void Release(void) = 0;
		protected:
			ConstantBuffer* _pConstantBuffer;
		};
	}
}

#endif // DX12_WVP_H_