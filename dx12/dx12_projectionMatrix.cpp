#include "dx12_projectionMatrix.h"

namespace ko
{
	namespace dx12
	{
		ProjectionMatrix* ProjectionMatrix::instance = nullptr;

		ProjectionMatrix* ProjectionMatrix::getInstance(void)
		{
			if (!instance)
				instance = new ProjectionMatrix;

			return instance;
		}

		void ProjectionMatrix::Update(void)
		{
			if (_isPerspective)
				_projectionMtx = DirectX::XMMatrixPerspectiveFovLH(1.0f, SCREEN_WIDTH / SCREEN_HEIGHT, _VIEW_NEAR_Z, _VIEW_FAR_Z);
			else
				_projectionMtx = DirectX::XMMatrixOrthographicOffCenterLH(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -2.0f, _VIEW_FAR_Z);
			
			DirectX::XMMATRIX* mat = nullptr;
			_pConstantBuffer->GetResource()->Map(0, nullptr, (void**)mat);
			mat = &_projectionMtx;
			_pConstantBuffer->GetResource()->Unmap(0, nullptr);
		}

		void ProjectionMatrix::Set(bool isPerspective)
		{
			_isPerspective = isPerspective;
		}
	}
}