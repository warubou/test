// ------------------------------------------------------------------------------------------------
// vector2.h								�I���W�i���x�N�g��(Vector2)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTOR�ɂ��Ă͑S��float�^���Q�Ƃ���
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <DirectXMath.h>

namespace ko {

	// ==========================================================
	// �O���錾
	// ========================================================== 
	struct Vector3;
	struct Vector4;
	struct KOVECTOR;

	// ==========================================================
	// Vector2
	// ========================================================== 
	struct Vector2
	{
		union {
			float _vec[2];
			struct {
				float _x, _y;
			};
		};

		// ===============================
		// �R���X�g���N�^
		// ===============================
		//Vector2() :Vector2(0.0f, 0.0f) {}
		Vector2() = default;
		Vector2(const Vector3& v);
		Vector2(const Vector4& v);
		Vector2(const KOVECTOR& v);
		Vector2(const DirectX::XMFLOAT2& v) : _x(v.x), _y(v.y) {}
		Vector2(const DirectX::XMFLOAT3& v) : _x(v.x), _y(v.y) {}
		Vector2(const DirectX::XMFLOAT4& v) : _x(v.x), _y(v.y) {}
		Vector2(const DirectX::XMVECTOR& v) : _x(v.m128_f32[0]), _y(v.m128_f32[1]) {}
		Vector2(float X, float Y) :_x(X), _y(Y) {}
		Vector2(float XY) : _x(XY), _y(XY) {}

