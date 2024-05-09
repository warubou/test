#include "dx12_adapter.h"
#include "dx12_dxgiFactory.h"

#include <vector>

namespace ko
{
	namespace dx12
	{
		Adapter::Adapter(){}
		Adapter::~Adapter() {}

		// ==============================================
		// アダプターの列挙
		// ==============================================
		HRESULT Adapter::EnumeratingAdapters(const std::wstring& enumeratingGPU)
		{
			if (FAILED(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(DxgiFactory::getInstance().GetPointer())))) {
				if (FAILED(CreateDXGIFactory2(0, IID_PPV_ARGS(DxgiFactory::getInstance().GetPointer())))) {
					return S_FALSE;
				}
			}

			// アダプターの列挙
			std::vector <IDXGIAdapter*> adapters;
			for (int i = 0; DxgiFactory::getInstance().Get()->EnumAdapters(i, &_adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
				adapters.push_back(_adapter);
			}

			// アダプターに引数の名前があるか走査
			for (auto adpt : adapters) {
				DXGI_ADAPTER_DESC adesc = {};
				adpt->GetDesc(&adesc);
				std::wstring strDesc = adesc.Description;
				if (strDesc.find(enumeratingGPU) != std::string::npos) {
					_adapter = adpt;
					break;
				}
			}

			return S_OK;
		}

		// ==============================================
		// アダプターの取得
		// ==============================================
		IDXGIAdapter* Adapter::Get(void)const
		{
			return _adapter;
		}

		// ==============================================
		// アダプターのポインターの取得
		// ==============================================
		IDXGIAdapter** Adapter::GetPointer(void)
		{
			return &_adapter;
		}

		// ==============================================
		// 解放
		// ==============================================
		void Adapter::Release(void)
		{
			if (_adapter)_adapter->Release();
		}
	}
}