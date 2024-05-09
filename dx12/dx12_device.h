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
			// デストラクタ
			// ==============================================
			~DX12Device() {}

			// ==============================================
			// デバイスの作成
			// ==============================================
			HRESULT Create(void);

			// ==============================================
			// デバイスの取得
			// ==============================================
			ID3D12Device* Get(void);

			// ==============================================
			// デバイスの解放
			// ==============================================
			void Release(void);

		private:
			// 外部参照制限
			// DX12Device() {}
			// DX12Device(const DX12Device& other) {}
			// DX12Device& operator=(const DX12Device& other) {}

			static ID3D12Device* _device;
			Adapter* _pAdapter = nullptr;
		};
	}
}

#endif // DX12_DEVICE_H_