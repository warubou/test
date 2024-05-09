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
		// �A�_�v�^�[�̗�
		// ==============================================
		HRESULT Adapter::EnumeratingAdapters(const std::wstring& enumeratingGPU)
		{
			if (FAILED(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(DxgiFactory::getInstance().GetPointer())))) {
				if (FAILED(CreateDXGIFactory2(0, IID_PPV_ARGS(DxgiFactory::getInstance().GetPointer())))) {
					return S_FALSE;
				}
			}

			// �A�_�v�^�[�̗�
			std::vector <IDXGIAdapter*> adapters;
			for (int i = 0; DxgiFactory::getInstance().Get()->EnumAdapters(i, &_adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
				adapters.push_back(_adapter);
			}

			// �A�_�v�^�[�Ɉ����̖��O�����邩����
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
		// �A�_�v�^�[�̎擾
		// ==============================================
		IDXGIAdapter* Adapter::Get(void)const
		{
			return _adapter;
		}

		// ==============================================
		// �A�_�v�^�[�̃|�C���^�[�̎擾
		// ==============================================
		IDXGIAdapter** Adapter::GetPointer(void)
		{
			return &_adapter;
		}

		// ==============================================
		// ���
		// ==============================================
		void Adapter::Release(void)
		{
			if (_adapter)_adapter->Release();
		}
	}
}