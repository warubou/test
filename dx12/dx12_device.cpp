#include "dx12_device.h"
//#include "dx12_featureLevel.h"

namespace ko
{
	namespace dx12
	{
		//�t�B�[�`�����x����
		D3D_FEATURE_LEVEL levels[] = {
			D3D_FEATURE_LEVEL_12_1,
			D3D_FEATURE_LEVEL_12_0,
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0,
		};

		static DX12Device& singleton = DX12Device::getInstance();
		ID3D12Device* DX12Device::_device = nullptr;

		// ==============================================
		// �f�o�C�X�̍쐬
		// ==============================================
		HRESULT DX12Device::Create(void)
		{
			_pAdapter = new Adapter;
			_pAdapter->EnumeratingAdapters(L"NVIDIA");

			//Direct3D�f�o�C�X�̏�����
			D3D_FEATURE_LEVEL featureLevel;
			for (auto l : levels) {
				if (D3D12CreateDevice(_pAdapter->Get(), l, IID_PPV_ARGS(&_device)) == S_OK) {
					featureLevel = l;
					return S_OK;
				}
			}

			// ���s��
			_pAdapter->Release();
			delete _pAdapter;
			_pAdapter = nullptr;
			return S_FALSE;
		}

		// ==============================================
		// �f�o�C�X�̎擾
		// ==============================================
		ID3D12Device* DX12Device::Get(void)
		{
			return _device;
		}

		// ==============================================
		// �f�o�C�X�̉��
		// ==============================================
		void DX12Device::Release(void)
		{
			if (_pAdapter)
			{
				_pAdapter->Release();
				delete _pAdapter;
				_pAdapter = nullptr;
			}

			_device->Release();
			_device = nullptr;
		}
	}
}