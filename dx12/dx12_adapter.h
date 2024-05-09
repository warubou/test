#pragma once
#ifndef DX12_ADAPTER_H_
#define DX12_ADAPTER_H_

#include "dx12_header.h"
#include <string>

namespace ko
{
	namespace dx12
	{
		class Adapter
		{
		public:
			Adapter();
			~Adapter();

			// ==============================================
			// �A�_�v�^�[�̗�
			// ==============================================
			HRESULT EnumeratingAdapters(const std::wstring& enumeratingGPU);

			// ==============================================
			// �A�_�v�^�[�̎擾
			// ==============================================
			IDXGIAdapter* Get(void)const;

			// ==============================================
			// �A�_�v�^�[�̃|�C���^�[�̎擾
			// ==============================================
			IDXGIAdapter** GetPointer(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);

		private:
			IDXGIAdapter* _adapter = nullptr;
		};
	}
}

#endif // DX12_ADAOTER_H_