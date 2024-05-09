// ------------------------------------------------------------------------------------------------
// vector4.h								�I���W�i���x�N�g��(Vector4)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTOR�ɂ��Ă͑S��float�^���Q�Ƃ���
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef VECTOR4_H_
#define VECTOR4_H_

#include <DirectXMath.h>

namespace ko
{
	// ==========================================================
	// �O���錾
	// ========================================================== 
	struct Vector2;
	struct Vector3;
	struct KOVECTOR;

	// ==========================================================
	// Vector4
	// ========================================================== 
	struct Vector4
	{
		union {
			float _vec[4];
			struct {
				float _x, _y, _z, _w;
			};
		};

		// �R���X�g���N�^
		// ===============================
		//Vector4() :Vector4(0.0f, 0.0f, 0.0f, 0.0f) {}
		Vector4() = default;
		Vector4(const Vector2& v);
		Vector4(const Vector2& v1, const Vector2& v2);
		Vector4(const Vector2& v, const float& t1, const float& t2);
		Vector4(const Vector3& v);
		Vector4(const Vector3& v, const float& t);
		Vector4(const KOVECTOR& v);
		Vector4(const DirectX::XMFLOAT2& v) : _x(v.x), _y(v.y), _z(0.0f), _w(0.0f) {}
		Vector4(const DirectX::XMFLOAT3& v) : _x(v.x), _y(v.y), _z(v.z), _w(0.0f) {}
		Vector4(const DirectX::XMFLOAT4& v) : _x(v.x), _y(v.y), _z(v.z), _w(v.w) {}
		Vector4(const DirectX::XMVECTOR& v) : _x(v.m128_f32[0]), _y(v.m128_f32[1]), _z(v.m128_f32[2]), _w(v.m128_f32[3]) {}
		Vector4(float X, float Y, float Z, float W) :_x(X), _y(Y), _z(Z), _w(W) {}
		Vector4(float XYZW) :_x(XYZW), _y(XYZW), _z(XYZW), _w(XYZW) {}

