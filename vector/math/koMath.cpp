// ------------------------------------------------------------------------------------------------
// koMath.cpp								�I���W�i���x�N�g���v�Z���w�֐�
// Date 2023/12/27
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#include "koMath.h"

#include <DirectXMath.h>

namespace ko
{
	namespace vector2
	{
		// Vector2����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector2& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y);
		}

		// Vector2��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			Vector2 temp = ko::vector2::Subtract(vec2, vec1);
			return ko::vector2::LengthSq(temp);
		}

		// Vector2����float�^�̒������擾
		// ===============================
		const float& Length(const Vector2& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y);
		}

		// Vector2��2�_�Ԃ̋������v�Z
		// ===============================
		const float& Length(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			Vector2 temp = ko::vector2::Subtract(vec2, vec1);
			return ko::vector2::Length(temp);
		}

		// Vector2���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector2& vec)noexcept
		{
			float length = ko::vector2::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector3���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector3& vec)noexcept
		{
			Vector2 v;
			v = vec;
			float length = ko::vector2::Length(v);
			if (length != 0)
				return v / length;
			return v;
		}

		// Vector4���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector4& vec)noexcept
		{
			Vector2 v;
			v = vec;
			float length = ko::vector2::Length(v);
			if (length != 0)
				return v / length;
			return v;
		}

		// Vector2����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1._x * vec2._x + vec1._y * vec2._y;
		}

		// Vector2����Vector2�^�̊O�ς��擾
		// ===============================
		const float& Cross(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1._x * vec2._y - vec1._y * vec2._x;
		}

		// Vector2����Vector2���m�̍������擾(Vector2�^)
		// ===============================
		const Vector2& Subtract(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector2�Ԃ���`�⊮���ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector2& vec1, const Vector2& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}
	}

	namespace vector3
	{
		// Vector3����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector3& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y + vec._z * vec._z);
		}

		// Vector3��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 temp = ko::vector3::Subtract(vec2, vec1);
			return ko::vector3::LengthSq(temp);
		}

		// Vector3����float�^�̒������擾
		// ===============================
		const float& Length(const Vector3& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y + vec._z * vec._z);
		}

		// Vector3��2�_�Ԃ̒������擾
		// ===============================
		const float& Length(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 temp = ko::vector3::Subtract(vec2, vec1);
			return ko::vector3::Length(temp);
		}

		// Vector3���琳�K������Vector3�^���擾
		// ===============================
		const Vector3& Normalize(const Vector3& vec)noexcept
		{
			float length = ko::vector3::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector4���琳�K������Vector3�^���擾
		// ===============================
		const Vector3& Normalize(const Vector4& vec)noexcept
		{
			Vector3 v;
			v = vec;
			float length = ko::vector3::Length(v);
			if (length != 0)
				return v / length;
			return v;
		}

		// Vector3����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			return (vec1._x * vec2._x + vec1._y * vec2._y + vec1._z * vec2._z);
		}

		// Vector3����Vector3�^�̊O�ς��擾
		// ===============================
		const Vector3& Cross(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 v;

			v._x = vec1._y * vec2._z - vec1._z * vec2._y;
			v._y = vec1._z * vec2._x - vec1._x * vec2._z;
			v._z = vec1._x * vec2._y - vec1._y * vec2._x;

			return v;
		}

		// Vector3����Vector3���m�̍������擾(Vector3�^)
		// ===============================
		const Vector3& Subtract(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector3�Ԃ���`�⊮����Vector2�^�Ƃ��ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}

		// Vector3�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector3& Vec3Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept
		{
			return Vector3(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z));
		}
	}

	namespace vector4
	{
		// Vector4����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector4& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y + vec._z * vec._z + vec._w * vec._w);
		}

		// Vector4��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector4 temp = ko::vector4::Subtract(vec2, vec1);
			return ko::vector4::LengthSq(temp);
		}

		// Vector4����float�^�̒������擾
		// ===============================
		const float& Length(const Vector4& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y + vec._z * vec._z + vec._w * vec._w);
		}

		// Vector4��2�_�Ԃ̒������擾
		// ===============================
		const float& Length(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector4 temp = ko::vector4::Subtract(vec2, vec1);
			return ko::vector4::Length(temp);
		}

		// Vector4���琳�K������Vector4�^���擾
		// ===============================
		const Vector4& Normalize(const Vector4& vec)noexcept
		{
			float length = ko::vector4::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector4����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector4& vec1, const Vector4 vec2)noexcept
		{
			return (vec1._x * vec2._x + vec1._y * vec2._y + vec1._z * vec2._z + vec1._w * vec2._w);
		}

		// Vector4����Vector4�^�̊O�ς��擾
		// ������
		// ===============================
		const Vector4& Cross(const Vector4& vec1, const Vector4 vec2)noexcept
		{
			return Vector4::zero;
		}

		// Vector4����Vector4���m�̍������擾(Vector4�^)
		// ===============================
		const Vector4& Subtract(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}

		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector3& Vec3Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector3(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z));
		}

		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector4& Vec4Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector4(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z), vec1._w + t * (vec2._w - vec1._w));
		}
	}

	namespace color
	{
		// ��{�I�ȃO���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScale(const Color& color)noexcept
		{
			Color temp;
			temp = (color._a * 0.2126f + color._g * 0.7152f + color._b * 0.0722f) / 3;
			return temp;
		}

		// R����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleR(const Color& color)noexcept
		{
			return Color(color._r, color._r, color._r, color._a);
		}

		// G����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleG(const Color& color)noexcept
		{
			return Color(color._g, color._g, color._g, color._a);
		}

		// B����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleB(const Color& color)noexcept
		{
			return Color(color._b, color._b, color._b, color._a);
		}

		// R,G,B�����ꂼ�ꔽ�]�����F���擾
		// ===============================
		const Color& KOColorNegapoji(const Color& color)noexcept
		{
			Color temp = color;
			for (int index = 0; index < 4; ++index)
			{
				temp._color[index] = 1.0f - temp._color[index];
			}

			return ko::koMath::ColorClamp(temp, Color::black, Color::white);
		}

		// �Z�s�A���̐F���擾
		// ===============================
		const Color& KOColorSepia(const Color& color)noexcept
		{
			float Y = 0.299f * color._r + 0.587f * color._g + 0.114f * color._b;

			// �Z�s�A���ł̓��m�N�����Ƃ͈Ⴂ�AR,G,B�ɖ��邳�����̂܂ܑ���͂��Ȃ�
			// ����̎����ł́A�Ԃ݂̐�����0.9�A�΂�0.7�Ab��0.4�̏d�݂���Z���Ă���
			Color temp = Color();
			temp._r = Y * 0.9f;
			temp._g = Y * 0.7f;
			temp._b = Y * 0.4f;

			return temp;
		}

		// ���m�N�����̐F���擾
		// ===============================
		const Color& KOColorMonocrome(const Color& color)noexcept
		{
			// �摜�����m�N���ɕω������Ă���
			// �s�N�Z���̖��邳���v�Z����
			float Y = 0.299f * color._r + 0.587 * color._g + 0.114f * color._b;

			Color temp = Color();
			temp = Y;

			return temp;
		}

		// R�̒l�̂ݎ擾
		// ===============================
		const Color& KOColorRScale(const Color& color)noexcept
		{
			return Color(color._r, 0.0f, 0.0f, color._a);
		}

		// G�̒l�̂ݎ擾
		// ===============================
		const Color& KOColorGScale(const Color& color)noexcept
		{
			return Color(0.0f, color._g, 0.0f, color._a);
		}

		// B�̒l�̂ݎ擾
		// ===============================
		const Color& KOCOlorBScale(const Color& color)noexcept
		{
			return Color(0.0f, 0.0f, color._b, color._a);
		}

		// 0.0f�`1.0f�̒l�Ɏ��߂Ď擾
		// ===============================
		const Color& KOColorSaturate(const Color& color)noexcept
		{
			return ko::koMath::ColorClamp(color, Color::white, Color::black);
		}
	}

	namespace koVector
	{
		// KOVECTOR��Ԃ�l�Ɉ������Z�b�g
		// ===============================
		const KOVECTOR& KOVectorSet(const float& X, const float& Y, const float& Z, const float& W)noexcept
		{
			return KOVECTOR(X, Y, Z, W);
		}

		// KOVECTOR����_xFloat,_yFloat���擾��float�^�Œ������擾
		// ===============================
		const float& KOVector2Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat);
		}

		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��float�^�Œ������擾
		// ===============================
		const float& KOVector3Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat + vec._zFloat * vec._zFloat);
		}

		// KOVECTOR����l�S�Ă��擾��float�^�Œ������擾
		// ===============================
		const float& KOVector4Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat + vec._zFloat * vec._zFloat + vec._wFloat * vec._wFloat);
		}

		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector2Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector2Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// KOVECTOR����_xFloat,_yFloat, _zFloat���擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector3Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector3Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// KOVECTOR����l�S�Ă��擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector4Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector4Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// 2�l��KOVECTOR����vec1����vec2��������������KOVECTOR�^�Ŏ擾
		// ===============================
		const KOVECTOR& KOVectorSubtract(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�œ��ς��擾
		// ===============================
		const KOVECTOR& KOVector2Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��KOVECTOR�^�œ��ς��擾
		// ===============================
		const KOVECTOR& KOVector3Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat + vec1._zFloat * vec2._zFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTOR����S�Ă̒l���擾��KOVECTOR�^�œ��ς��擾
		// ===============================
		const KOVECTOR& KOVector4Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat + vec1._zFloat * vec2._zFloat + vec1._wFloat * vec2._wFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�ŊO�ς��擾
		// ===============================
		const KOVECTOR& KOVector2Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			KOVECTOR vec;
			float t = vec1._xFloat * vec2._yFloat - vec1._yFloat * vec2._xFloat;
			vec = t;
			return vec;
		}

		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��KOVECTOR�^�ŊO�ς��擾
		// ===============================
		const KOVECTOR& KOVector3Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			KOVECTOR v;

			v._xFloat = vec1._yFloat * vec2._zFloat - vec1._zFloat * vec2._yFloat;
			v._yFloat = vec1._zFloat * vec2._xFloat - vec1._xFloat * vec2._zFloat;
			v._zFloat = vec1._xFloat * vec2._yFloat - vec1._yFloat * vec2._xFloat;

			return v;
		}

		// KOVECTOR����S�l���擾��KOVECTOR�^�ŊO�ς��擾
		// ===============================
		const KOVECTOR& KOVector4Cross(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& vec3)noexcept
		{
			KOVECTOR v;

			v._xFloat = vec1._yFloat * (vec2._zFloat * vec3._wFloat - vec3._zFloat * vec2._wFloat)
				- vec1._zFloat * (vec2._yFloat * vec3._wFloat - vec3._yFloat * vec2._wFloat)
				+ vec1._wFloat * (vec2._yFloat * vec3._zFloat - vec3._yFloat * vec2._zFloat);

			v._yFloat = vec1._xFloat * (vec3._zFloat * vec2._wFloat - vec2._zFloat * vec3._wFloat)
				- vec1._zFloat * (vec3._xFloat * vec2._wFloat - vec2._xFloat * vec3._wFloat)
				+ vec1._wFloat * (vec3._xFloat * vec2._zFloat - vec2._xFloat * vec3._zFloat);

			v._zFloat = vec1._xFloat * (vec2._yFloat * vec3._wFloat - vec3._yFloat * vec2._wFloat)
				- vec1._yFloat * (vec2._xFloat * vec3._wFloat - vec3._xFloat * vec2._wFloat)
				+ vec1._wFloat * (vec2._xFloat * vec3._yFloat - vec3._xFloat * vec2._yFloat);

			v._wFloat = vec1._xFloat * (vec3._yFloat * vec2._zFloat - vec2._yFloat * vec3._zFloat)
				- vec1._yFloat * (vec3._xFloat * vec2._zFloat - vec2._xFloat * vec3._zFloat)
				+ vec1._zFloat * (vec3._xFloat * vec2._yFloat - vec2._xFloat * vec3._yFloat);

			return v;
		}

		// KOVECTOR����X������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetXF(const KOVECTOR& vec)noexcept
		{
			return vec._xFloat;
		}

		// KOVECTOR����Y������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetYF(const KOVECTOR& vec)noexcept
		{
			return vec._yFloat;
		}

		// KOVECTOR����Z������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetZF(const KOVECTOR& vec)noexcept
		{
			return vec._zFloat;
		}

		// KOVECTOR����Z������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetWF(const KOVECTOR& vec)noexcept
		{
			return vec._wFloat;
		}

		// KOVECTOR����ے���v�Z(DirectX::XMVectorNegate()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorNegate(const KOVECTOR& vec)noexcept
		{
			__m128 changeVec;
			__m128 temp;

			for (int index = 0; index < 4; ++index)
			{
				changeVec.m128_f32[index] = vec._vec[index];
			}

			// SIMD����
			temp = _mm_setzero_ps();

			__m128 resultM = _mm_sub_ps(temp, changeVec);

			KOVECTOR resultVec;
			for (int index = 0; index < 4; ++index)
			{
				resultVec._vec[index] = resultM.m128_f32[index];
			}

			return resultVec;
		}

		// Vector4����ے���v�Z(DirectX::XMVectorNegate()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorNegate(const Vector4& vec)noexcept
		{
			KOVECTOR v;
			v = vec;
			v = ko::koVector::KOVectorNegate(v);
			return v;
		}

		// �܂��Ƃ肠�����������֐�(DirectX::XMVectorSelect()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorSelect(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& controllVec)noexcept
		{
			__m128 tempVec1;
			__m128 tempVec2;
			__m128 tempControllVec;

			for (int index = 0; index < 4; ++index)
			{
				tempVec1.m128_f32[index] = vec1._vec[index];
				tempVec2.m128_f32[index] = vec2._vec[index];
				tempControllVec.m128_u32[index] = controllVec._vecInt[index];
			}

			// SIMD����
			__m128 m1 = _mm_andnot_ps(tempControllVec, tempVec1);
			__m128 m2 = _mm_and_ps(tempVec2, tempControllVec);
			__m128 m3 = _mm_or_ps(m1, m2);

			KOVECTOR resultVec;
			for (int index = 0; index < 4; ++index)
			{
				resultVec._vec[index] = m3.m128_f32[index];
			}
			return resultVec;
		}

		// �S�v�f�������������o
		// ===============================
		const bool& KOVector4Equal(KOVECTOR& vec1, KOVECTOR& vec2)noexcept
		{
			return vec1 == vec2;
		}

		// 3�v�f�������������o
		// ===============================
		const bool& KOVector3Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			Vector3 v1, v2;
			v1 = vec1;
			v2 = vec2;

			return v1 == v2;
		}

		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			Vector2 v1, v2;
			v1 = vec1;
			v2 = vec2;

			return v1 == v2;
		}

		// Vector3�^����Vector3�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector3& KOVector3Normalize(const Vector3& vec)noexcept
		{
			Vector3 v;
			v = ko::vector3::Normalize(vec);
			return v;
		}

		// Vector4�^����Vector3�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector3& KOVector3Normalize(const Vector4& vec)noexcept
		{
			Vector3 v;
			v = ko::vector3::Normalize(vec);
			return v;
		}

		// Vector4�^����Vector4�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector4& KOVector4Normalize(const Vector4& vec)noexcept
		{
			KOVECTOR v;
			v = vec;
			v = ko::koVector::KOVector4Normalize(v);

			Vector4 v4;
			v4._x = v._xFloat;
			v4._y = v._yFloat;
			v4._z = v._zFloat;
			v4._w = v._wFloat;

			return v4;
		}

		// Vector3�^����Vector4�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector4& KOVector4Normalize(const Vector3& vec)noexcept
		{
			KOVECTOR v;
			v = vec;
			v = ko::koVector::KOVector4Normalize(v);

			Vector4 v4;
			v4._x = v._xFloat;
			v4._y = v._yFloat;
			v4._z = v._zFloat;
			v4._w = v._wFloat;
			return v4;
		}

		// Vector4���m�̍�����vector4�^�Ŏ擾
		// ===============================
		const Vector4& KOVectorSubtract(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector4���m�̍�����Vector3�^�Ŏ擾
		// ===============================
		const Vector3& KOVectorSubtractVec3(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector3 v1, v2, v3;
			v1 = vec1;
			v2 = vec2;
			v3 = v1 - v2;
			return v3;
		}

		// Vector3���m��Vector3�̓��ς��擾
		// ===============================
		const Vector3& KOVector3Dot(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;
			v1 = ko::koVector::KOVector3Dot(v1, v2);

			Vector3 v3;
			v3._x = v1._xFloat;
			v3._y = v1._yFloat;
			v3._z = v1._zFloat;
			return v3;
		}

		// Vector4���m��Vector3�̓��ς��擾
		// ===============================
		const Vector3& KOVector3Dot(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;
			v1 = ko::koVector::KOVector3Dot(v1, v2);

			Vector3 v3;
			v3._x = v1._xFloat;
			v3._y = v1._yFloat;
			v3._z = v1._zFloat;
			return v3;
		}

		// Vector4���m��Vector4�̓��ς��擾
		// ===============================
		const Vector4& KOVector4Dot(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;
			v1 = ko::koVector::KOVector4Dot(v1, v2);

			Vector4 v4;
			v4._x = v1._xFloat;
			v4._y = v1._yFloat;
			v4._z = v1._zFloat;
			v4._w = v1._wFloat;

			return v4;
		}

		// vector3���m��vector4�̓��ς��擾
		// ===============================
		const Vector4& KOVector4Dot(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;
			v1 = ko::koVector::KOVector4Dot(v1, v2);

			Vector4 v4;
			v4._x = v1._xFloat;
			v4._y = v1._yFloat;
			v4._z = v1._zFloat;
			v4._w = v1._wFloat;

			return v4;
		}

		// Vector3���m��Vector3�̊O�ς��擾
		// ===============================
		const Vector3& KOVector3Cross(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;

			v1 = ko::koVector::KOVector3Cross(v1, v2);

			Vector3 v3;
			v3._x = v1._xFloat;
			v3._y = v1._yFloat;
			v3._z = v1._zFloat;
			return v3;
		}

		// Vector4���m��Vector3�̊O�ς��擾
		// ===============================
		const Vector3& KOVector3Cross(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			KOVECTOR v1, v2;
			v1 = vec1;
			v2 = vec2;

			v1 = ko::koVector::KOVector3Cross(v1, v2);

			Vector3 v3;
			v3._x = v1._xFloat;
			v3._y = v1._yFloat;
			v3._z = v1._zFloat;
			return v3;
		}

		// Vector4�^3��Vector4�^�̊O�ς��擾
		// ===============================
		const Vector4& KOVector4Cross(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3)noexcept
		{
			KOVECTOR v1, v2, v3;
			v1 = vec1;
			v2 = vec2;
			v3 = vec3;
			v1 = ko::koVector::KOVector4Cross(v1, v2, v3);

			Vector4 v4;
			v4._x = v1._xFloat;
			v4._y = v1._yFloat;
			v4._z = v1._zFloat;
			v4._w = v1._wFloat;

			return v4;
		}

		// Vector3�^3��Vector4�^�̊O�ς��擾
		// ===============================
		const Vector4& KOVector4Cross(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3)noexcept
		{
			KOVECTOR v1, v2, v3;
			v1 = vec1;
			v2 = vec2;
			v3 = vec3;
			v1 = ko::koVector::KOVector4Cross(v1, v2, v3);

			Vector4 v4;
			v4._x = v1._xFloat;
			v4._y = v1._yFloat;
			v4._z = v1._zFloat;
			v4._w = v1._wFloat;

			return v4;
		}

		// 3�v�f�������������o
		// ===============================
		const bool& KOVector3Equal(Vector4& vec1, Vector4& vec2)noexcept
		{
			Vector3 v1, v2;
			v1 = vec1;
			v2 = vec2;
			return v1 == v2;
		}

		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(Vector4& vec1, Vector4& vec2)noexcept
		{
			Vector2 v1, v2;
			v1 = vec1;
			v2 = vec2;
			return v1 == v2;
		}

		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(Vector3& vec1, Vector3& vec2)noexcept
		{
			Vector2 v1, v2;
			v1 = vec1;
			v2 = vec2;
			return v1 == v2;
		}
	}

	namespace koMatrix
	{
		// �P�ʍs��𐶐�
		// ===============================
		const Matrix& KOMatrixIdentity(void)noexcept
		{
			return Matrix::identity;
		}

		// �X�P�[���̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixScaling(float scaleX, float scaleY, float scaleZ)noexcept
		{
			return Matrix(scaleX, 0.0f, 0.0f, 0.0f,
				0.0f, scaleY, 0.0f, 0.0f,
				0.0f, 0.0f, scaleZ, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		// Vector3����X�P�[���s��𐶐�
		// ===============================
		const Matrix& KOMatrixScaling(Vector3 scale)noexcept
		{
			return ko::koMatrix::KOMatrixScaling(scale._x, scale._y, scale._z);
		}

		// ��]�s��𐶐�
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(float rotX, float rotY, float rotZ)noexcept
		{
			ko::Matrix result;

			// �s��̐ݒ�
			result._m11 = cosf(rotY) * cosf(rotZ);
			result._m12 = cosf(rotY) * sinf(rotZ);
			result._m13 = -sinf(rotY);
			result._m14 = 0.0f;

			result._m21 = sinf(rotX) * sinf(rotY) * cosf(rotZ) - cosf(rotX) * sinf(rotZ);
			result._m22 = sinf(rotX) * sinf(rotY) * sinf(rotZ) + cosf(rotX) * cosf(rotZ);
			result._m23 = sinf(rotX) * cosf(rotY);
			result._m24 = 0.0f;

			result._m31 = cosf(rotX) * sinf(rotY) * cosf(rotZ) + sinf(rotX) * sinf(rotZ);
			result._m32 = cosf(rotX) * sinf(rotY) * sinf(rotZ) - sinf(rotX) * cosf(rotZ);
			result._m33 = cosf(rotX) * cosf(rotY);
			result._m34 = 0.0f;

			result._m41 = 0.0f;
			result._m42 = 0.0f;
			result._m43 = 0.0f;
			result._m44 = 1.0f;

			return result;
		}

		// Vector3�����]�s��𐶐�
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(Vector3 rot)noexcept
		{
			return ko::koMatrix::KOMatrixYawPitchRoll(rot._x, rot._y, rot._z);
		}

		// �ړ��s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranslation(float offsetX, float offsetY, float offsetZ)noexcept
		{
			return Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, offsetX, offsetY, offsetZ, 1.0f);
		}

		// Vector3����ړ��s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranslation(Vector3 offset)noexcept
		{
			return ko::koMatrix::KOMatrixTranslation(offset._x, offset._y, offset._z);
		}

		// Matrix���m�̍s��̊|���Z���s��
		// ===============================
		const Matrix& KOMatrixMultiply(const Matrix& m1, const Matrix& m2)noexcept
		{
			Matrix m;

			m._m11 = m1._m11 * m2._m11 + m1._m12 * m2._m21 + m1._m13 * m2._m31 + m1._m14 * m2._m41;
			m._m12 = m1._m11 * m2._m12 + m1._m12 * m2._m22 + m1._m13 * m2._m32 + m1._m14 * m2._m42;
			m._m13 = m1._m11 * m2._m13 + m1._m12 * m2._m23 + m1._m13 * m2._m33 + m1._m14 * m2._m43;
			m._m14 = m1._m11 * m2._m14 + m1._m12 * m2._m24 + m1._m13 * m2._m34 + m1._m14 * m2._m44;

			m._m21 = m1._m21 * m2._m11 + m1._m22 * m2._m21 + m1._m23 * m2._m31 + m1._m24 * m2._m41;
			m._m22 = m1._m21 * m2._m12 + m1._m22 * m2._m22 + m1._m23 * m2._m32 + m1._m24 * m2._m42;
			m._m23 = m1._m21 * m2._m13 + m1._m22 * m2._m23 + m1._m23 * m2._m33 + m1._m24 * m2._m43;
			m._m24 = m1._m21 * m2._m14 + m1._m22 * m2._m24 + m1._m23 * m2._m34 + m1._m24 * m2._m44;

			m._m31 = m1._m31 * m2._m11 + m1._m32 * m2._m21 + m1._m33 * m2._m31 + m1._m34 * m2._m41;
			m._m32 = m1._m31 * m2._m12 + m1._m32 * m2._m22 + m1._m33 * m2._m32 + m1._m34 * m2._m42;
			m._m33 = m1._m31 * m2._m13 + m1._m32 * m2._m23 + m1._m33 * m2._m33 + m1._m34 * m2._m43;
			m._m34 = m1._m31 * m2._m14 + m1._m32 * m2._m24 + m1._m33 * m2._m34 + m1._m34 * m2._m44;

			m._m41 = m1._m41 * m2._m11 + m1._m42 * m2._m21 + m1._m43 * m2._m31 + m1._m44 * m2._m41;
			m._m42 = m1._m41 * m2._m12 + m1._m42 * m2._m22 + m1._m43 * m2._m32 + m1._m44 * m2._m42;
			m._m43 = m1._m41 * m2._m13 + m1._m42 * m2._m23 + m1._m43 * m2._m33 + m1._m44 * m2._m43;
			m._m44 = m1._m41 * m2._m14 + m1._m42 * m2._m24 + m1._m43 * m2._m34 + m1._m44 * m2._m44;

			//for (int y = 0; y < 4; ++y)
			//{
			//	float sum;
			//	for (int x = 0; x < 4; ++x)
			//	{
			//		sum += m1._mat[y][x] * m2._mat[x][y];
			//	}
			//}
			return m;
		}

		// KOVECTOR���王�_�̌����𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToLH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept
		{
			bool item = !ko::koVector::KOVector3Equal(eyeDirection, KOVECTOR::zero);
			KOAssert(item, "eyeDirection has become all 0.0f.", "CreateViewMatrix");
			if (!item)
			{
				return Matrix::allminus;
			}

			item = !ko::koVector::KOVector3Equal(upDirection, KOVECTOR::zero);
			KOAssert(item, "upDirection has become all 0.0f.", "CreateViewMatrix");
			if (!item)
			{
				return Matrix::allminus;
			}

			KOVECTOR R2 = ko::koVector::KOVector3Normalize(eyeDirection);

			KOVECTOR R0 = ko::koVector::KOVector3Cross(upDirection, R2);
			R0 = ko::koVector::KOVector3Normalize(R0);

			KOVECTOR R1 = ko::koVector::KOVector3Cross(R2, R0);

			KOVECTOR NegEyePosition = ko::koVector::KOVectorNegate(eyePosition);

			KOVECTOR D0 = ko::koVector::KOVector3Dot(R0, NegEyePosition);
			KOVECTOR D1 = ko::koVector::KOVector3Dot(R1, NegEyePosition);
			KOVECTOR D2 = ko::koVector::KOVector3Dot(R2, NegEyePosition);

			KOVECTOR tempSelect1110;
			tempSelect1110._vecInt[0] = 0xFFFFFFFF;
			tempSelect1110._vecInt[1] = 0xFFFFFFFF;
			tempSelect1110._vecInt[2] = 0xFFFFFFFF;
			tempSelect1110._vecInt[3] = 0;

			Matrix m;
			m._koVec[0] = ko::koVector::KOVectorSelect(D0, R0, tempSelect1110);
			m._koVec[1] = ko::koVector::KOVectorSelect(D1, R1, tempSelect1110);
			m._koVec[2] = ko::koVector::KOVectorSelect(D2, R2, tempSelect1110);
			m._koVec[3] = ko::koVector::KOVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

			m = KOMatrixTranspose(m);

			return m;
		}

		// Vector4���王�_�̌����𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToLH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept
		{
			KOVECTOR tempEyePosition;
			KOVECTOR tempEyeDirection;
			KOVECTOR tempUpDirection;
			tempEyePosition = eyePosition;
			tempEyeDirection = eyeDirection;
			tempUpDirection = upDirection;
			return ko::koMatrix::KOMatrixLookToLH(tempEyePosition, tempEyeDirection, tempUpDirection);
		}

		// KOVECTOR���璍���_�𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtLH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR eyeDirection = ko::koVector::KOVectorSubtract(focusPosition, eyePosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, eyeDirection, upDirection);
		}

		// Vector4���璍���_�𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtLH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept
		{
			Vector4 eyeDirection = ko::koVector::KOVectorSubtract(focusPosition, eyePosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, eyeDirection, upDirection);
		}

		// KOVECTOR���王�_�̌����𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToRH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR NegEyeDirection = ko::koVector::KOVectorNegate(eyeDirection);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, NegEyeDirection, upDirection);
		}

		// KOVECTOR���王�_�̌����𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToRH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept
		{
			KOVECTOR tempEyePosition;
			KOVECTOR tempEyeDirection;
			KOVECTOR tempUpDirection;
			tempEyePosition = eyePosition;
			tempEyeDirection = eyeDirection;
			tempUpDirection = upDirection;
			return ko::koMatrix::KOMatrixLookToRH(tempEyePosition, tempEyeDirection, tempUpDirection);
		}

		// KOVECTOR���璍���_�𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtRH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR NegEyeDirection = ko::koVector::KOVectorSubtract(eyePosition, focusPosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, NegEyeDirection, upDirection);
		}

		// Vector4���璍���_�𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtRH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept
		{
			KOVECTOR tempEyePosition;
			KOVECTOR tempFocusPosition;
			KOVECTOR tempUpDirection;
			tempEyePosition = eyePosition;
			tempFocusPosition = focusPosition;
			tempUpDirection = upDirection;
			return ko::koMatrix::KOMatrixLookAtRH(tempEyePosition, tempFocusPosition, tempUpDirection);
		}

		// �t�s��𐶐�
		// ===============================
		const Matrix& KOMatrixInverse(const Matrix& mat)noexcept
		{
			Matrix temp;

			for (int y = 0; y < 4; ++y)
			{
				for (int x = 0; x < 4; ++x)
				{
					if (mat._mat[y][x] != 0)
						temp._mat[y][x] = 1 / mat._mat[y][x];
				}
			}

			return temp;
		}

		// �������e�̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ)noexcept
		{
			float tanHalfFovY = tanf(fovAngleY * 0.5f);

			float scaleY = 1.0f / tanHalfFovY;
			float scaleX = scaleY / aspectRatio;

			float rangeInv = 1.0f / (farZ - nearZ);

			return Matrix(scaleX, 0.0f, 0.0f, 0.0f, 0.0f, scaleY, 0.0f, 0.0f, 0.0f, 0.0f, farZ * rangeInv, 1.0f, 0.0f, 0.0f, -nearZ * farZ * rangeInv, 0.0f);
		}

		// ���s���e�̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixOrthographicOffCenterLH(float viewLeft, float viewRight, float viewBottom, float viewTop, float nearZ, float farZ)noexcept
		{
			float invWidth = 1.0f / (viewRight - viewLeft);
			float invHeight = 1.0f / (viewTop - viewBottom);
			float invDepth = 1.0f / (farZ - nearZ);

			return Matrix(
				2.0f * invWidth, 0.0f, 0.0f, 0.0f,
				0.0f, 2.0f * invHeight, 0.0f, 0.0f,
				0.0f, 0.0f, invDepth, 0.0f,
				(viewLeft + viewRight) * -invWidth, (viewTop + viewBottom) * -invHeight, nearZ * -invDepth, 1.0f
			);
		}

		// ���s���e�̍s��𐶐�(Part2)
		// ===============================
		const Matrix& KOMatrixOrthographicLH(float viewWidth, float viewHeight, float nearZ, float farZ)noexcept
		{
			float invWidth = 1.0f / viewWidth;
			float invHeight = 1.0f / viewHeight;
			float invDepth = 1.0f / (farZ - nearZ);

			return Matrix(
				2.0f * invWidth, 0.0f, 0.0f, 0.0f,
				0.0f, 2.0f * invHeight, 0.0f, 0.0f,
				0.0f, 0.0f, invDepth, 0.0f,
				0.0f, 0.0f, -nearZ * invDepth, 1.0f
			);
		}

		// �]�u�s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranspose(const Matrix& mat)noexcept
		{
			Matrix m;

			for (int y = 0; y < 4; ++y)
			{
				for (int x = 0; x < 4; ++x)
				{
					m._mat[y][x] = mat._mat[x][y];
				}
			}

			return m;
		}
	}

	namespace koMath
	{
		// �e�v�f��min�`max�Ɏ��߂Ď擾
		// ===============================
		const Color& ColorClamp(const Color& color, const Color& min, const Color& max)noexcept
		{
			return ko::koMath::ColorMax(min, ko::koMath::ColorMin(color, max));
		}

		// �e�v�f�̏������l�̕��ŐF���擾
		// ���l��color1�̗v�f��ԋp
		// ===============================
		const Color& ColorMin(const Color& color1, const Color& color2)noexcept
		{
			Color temp = Color();
			color1._a <= color2._a ? (temp._a = color1._a) : (temp._a = color2._a);
			color1._g <= color2._g ? (temp._g = color1._g) : (temp._g = color2._g);
			color1._b <= color2._b ? (temp._b = color1._b) : (temp._b = color2._b);
			return temp;
		}

		// �e�v�f�̑傫���l�̕��ŐF���擾
		// ���l��color1�̗v�f��ԋp
		// ===============================
		const Color& ColorMax(const Color& color1, const Color& color2)noexcept
		{
			Color temp = Color();
			color1._a >= color2._a ? (temp._a = color1._a) : (temp._a = color2._a);
			color1._g >= color2._g ? (temp._g = color1._g) : (temp._g = color2._g);
			color1._b >= color2._b ? (temp._b = color1._b) : (temp._b = color2._b);
			return temp;
		}

		const float& DegToRad(const float& deg)noexcept
		{
			return deg * (PI / 180.0f);
		}

		const float& RadToDeg(const float& rad)noexcept
		{
			return rad / (PI / 180.0f);
		}

		const Vector3& ExtractRotationAnglesFromViewMatrix(const Matrix& viewMatrix) {
			
			Matrix view = viewMatrix;
			Vector3 resultRot = Vector3::zero;

			// �r���[�}�g���b�N�X������W�ƒ����_���擾
			KOVECTOR eye = koVector::KOVectorSet(view._m41, view._m42, view._m43, 1.0f);
			KOVECTOR focus = koVector::KOVectorSet(view._m31 + view._m41, view._m32 + view._m42, view._m33 + view._m43, 1.0f);

			// �r���[�}�g���b�N�X�̑O���x�N�g������Yaw�iY�����̉�]�p�j��Pitch�iX�����̉�]�p�j�����߂�
			KOVECTOR forward = koVector::KOVector3Normalize(focus - eye);
			resultRot._x = asinf(-koVector::KOVectorGetYF(forward));
			resultRot._y = atan2f(koVector::KOVectorGetXF(forward), koVector::KOVectorGetZF(forward));

			// �r���[�}�g���b�N�X�̉E�����x�N�g������Roll�iZ�����̉�]�p�j�����߂�
			KOVECTOR right = koVector::KOVector3Cross(koVector::KOVectorSet(0.0f, 1.0f, 0.0f, 0.0f), forward);
			right = koVector::KOVector3Normalize(right);
			resultRot._z = atan2f(koVector::KOVectorGetYF(right), koVector::KOVectorGetXF(right));

			return resultRot;
		}
	}
}