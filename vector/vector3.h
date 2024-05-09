// ------------------------------------------------------------------------------------------------
// vector3.h								�I���W�i���x�N�g��(Vector3)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTOR�ɂ��Ă͑S��float�^���Q�Ƃ���
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <DirectXMath.h>

namespace ko 
{
	// ==========================================================
	// �O���錾
	// ========================================================== 
	struct Vector2;
	struct Vector4;
	struct KOVECTOR;

	// ==========================================================
	// Vector3
	// ========================================================== 
	struct Vector3
	{
		union {
			float _vec[3];
			struct {
				float _x, _y, _z;
			};
		};

		// ===============================
		// �R���X�g���N�^
		// ===============================
		//Vector3() :Vector3(0.0f, 0.0f, 0.0f) {}
		Vector3() = default;
		Vector3(const Vector2& v);
		Vector3(const Vector2& v, const float& t);
		Vector3(const Vector4& v);
		Vector3(const KOVECTOR& v);
		Vector3(const DirectX::XMFLOAT2& v) : _x(v.x), _y(v.y), _z(0.0f) {}
		Vector3(const DirectX::XMFLOAT3& v) : _x(v.x), _y(v.y), _z(v.z) {}
		Vector3(const DirectX::XMVECTOR& v) : _x(v.m128_f32[0]), _y(v.m128_f32[1]), _z(v.m128_f32[2]) {}
		Vector3(float X, float Y, float Z) :_x(X), _y(Y), _z(Z) {}
		Vector3(float XYZ) :_x(XYZ), _y(XYZ), _z(XYZ) {}