		// ==========================================================
		// DirectX::XM�n�Ƃ̈ÖٓI�ϊ�
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_x, _y, 0.0f, 0.0f);
		}

		operator DirectX::XMFLOAT2() const {
			return DirectX::XMFLOAT2(_x, _y);
		}

		// ==========================================================
		// ���Z�q�̃I�[�o�[���[�h�I�I
		// ========================================================== 
		// +Vector2
		// ===============================
		Vector2 operator+ (void)const;
		// -Vector2
		// ===============================
		Vector2 operator- (void)const;

		// Vector2 + Vector2
		// ===============================
		Vector2 operator+ (const Vector2& vec)const;
		// Vector2 - Vector2
		// ===============================
		Vector2 operator- (const Vector2& vec)const;
		// Vector2 * Vector2
		// ===============================
		Vector2 operator* (const Vector2& vec)const;
		// Vector2 / Vector2
		// ===============================
		Vector2 operator/ (const Vector2& vec)const;
		// Vector2 + float
		// ===============================
		Vector2 operator+ (const float& t)const;
		// Vector2 - float
		// ===============================
		Vector2 operator- (const float& t)const;
		// Vector2 * float
		// ===============================
		Vector2 operator* (const float& t)const;
		// Vector2 / float
		// ===============================
		Vector2 operator/ (const float& t)const;
		// Vector2 + Vector3
		// ===============================
		Vector2 operator+ (const Vector3& vec)const;
		// Vector2 - Vector3
		// ===============================
		Vector2 operator- (const Vector3& vec)const;
		// Vector2 * Vector3
		// ===============================
		Vector2 operator* (const Vector3& vec)const;
		// Vector2 / Vector3
		// ===============================
		Vector2 operator/ (const Vector3& vec)const;
		// Vector2 + Vector4
		// ===============================
		Vector2 operator+ (const Vector4& vec)const;
		// Vector2 - Vector4
		// ===============================
		Vector2 operator- (const Vector4& vec)const;
		// Vector2 * Vector4
		// ===============================
		Vector2 operator* (const Vector4& vec)const;
		// Vector2 / Vector4
		// ===============================
		Vector2 operator/ (const Vector4& vec)const;
		// Vector2 + KOVECTOR
		// ===============================
		Vector2 operator+ (const KOVECTOR& vec)const;
		// Vector2 - KOVECTOR
		// ===============================
		Vector2 operator- (const KOVECTOR& vec)const;
		// Vector2 * KOVECTOR
		// ===============================
		Vector2 operator* (const KOVECTOR& vec)const;
		// Vector2 / KOVECTOR
		// ===============================
		Vector2 operator/ (const KOVECTOR& vec)const;

		// Vector2 += Vector2
		// ===============================
		Vector2& operator+= (const Vector2& vec);
		// Vector2 -= Vector2
		// ===============================
		Vector2& operator-= (const Vector2& vec);
		// Vector2 *= Vector2
		// ===============================
		Vector2& operator*= (const Vector2& vec);
		// Vector2 /= Vector2
		// ===============================
		Vector2& operator/= (const Vector2& vec);
		// Vector2 += float
		// ===============================
		Vector2& operator+= (const float& t);
		// Vector2 -= float
		// ===============================
		Vector2& operator-= (const float& t);
		// Vector2 *= float
		// ===============================
		Vector2& operator*= (const float& t);
		// Vector2 /= float
		// ===============================
		Vector2& operator/= (const float& t);
		// Vector2 += Vector3
		// ������_z�͖���
		// ===============================
		Vector2& operator+= (const Vector3& vec);
		// Vector2 -= Vector3
		// ������_z�͖���
		// ===============================
		Vector2& operator-= (const Vector3& vec);
		// Vector2 *= Vector3
		// ������_z�͖���
		// ===============================
		Vector2& operator*= (const Vector3& vec);
		// Vector2 /= Vector3
		// ������_z�͖���
		// ===============================
		Vector2& operator/= (const Vector3& vec);
		// Vector2 += Vector4
		// ������_z�A_w�͖���
		// ===============================
		Vector2& operator+= (const Vector4& vec);
		// Vector2 -= Vector4
		// ������_z�A_w�͖���
		// ===============================
		Vector2& operator-= (const Vector4& vec);
		// Vector2 *= Vector4
		// ������_z�A_w�͖���
		// ===============================
		Vector2& operator*= (const Vector4& vec);
		// Vector2 /= Vector4
		// ������_z�A_w�͖���
		// ===============================
		Vector2& operator/= (const Vector4& vec);
		// Vector2 += KOVECTOR
		// ������_zFloat�A_wFloat�͖���
		// ===============================
		Vector2& operator+= (const KOVECTOR& vec);
		// Vector2 -= KOVECTOR
		// ������_zFloat�A_wFloat�͖���
		// ===============================
		Vector2& operator-= (const KOVECTOR& vec);
		// Vector2 *= KOVECTOR
		// ������_zFloat�A_wFloat�͖���
		// ===============================
		Vector2& operator*= (const KOVECTOR& vec);
		// Vector2 /= KOVECTOR
		// ������_zFloat�A_wFloat�͖���
		// ===============================
		Vector2& operator/= (const KOVECTOR& vec);


		// if(Vector2 == Vector2)
		// ===============================
		bool operator== (const Vector2& vec)const;
		// if(Vector2 != Vector2)
		// ===============================
		bool operator!= (const Vector2& vec)const;
		// if(Vector2 == Vector3)
		// ===============================
		bool operator== (const Vector3& vec)const;
		// if(Vector2 != Vector3)
		// ===============================
		bool operator!= (const Vector3& vec)const;
		// if(Vector2 == Vector4)
		// ===============================
		bool operator== (const Vector4& vec)const;
		// if(Vector2 != Vector4)
		// ===============================
		bool operator!= (const Vector4& vec)const;
		// if(Vector2 == KOVECTOR)
		// ===============================
		bool operator== (const KOVECTOR& vec)const;
		// if(Vector2 != KOVECTOR)
		// ===============================
		bool operator!= (const KOVECTOR& vec)const;

		// Vector2 = Vector3
		// ===============================
		Vector2& operator= (const Vector3& vec);
		// Vector2 = Vector4
		// ===============================
		Vector2& operator= (const Vector4& vec);
		// Vector2 = KOVECTOR
		// ===============================
		Vector2& operator= (const KOVECTOR& vec);

		// Vector2�̒l�S��0.0f�𐶐�
		// ===============================
		static const Vector2 zero;
		// Vector2�̒l�S��1.0f�𐶐�
		// ===============================
		static const Vector2 one;
		// _y =  1.0f��Vector2�𐶐�
		// ===============================
		static const Vector2 up;
		// _y = -1.0f��Vector2�𐶐�
		// ===============================
		static const Vector2 down;
		// _x =  1.0f��Vector2�𐶐�
		// ===============================
		static const Vector2 right;
		// _x = -1.0f��Vector2�𐶐�
		// ===============================
		static const Vector2 left;
	};

}

#endif // VECTOR2_H_