#pragma once
#ifndef DX12_WORLD_MATRIX_H_
#define DX12_WORLD_MATRIX_H_

#include <DirectXMath.h>
#include "dx12_header.h"
#include "dx12_WVP.h"
#include "../vector/vector.h"

namespace ko
{
	namespace dx12
	{
		class WorldMatrix : public WVP
		{
		public:

			static WorldMatrix* getInstance(void);

			void Update(const Vector3& pos, const Vector3& scale, const Vector3 rotate);
			void Update(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& scale, const DirectX::XMFLOAT3& rotate);
			void Update(const DirectX::XMVECTOR& pos, const DirectX::XMVECTOR& scale, const DirectX::XMVECTOR& rotate);

			void Release(void)override {}

		private:
			WorldMatrix() {}
			~WorldMatrix() {}

			static WorldMatrix* instance;

			DirectX::XMMATRIX _worldMtx;
		};
	}
}

#endif // DX12_WORLD_MATRIX_H_