		// ==========================================================
		// DirectX::XM�n�Ƃ̈ÖٓI�ϊ�
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_x, _y, _z, 0.0f);
		}

		operator DirectX::XMFLOAT3() const {
			return DirectX::XMFLOAT3(_x, _y, _z);
		}

		// ==========================================================
		// ���Z�q�̃I�[�o�[���[�h�I�I
		// ==========================================================
		// +Vector3
		// ===============================
		Vector3 operator+ (void)const;
		// -Vector3
		// ===============================
		Vector3 operator- (void)const;

		// Vector3 + Vector3
		// ===============================
		Vector3 operator+ (const Vector3& vec)const;
		// Vector3 - Vector3
		// ===============================
		Vector3 operator- (const Vector3& vec)const;
		// Vector3 * Vector3
		// ===============================
		Vector3 operator* (const Vector3& vec)const;
		// Vector3 / Vector3
		// ===============================
		Vector3 operator/ (const Vector3& vec)const;
		// Vector3 + float
		// ===============================
		Vector3 operator+ (const float& t)const;
		// Vector3 - float
		// ===============================
		Vector3 operator- (const float& t)const;
		// Vector3 * float
		// ===============================
		Vector3 operator* (const float& t)const;
		// Vector3 / float
		// ===============================
		Vector3 operator/ (const float& t)const;
		// Vector3 + Vector2
		// _z�͖���
		// ===============================
		Vector3 operator+ (const Vector2& vec)const;
		// Vector3 - Vector2
		// _z�͖���
		// ===============================
		Vector3 operator- (const Vector2& vec)const;
		// Vector3 * Vector2
		// _z�͖���
		// ===============================
		Vector3 operator* (const Vector2& vec)const;
		// Vector3 / Vector2
		// _z�͖���
		// ===============================
		Vector3 operator/ (const Vector2& vec)const;
		// Vector3 + Vector4
		// ������_w�͖���
		// ===============================
		Vector3 operator+ (const Vector4& vec)const;
		// Vector3 - Vector4
		// ������_w�͖���
		// ===============================
		Vector3 operator- (const Vector4& vec)const;
		// Vector3 * Vector4
		// ������_w�͖���
		// ===============================
		Vector3 operator* (const Vector4& vec)const;
		// Vector3 / Vector4
		// ������_w�͖���
		// ===============================
		Vector3 operator/ (const Vector4& vec)const;
		// Vector3 + KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3 operator+ (const KOVECTOR& vec)const;
		// Vector3 - KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3 operator- (const KOVECTOR& vec)const;
		// Vector3 * KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3 operator* (const KOVECTOR& vec)const;
		// Vector3 / KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3 operator/ (const KOVECTOR& vec)const;

		// Vector3 += Vector3
		// ===============================
		Vector3& operator+= (const Vector3& vec);
		// Vector3 -= Vector3
		// ===============================
		Vector3& operator-= (const Vector3& vec);
		// Vector3 *= Vector3
		// ===============================
		Vector3& operator*= (const Vector3& vec);
		// Vector3 /= Vector3
		// ===============================
		Vector3& operator/= (const Vector3& vec);
		// Vector3 += float
		// ===============================
		Vector3& operator+= (const float& t);
		// Vector3 -= float
		// ===============================
		Vector3& operator-= (const float& t);
		// Vector3 *= float
		// ===============================
		Vector3& operator*= (const float& t);
		// Vector3 /= float
		// ===============================
		Vector3& operator/= (const float& t);
		// Vector3 += Vector2
		// _z�͖���
		// ===============================
		Vector3& operator+= (const Vector2& vec);
		// Vector3 -= Vector2
		// _z�͖���
		// ===============================
		Vector3& operator-= (const Vector2& vec);
		// Vector3 *= Vector2
		// _z�͖���
		// ===============================
		Vector3& operator*= (const Vector2& vec);
		// Vector3 /= Vector2
		// _z�͖���
		// ===============================
		Vector3& operator/= (const Vector2& vec);
		// Vector3 += Vector4
		// ������_w�͖���
		// ===============================
		Vector3& operator+= (const Vector4& vec);
		// Vector3 -= Vector4
		// ������_w�͖���
		// ===============================
		Vector3& operator-= (const Vector4& vec);
		// Vector3 *= Vector4
		// ������_w�͖���
		// ===============================
		Vector3& operator*= (const Vector4& vec);
		// Vector3 /= Vector4
		// ������_w�͖���
		// ===============================
		Vector3& operator/= (const Vector4& vec);
		// Vector3 += KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3& operator+= (const KOVECTOR& vec);
		// Vector3 -= KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3& operator-= (const KOVECTOR& vec);
		// Vector3 *= KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3& operator*= (const KOVECTOR& vec);
		// Vector3 /= KOVECTOR
		// ������_wFloat�͖���
		// ===============================
		Vector3& operator/= (const KOVECTOR& vec);

		// if(Vector3 == Vector3)
		// ===============================
		bool operator== (const Vector3& vec)const;
		// if(Vector3 != Vector3)
		// ===============================
		bool operator!= (const Vector3& vec)const;
		// if(Vector3 == Vector2)
		// _z�͔�r���Ȃ�
		// ===============================
		bool operator== (const Vector2& vec)const;
		// if(Vector3 != Vector2)
		// _z�͔�r���Ȃ�
		// ===============================
		bool operator!= (const Vector2& vec)const;
		// if(Vector3 == Vector4)
		// ������_w�͔�r���Ȃ�
		// ===============================
		bool operator== (const Vector4& vec)const;
		// if(Vector3 != Vector4)
		// ������_w�͔�r���Ȃ�
		// ===============================
		bool operator!= (const Vector4& vec)const;
		// if(Vector3 == KOVECTOR)
		// ������_wFloat�͔�r���Ȃ�
		// ===============================
		bool operator== (const KOVECTOR& vec)const;
		// if(Vector3 != KOVECTOR)
		// ������_wFloat�͔�r���Ȃ�
		// ===============================
		bool operator!= (const KOVECTOR& vec)const;

		// Vector3 = float
		// _z��0
		// ===============================
		Vector3& operator= (const float& t);
		// Vector3 = Vector2
		// _z��0
		// ===============================
		Vector3& operator= (const Vector2& vec);
		// Vector3 = Vector4
		// ===============================
		Vector3& operator= (const Vector4& vec);
		// Vector3 = KOVECTOR
		// ===============================
		Vector3& operator= (const KOVECTOR& vec);

		// Vector3�̒l�S��0.0f�𐶐�
		// ===============================
		static const Vector3 zero;
		// Vector3�̒l�S��1.0f�𐶐�
		// ===============================
		static const Vector3 one;
		// _y =  1.0f��Vector3�𐶐�
		// ===============================
		static const Vector3 up;
		// _y = -1.0f��Vector3�𐶐�
		// ===============================
		static const Vector3 down;
		// _x =  1.0f��Vector3�𐶐�
		// ===============================
		static const Vector3 right;
		// _x = -1.0f��Vector3�𐶐�
		// ===============================
		static const Vector3 left;
		// _z =  1.0f��Vector3�𐶐�(������W�n)
		// ===============================
		static const Vector3 frontLH;
		// _z = -1.0f��Vector3�𐶐�(������W�n)
		// ===============================
		static const Vector3 backLH;
		// _z = -1.0f��Vector3�𐶐�(�E����W�n)
		// ===============================
		static const Vector3 frontRH;
		// _z =  1.0f��Vector3�𐶐�(�E����W�n)
		// ===============================
		static const Vector3 backRH;
	};

}

#endif // VECTOR3_H_