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
			// アダプターの列挙
			// ==============================================
			HRESULT EnumeratingAdapters(const std::wstring& enumeratingGPU);

			// ==============================================
			// アダプターの取得
			// ==============================================
			IDXGIAdapter* Get(void)const;

			// ==============================================
			// アダプターのポインターの取得
			// ==============================================
			IDXGIAdapter** GetPointer(void);

			// ==============================================
			// 解放
			// ==============================================
			void Release(void);

		private:
			IDXGIAdapter* _adapter = nullptr;
		};
	}
}

#endif // DX12_ADAOTER_H_