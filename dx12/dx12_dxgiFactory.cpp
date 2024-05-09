#include "dx12_dxgiFactory.h"

namespace ko
{
	namespace dx12
	{
		static DxgiFactory& singleton = DxgiFactory::getInstance();
		IDXGIFactory6* DxgiFactory::_dxgiFactory = nullptr;

		// ==============================================
		// �f�X�g���N�^
		// ==============================================
		DxgiFactory::~DxgiFactory() {}

		// ==============================================
		// IDXGIFaxtory6*�̎擾
		// ==============================================
		IDXGIFactory6* DxgiFactory::Get(void)
		{
			return _dxgiFactory;
		}

		// ==============================================
		// IDXGIFactory6**�̎擾
		// ==============================================
		IDXGIFactory6** DxgiFactory::GetPointer(void)
		{
			return &_dxgiFactory;
		}

		// ==============================================
		// ���
		// ==============================================
		void DxgiFactory::Release(void)
		{
			if (_dxgiFactory)_dxgiFactory->Release();
		}
	}
}