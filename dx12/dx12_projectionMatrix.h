#pragma once
#ifndef DX12_PROJECTION_MATRIX_H_
#define DX12_PROJECTION_MATRIX_H_

#include <DirectXMath.h>
#include "dx12_header.h"
#include "dx12_WVP.h"
#include "../vector/vector.h"

namespace ko
{
	namespace dx12
	{
		class ProjectionMatrix : public WVP
		{
		public:

			static ProjectionMatrix* getInstance(void);

			void Update(void);
			void Set(bool isPerspective);

			void Release(void)override {}

		private:
			ProjectionMatrix() {}
			~ProjectionMatrix(){}

			static ProjectionMatrix* instance;

			DirectX::XMMATRIX _projectionMtx;
			bool _isPerspective = false;
			const float _VIEW_NEAR_Z = 1.0f;
			const float _VIEW_FAR_Z = 10000.0f;
		};
	}
}

#endif // DX12_PROJECTION_MATRIX_H_