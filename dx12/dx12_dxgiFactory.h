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
			// デストラクタ
			// ==============================================
			~DxgiFactory();

			// ==============================================
			// IDXGIFaxtory6*の取得
			// ==============================================
			static IDXGIFactory6* Get(void);

			// ==============================================
			// IDXGIFactory6**の取得
			// ==============================================
			static IDXGIFactory6** GetPointer(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);
			
		private:
			// 外部参照制限
			// DxgiFactory() {}
			// DxgiFactory(const DxgiFactory& other) {}
			// DxgiFactory& operator=(const DxgiFactory& other) {}

			static IDXGIFactory6* _dxgiFactory;
		};
	}
}

#endif // DX12_DXGI_FACTORY