		// ==========================================================
		// DirectX::XM�n�Ƃ̈ÖٓI�ϊ�
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_x, _y, _z, _w);
		}

		operator DirectX::XMFLOAT4() const {
			return DirectX::XMFLOAT4(_x, _y, _z, _w);
		}

		// ==========================================================
		// ���Z�q�̃I�[�o�[���[�h�I�I
		// ========================================================== 
		// +Vector4
		// ===============================
		Vector4 operator+ (void)const;
		// -Vector4
		// ===============================
		Vector4 operator- (void)const;

		// Vector4 + Vector4
		// ===============================
		Vector4 operator+ (const Vector4& vec)const;
		// Vector4 - Vector4
		// ===============================
		Vector4 operator- (const Vector4& vec)const;
		// Vector4 * Vector4
		// ===============================
		Vector4 operator* (const Vector4& vec)const;
		// Vector4 / Vector4
		// ===============================
		Vector4 operator/ (const Vector4& vec)const;
		// Vector4 + float
		// ===============================
		Vector4 operator+ (const float& t)const;
		// Vector4 - float
		// ===============================
		Vector4 operator- (const float& t)const;
		// Vector4 * float
		// ===============================
		Vector4 operator* (const float& t)const;
		// Vector4 / float
		// ===============================
		Vector4 operator/ (const float& t)const;
		// Vector4 + Vector2
		// _z,_w�͖���
		// ===============================
		Vector4 operator+ (const Vector2& vec)const;
		// Vector4 - Vector2
		// _z,_w�͖���
		// ===============================
		Vector4 operator- (const Vector2& vec)const;
		// Vector4 * Vector2
		// _z,_w�͖���
		// ===============================
		Vector4 operator* (const Vector2& vec)const;
		// Vector4 / Vector2
		// _z,_w�͖���
		// ===============================
		Vector4 operator/ (const Vector2& vec)const;
		// Vector4 + Vector3
		// _w�͖���
		// ===============================
		Vector4 operator+ (const Vector3& vec)const;
		// Vector4 - Vector3
		// _w�͖���
		// ===============================
		Vector4 operator- (const Vector3& vec)const;
		// Vector4 * Vector3
		// _w�͖���
		// ===============================
		Vector4 operator* (const Vector3& vec)const;
		// Vector4 / Vector3
		// _w�͖���
		// ===============================
		Vector4 operator/ (const Vector3& vec)const;
		// Vector4 + KOVECTOR
		// ===============================
		Vector4 operator+ (const KOVECTOR& vec)const;
		// Vector4 - KOVECTOR
		// ===============================
		Vector4 operator- (const KOVECTOR& vec)const;
		// Vector4 * KOVECTOR
		// ===============================
		Vector4 operator* (const KOVECTOR& vec)const;
		// Vector4 / KOVECTOR
		// ===============================
		Vector4 operator/ (const KOVECTOR& vec)const;

		// Vector4 += Vector4
		// ===============================
		Vector4& operator+= (const Vector4& vec);
		// Vector4 -= Vector4
		// ===============================
		Vector4& operator-= (const Vector4& vec);
		// Vector4 *= Vector4
		// ===============================
		Vector4& operator*= (const Vector4& vec);
		// Vector4 /= Vector4
		// ===============================
		Vector4& operator/= (const Vector4& vec);
		// Vector4 += float
		// ===============================
		Vector4& operator+= (const float& t);
		// Vector4 -= float
		// ===============================
		Vector4& operator-= (const float& t);
		// Vector4 *= float
		// ===============================
		Vector4& operator*= (const float& t);
		// Vector4 /= float
		// ===============================
		Vector4& operator/= (const float& t);
		// Vector4 += Vector2
		// ===============================
		Vector4& operator+= (const Vector2& vec);
		// Vector4 -= Vector2
		// ===============================
		Vector4& operator-= (const Vector2& vec);
		// Vector4 *= Vector2
		// ===============================
		Vector4& operator*= (const Vector2& vec);
		// Vector4 /= Vector2
		// ===============================
		Vector4& operator/= (const Vector2& vec);
		// Vector4 += Vector3
		// ===============================
		Vector4& operator+= (const Vector3& vec);
		// Vector4 -= Vector3
		// ===============================
		Vector4& operator-= (const Vector3& vec);
		// Vector4 *= Vector3
		// ===============================
		Vector4& operator*= (const Vector3& vec);
		// Vector4 /= Vector3
		// ===============================
		Vector4& operator/= (const Vector3& vec);
		// Vector4 += KOVECTOR
		// ===============================
		Vector4& operator+= (const KOVECTOR& vec);
		// Vector4 -= KOVECTOR
		// ===============================
		Vector4& operator-= (const KOVECTOR& vec);
		// Vector4 *= KOVECTOR
		// ===============================
		Vector4& operator*= (const KOVECTOR& vec);
		// Vector4 /= KOVECTOR
		// ===============================
		Vector4& operator/= (const KOVECTOR& vec);

		// if(Vector4 == Vector4)
		// ===============================
		bool operator== (const Vector4& vec)const;
		// if(Vector4 != Vector4)
		// ===============================
		bool operator!= (const Vector4& vec)const;
		// if(Vector4 == Vector2)
		// ������_z,_w�͖���
		// ===============================
		bool operator== (const Vector2& vec)const;
		// if(Vector4 != Vector2)
		// ������_z,_w�͖���
		// ===============================
		bool operator!= (const Vector2& vec)const;
		// if(Vector4 == Vector3)
		// ������_w�͖���
		// ===============================
		bool operator== (const Vector3& vec)const;
		// if(Vector4 != Vector3)
		// ������_w�͖���
		// ===============================
		bool operator!= (const Vector3& vec)const;
		// if(Vector4 == KOVECTOR)
		// ===============================
		bool operator== (const KOVECTOR& vec)const;
		// if(Vector4 != KOVECTOR)
		// ===============================
		bool operator!= (const KOVECTOR& vec)const;

		// Vector4 = Vector2
		// _z,_w ��0
		// ===============================
		Vector4& operator= (const Vector2& vec);
		// Vector4 = Vector3
		// _w ��0
		// ===============================
		Vector4& operator= (const Vector3& vec);
		// Vector4 = KOVECTOR
		// ===============================
		Vector4& operator= (const KOVECTOR& vec);

		// Vector4�̒l�S��0.0f�𐶐�
		// ===============================
		static const Vector4 zero;
		// Vector4�̒l�S��1.0f�𐶐�
		// ===============================
		static const Vector4 one;
		// _y =  1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 up;
		// _y = -1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 down;
		// _x =  1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 right;
		// _x = -1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 left;
		// _z =  1.0f��Vector4�𐶐�(������W�n)
		// ===============================
		static const Vector4 frontLH;
		// _z = -1.0f��Vector4�𐶐�(������W�n)
		// ===============================
		static const Vector4 backLH;
		// _z = -1.0f��Vector4�𐶐�(�E����W�n)
		// ===============================
		static const Vector4 frontRH;
		// _z =  1.0f��Vector4�𐶐�(�E����W�n)
		// ===============================
		static const Vector4 backRH;
		// _w =  1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 plusW;
		// _w = -1.0f��Vector4�𐶐�
		// ===============================
		static const Vector4 minusW;
	};
}

#endif // VECTOR4_H_
