#pragma once
#ifndef	DX12_DXGI_FACTORY_H_
#define DX12_DXGI_FACTORY_H_

#include "singleton.h"
#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class DxgiFactory : public Singleton<DxgiFactory>
		{
		public:
			// ==============================================
			// �f�X�g���N�^
			// ==============================================
			~DxgiFactory();

			// ==============================================
			// IDXGIFaxtory6*�̎擾
			// ==============================================
			static IDXGIFactory6* Get(void);

			// ==============================================
			// IDXGIFactory6**�̎擾
			// ==============================================
			static IDXGIFactory6** GetPointer(void);

			// ==============================================
			// ���
			// ==============================================
			void Release(void);
			
		private:
			// �O���Q�Ɛ���
			// DxgiFactory() {}
			// DxgiFactory(const DxgiFactory& other) {}
			// DxgiFactory& operator=(const DxgiFactory& other) {}

			static IDXGIFactory6* _dxgiFactory;
		};
	}
}

#endif // DX12_DXGI_FACTORY