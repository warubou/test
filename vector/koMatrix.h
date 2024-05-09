// ------------------------------------------------------------------------------------------------
// koMatrix.h								�I���W�i���x�N�g��(KOMatrix)
// Date 2023/12/26
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef KO_MATRIX_H_
#define KO_MATRIX_H_

#include "vector3.h"
#include "vector4.h"
#include "koVector.h"
#include <DirectXMath.h>

namespace ko
{
	// ========================================
	// Matrix
	// ========================================
	struct Matrix
	{
		union {
			DirectX::XMFLOAT4X4 mat;
			float    _mat[4][4];
			Vector4  _vec[4];
			KOVECTOR _koVec[4];

			struct {
				float _m11, _m12, _m13, _m14;
				float _m21, _m22, _m23, _m24;
				float _m31, _m32, _m33, _m34;
				float _m41, _m42, _m43, _m44;
			};
		};

		// �R���X�g���N�^
		// ===============================
		Matrix() :Matrix(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {}
		Matrix(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44)
			: _m11(m11), _m12(m12), _m13(m13), _m14(m14),
			_m21(m21), _m22(m22), _m23(m23), _m24(m24),
			_m31(m31), _m32(m32), _m33(m33), _m34(m34),
			_m41(m41), _m42(m42), _m43(m43), _m44(m44) {}

		// ==========================================================
		// DirectX::XM�n�Ƃ̈ÖٓI�ϊ�
		// ==========================================================
		operator DirectX::XMMATRIX() const {
			return DirectX::XMLoadFloat4x4(&mat);
		}

		// ==========================================================
		// ���Z�q�̃I�[�o�[���[�h�I�I
		// ==========================================================
		// +Matrix
		// ===============================
		Matrix operator+ (void)const;
		// -Matrix
		// ===============================
		Matrix operator- (void)const;

		// Matrix + Matrix
		// ===============================
		Matrix operator+ (const Matrix& mat)const;
		// Matrix - Matrix
		// ===============================
		Matrix operator- (const Matrix& mat)const;
		// Matrix * Matrix
		// ===============================
		Matrix operator* (const Matrix& mat)const;
		// Matrix / Matrix
		// ===============================
		Matrix operator/ (const Matrix& mat)const;

		// Matirx += Matrix
		// ===============================
		Matrix& operator+= (const Matrix& mat);
		// Matrix -= Matrix
		// ===============================
		Matrix& operator-= (const Matrix& mat);
		// Matirx *= Matrix
		// ===============================
		Matrix& operator*= (const Matrix& mat);
		// Matrix /= Matrix
		// ===============================
		Matrix& operator/= (const Matrix& mat);

		// if(Matrix == Matrix)
		// ===============================
		bool operator== (const Matrix& mat)const;
		// if(Matrix != Matrix)
		// ===============================
		bool operator!= (const Matrix& mat)const;

		// Matrix�̑S�Ă̒l0.0f�𐶐�
		// ===============================
		static const Matrix zero;
		// Matrix�̑S�Ă̒l1.0f�𐶐�
		// ===============================
		static const Matrix one;
		// Matrix�̑S�Ă̒l-1.0f�𐶐�
		// ===============================
		static const Matrix allminus;
		// Matrix�̒P�ʍs��𐶐�
		// ===============================
		static const Matrix identity;
	};
}

#endif // KO_MATRIX_H_
