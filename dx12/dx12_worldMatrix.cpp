#include "dx12_worldMatrix.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		WorldMatrix* WorldMatrix::instance = nullptr;

		WorldMatrix* WorldMatrix::getInstance(void)
		{
			if (!instance)
				instance = new WorldMatrix();

			return instance;
		}

		void WorldMatrix::Update(const Vector3& pos, const Vector3& scale, const Vector3 rotate)
		{
			DirectX::XMMATRIX scaleMtx;
			DirectX::XMMATRIX rotateMtx;
			DirectX::XMMATRIX translateMtx;

			_worldMtx = DirectX::XMMatrixIdentity();				// ’PˆÊs—ñ‚ðì‚éŠÖ”
			scaleMtx = DirectX::XMMatrixScaling(scale._x, scale._y, scale._z);
			// s—ñ‚ÌŠ|‚¯ŽZ‚ð‚·‚é	ˆø”1 = ˆø”2 * ˆø”3
			_worldMtx = DirectX::XMMatrixMultiply(_worldMtx, scaleMtx);
			// ‰ñ“]‚ð”½‰f
			rotateMtx = DirectX::XMMatrixRotationRollPitchYaw(rotate._x, rotate._y, rotate._z);
			_worldMtx = DirectX::XMMatrixMultiply(_worldMtx, rotateMtx);
			// ˆÚ“®‚ð”½‰f
			translateMtx = DirectX::XMMatrixTranslation(pos._x, pos._y, pos._z);
			_worldMtx = DirectX::XMMatrixMultiply(_worldMtx, translateMtx);

			DirectX::XMMATRIX* mat = nullptr;
			_pConstantBuffer->GetResource()->Map(0, nullptr, (void**)mat);
			mat = &_worldMtx;
			_pConstantBuffer->GetResource()->Unmap(0, nullptr);
		}

		void WorldMatrix::Update(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& scale, const DirectX::XMFLOAT3& rotate)
		{
			Vector3 Pos = Vector3(pos);
			Vector3 Scale = Vector3(scale);
			Vector3 Rotate = Vector3(rotate);
			Update(Pos, Scale, Rotate);
		}

		void WorldMatrix::Update(const DirectX::XMVECTOR& pos, const DirectX::XMVECTOR& scale, const DirectX::XMVECTOR& rotate)
		{
			Vector3 Pos = Vector3(pos);
			Vector3 Scale = Vector3(scale);
			Vector3 Rotate = Vector3(rotate);
			Update(Pos, Scale, Rotate);
		}
	}
}