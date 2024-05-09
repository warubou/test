#pragma once
#ifndef DX12_DEVICE_H_
#define DX12_DEVICE_H_

#include "singleton.h"
#include "dx12_header.h"
#include "dx12_adapter.h"

namespace ko
{
	namespace dx12
	{
		class DX12Device : public Singleton<DX12Device>
		{
		public:
			// ==============================================
			// �f�X�g���N�^
			// ==============================================
			~DX12Device() {}

			// ==============================================
			// �f�o�C�X�̍쐬
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// �f�o�C�X�̎擾
			// ==============================================
			ID3D12Device* Get(void);

			// ==============================================
			// �f�o�C�X�̉��
			// ==============================================
			void Release(void);

		private:
			// �O���Q�Ɛ���
			// DX12Device() {}
			// DX12Device(const DX12Device& other) {}
			// DX12Device& operator=(const DX12Device& other) {}

			static ID3D12Device* _device;
			Adapter* _pAdapter = nullptr;
		};
	}
}

#endif // DX12_DEVICE_H_