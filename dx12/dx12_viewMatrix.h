#pragma once
#ifndef DX12_VIEW_MATRIX_H_
#define DX12_VIEW_MATRIX_H_

#include <DirectXMath.h>
#include "dx12_header.h"
#include "dx12_WVP.h"
#include "../vector/vector.h"

namespace ko
{
	namespace dx12
	{
		class ViewMatrix : public WVP
		{
		public:
			struct Camera
			{
				DirectX::XMVECTOR	_pos;			// �J�����̎��_(�ʒu)
				DirectX::XMVECTOR	_prevPos;		// �J�����̑O�t���[�����_(�ʒu)
				DirectX::XMVECTOR	_at;			// �J�����̒����_
				DirectX::XMVECTOR	_prevAt;		// �J�����̑O�t���[�������_
				DirectX::XMVECTOR	_up;			// �J�����̏�����x�N�g��
				DirectX::XMVECTOR	_rot;			// �J�����̉�]
				float				_len;			// �J�����̎��_�ƒ����_�̋���

				// �S�v�f�̃R�s�[
				void Copy(const Camera& newCamera) {

					_pos = DirectX::XMVectorSet(newCamera._pos.m128_f32[0], newCamera._pos.m128_f32[1], newCamera._pos.m128_f32[2], newCamera._pos.m128_f32[3]);
					_at = DirectX::XMVectorSet(newCamera._at.m128_f32[0], newCamera._at.m128_f32[1], newCamera._at.m128_f32[2], newCamera._at.m128_f32[3]);
					_up = DirectX::XMVectorSet(newCamera._up.m128_f32[0], newCamera._up.m128_f32[1], newCamera._up.m128_f32[2], newCamera._up.m128_f32[3]);
					_rot = DirectX::XMVectorSet(newCamera._rot.m128_f32[0], newCamera._rot.m128_f32[1], newCamera._rot.m128_f32[2], newCamera._rot.m128_f32[3]);

					_len = newCamera._len;
				}
			};

			struct HELPER_CAMERA :public Camera {

				HELPER_CAMERA(const DirectX::XMVECTOR& pos, const DirectX::XMVECTOR& at)
				{
					_pos = pos;
					_prevPos = pos;
					_at = at;
					_prevAt = at;
					_up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
					_rot = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);

					// ���_�ƒ����_�̋������v�Z
					float vx, vz;
					vx = _pos.m128_f32[0] - _at.m128_f32[0];
					vz = _pos.m128_f32[2] - _at.m128_f32[2];
					_len = sqrtf(vx * vx + vz * vz);
				}

				HELPER_CAMERA() {
					_pos = DirectX::XMVectorSet(500.0f, 200.0f, -300.0f, 0.0f);
					_prevPos = DirectX::XMVectorSet(0.0f, 200.0f, -300.0f, 0.0f);
					_at = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
					_prevAt = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
					_up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
					_rot = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);

					// ���_�ƒ����_�̋������v�Z
					float vx, vz;
					vx = _pos.m128_f32[0] - _at.m128_f32[0];
					vz = _pos.m128_f32[2] - _at.m128_f32[2];
					_len = sqrtf(vx * vx + vz * vz);
					//len = 1;
				}
			};

			static ViewMatrix* getInstance(void);

			void Update(void);
			void Set(const Camera& camera);

			void Release(void)override {}

		private:
			ViewMatrix() : _camera(Camera()) {}
			~ViewMatrix() {}

			static ViewMatrix* instance;

			DirectX::XMMATRIX _viewMtx;
			DirectX::XMMATRIX _invViewMtx;
			Camera _camera;
		};
	}
}

#endif // DX12_VIEW_MATRIX_H_