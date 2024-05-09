#include "dx12_viewMatrix.h"

namespace ko
{
	namespace dx12
	{
		ViewMatrix* ViewMatrix::instance = nullptr;

		ViewMatrix* ViewMatrix::getInstance(void)
		{
			if (!instance)
				instance = new ViewMatrix;

			return instance;
		}

		void ViewMatrix::Update(void)
		{
			_viewMtx = DirectX::XMMatrixLookAtLH(_camera._pos, _camera._at, _camera._up);
			_invViewMtx = DirectX::XMMatrixInverse(nullptr, _viewMtx);

			DirectX::XMMATRIX* mat = nullptr;
			_pConstantBuffer->GetResource()->Map(0, nullptr, (void**)mat);
			_pConstantBuffer->GetResource()->Unmap(0, nullptr);
		}

		void ViewMatrix::Set(const Camera& camera)
		{
			_camera = camera;
		}
	}
}