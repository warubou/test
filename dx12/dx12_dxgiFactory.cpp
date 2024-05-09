#include "dx12_dxgiFactory.h"

namespace ko
{
	namespace dx12
	{
		static DxgiFactory& singleton = DxgiFactory::getInstance();
		IDXGIFactory6* DxgiFactory::_dxgiFactory = nullptr;

		// ==============================================
		// デストラクタ
		// ==============================================
		DxgiFactory::~DxgiFactory() {}

		// ==============================================
		// IDXGIFaxtory6*の取得
		// ==============================================
		IDXGIFactory6* DxgiFactory::Get(void)
		{
			return _dxgiFactory;
		}

		// ==============================================
		// IDXGIFactory6**の取得
		// ==============================================
		IDXGIFactory6** DxgiFactory::GetPointer(void)
		{
			return &_dxgiFactory;
		}

		// ==============================================
		// 解放
		// ==============================================
		void DxgiFactory::Release(void)
		{
			if (_dxgiFactory)_dxgiFactory->Release();
		}
	}
}