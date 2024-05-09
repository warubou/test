// ------------------------------------------------------------------------------------------------
// koMath.h								�I���W�i���x�N�g���v�Z���w�֐�
// Date 2023/12/27
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef KO_MATH_H_
#define KO_MATH_H_

#include "../vector.h"

namespace ko
{
	static constexpr float PI = 3.14159265358979323846f;
	static constexpr float PI2 = PI * PI;

	namespace vector2
	{
		// Vector2����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector2& vec)noexcept;
		// Vector2��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2����float�^�̒������擾
		// ===============================
		const float& Length(const Vector2& vec)noexcept;
		// Vector2��2�_�Ԃ̒������v�Z
		// ===============================
		const float& Length(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector2& vec)noexcept;
		// Vector3���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector3& vec)noexcept;
		// Vector4���琳�K������Vector2�^���擾
		// ===============================
		const Vector2& Normalize(const Vector4& vec)noexcept;
		// Vector2����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2����float�^�̊O�ς��擾
		// ===============================
		const float& Cross(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2����Vector2���m�̍������擾(Vector2�^)
		// ===============================
		const Vector2& Subtract(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2�Ԃ���`�⊮���ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector2& vec1, const Vector2& vec2, float t)noexcept;
	}

	namespace vector3
	{
		// Vector3����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector3& vec)noexcept;
		// Vector3��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3����float�^�̒������擾
		// ===============================
		const float& Length(const Vector3& vec)noexcept;
		// Vector3��2�_�Ԃ̒������擾
		// ===============================
		const float& Length(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3���琳�K������Vector3�^���擾
		// ===============================
		const Vector3& Normalize(const Vector3& vec)noexcept;
		// Vector4���琳�K������Vector3�^���擾
		// ===============================
		const Vector3& Normalize(const Vector4& vec)noexcept;
		// Vector3����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3����Vector3�^�̊O�ς��擾
		// ===============================
		const Vector3& Cross(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3����Vector3���m�̍������擾(Vector3�^)
		// ===============================
		const Vector3& Subtract(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3�Ԃ���`�⊮����Vector2�^�Ƃ��ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept;
		// Vector3�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector3& Vec3Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept;
	}

	namespace vector4
	{
		// Vector4����float�^�̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector4& vec)noexcept;
		// Vector4��2�_�Ԃ̒�����2����擾
		// ===============================
		const float& LengthSq(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4����float�^�̒������擾
		// ===============================
		const float& Length(const Vector4& vec)noexcept;
		// Vector4��2�_�Ԃ̒������擾
		// ===============================
		const float& Length(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4���琳�K������Vector4�^���擾
		// ===============================
		const Vector4& Normalize(const Vector4& vec)noexcept;
		// Vector4����float�^�̓��ς��擾
		// ===============================
		const float& Dot(const Vector4& vec1, const Vector4 vec2)noexcept;
		// Vector4����Vector4�^�̊O�ς��擾
		// ������
		// ===============================
		const Vector4& Cross(const Vector4& vec1, const Vector4 vec2)noexcept;
		// Vector4����Vector4���m�̍������擾(Vector4�^)
		// ===============================
		const Vector4& Subtract(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector2& Vec2Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector3& Vec3Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
		// Vector4�Ԃ���`�⊮����Vector3�^�Ƃ��ĕԋp
		// ===============================
		const Vector4& Vec4Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
	}

	namespace color
	{
		// ��{�I�ȃO���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScale(const Color& color)noexcept;
		// R����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleR(const Color& color)noexcept;
		// G����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleG(const Color& color)noexcept;
		// B����Ƃ����O���[�X�P�[���̐F���擾
		// ===============================
		const Color& KOColorGrayScaleB(const Color& color)noexcept;
		// R,G,B�����ꂼ�ꔽ�]�����F���擾
		// ===============================
		const Color& KOColorNegapoji(const Color& color)noexcept;
		// �Z�s�A���̐F���擾
		// ===============================
		const Color& KOColorSepia(const Color& color)noexcept;
		// ���m�N�����̐F���擾
		// ===============================
		const Color& KOColorMonocrome(const Color& color)noexcept;
		// R�̒l�̂ݎ擾
		// ===============================
		const Color& KOColorRScale(const Color& color)noexcept;
		// G�̒l�̂ݎ擾
		// ===============================
		const Color& KOColorGScale(const Color& color)noexcept;
		// B�̒l�̂ݎ擾
		// ===============================
		const Color& KOCOlorBScale(const Color& color)noexcept;
		// 0.0f�`1.0f�̒l�Ɏ��߂Ď擾
		// ===============================
		const Color& KOColorSaturate(const Color& color)noexcept;
	}

	namespace koVector
	{
		// KOVECTOR��Ԃ�l�Ɉ������Z�b�g
		// ===============================
		const KOVECTOR& KOVectorSet(const float& X, const float& Y, const float& Z, const float& W)noexcept;
		// KOVECTOR����_xFloat,_yFloat���擾��float�^�Œ������擾
		// ===============================
		const float& KOVector2Length(const KOVECTOR& vec)noexcept;
		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��float�^�Œ������擾
		// ===============================
		const float& KOVector3Length(const KOVECTOR& vec)noexcept;
		// KOVECTOR����l�S�Ă��擾��float�^�Œ������擾
		// ===============================
		const float& KOVector4Length(const KOVECTOR& vec)noexcept;
		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector2Normalize(const KOVECTOR& vec)noexcept;
		// KOVECTOR����_xFloat,_yFloat, _zFloat���擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector3Normalize(const KOVECTOR& vec)noexcept;
		// KOVECTOR����l�S�Ă��擾��KOVECTOR�^�Ő��K�����擾
		// ===============================
		const KOVECTOR& KOVector4Normalize(const KOVECTOR& vec)noexcept;
		// 2�l��KOVECTOR����vec1����vec2��������������KOVECTOR�^�Ŏ擾
		// ===============================
		const KOVECTOR& KOVectorSubtract(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�œ��ς��擾
		// �S�l�͑S�ē����ɂȂ�
		// ===============================
		const KOVECTOR& KOVector2Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��KOVECTOR�^�œ��ς��擾
		// �S�l�͑S�ē����ɂȂ�
		// ===============================
		const KOVECTOR& KOVector3Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����S�Ă̒l���擾��KOVECTOR�^�œ��ς��擾
		// �S�l�͑S�ē����ɂȂ�
		// ===============================
		const KOVECTOR& KOVector4Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����_xFloat,_yFloat���擾��KOVECTOR�^�ŊO�ς��擾
		// �S�l�͑S�ē����ɂȂ�
		// ===============================
		const KOVECTOR& KOVector2Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����_xFloat,_yFloat,_zFloat���擾��KOVECTOR�^�ŊO�ς��擾
		// ===============================
		const KOVECTOR& KOVector3Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTOR����S�l���擾��KOVECTOR�^�ŊO�ς��擾
		// ===============================
		const KOVECTOR& KOVector4Cross(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& vec3)noexcept;
		// KOVECTOR����X������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetXF(const KOVECTOR& vec)noexcept;
		// KOVECTOR����Y������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetYF(const KOVECTOR& vec)noexcept;
		// KOVECTOR����Z������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetZF(const KOVECTOR& vec)noexcept;
		// KOVECTOR����Z������float�^�Ŏ擾
		// ===============================
		const float& KOVectorGetWF(const KOVECTOR& vec)noexcept;
		// KOVECTOR����ے���v�Z(DirectX::XMVectorNegate()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorNegate(const KOVECTOR& vec)noexcept;
		// Vector4����ے���v�Z(DirectX::XMVectorNegate()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorNegate(const Vector4& vec)noexcept;
		// �܂��Ƃ肠�����������֐�(DirectX::XMVectorSelect()�ɏ���)
		// ===============================
		const KOVECTOR& KOVectorSelect(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& controllVec)noexcept;
		// �S�v�f�������������o
		// ===============================
		const bool& KOVector4Equal(KOVECTOR& vec1, KOVECTOR& vec2)noexcept;
		// 3�v�f�������������o
		// ===============================
		const bool& KOVector3Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;

		// Vector3�^����Vector3�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector3& KOVector3Normalize(const Vector3& vec)noexcept;
		// Vector4�^����Vector3�^�̐��K���x�N�g�����擾
		// _w�͖���
		// ===============================
		const Vector3& KOVector3Normalize(const Vector4& vec)noexcept;
		// Vector4�^����Vector4�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector4& KOVector4Normalize(const Vector4& vec)noexcept;
		// Vector3�^����Vector4�^�̐��K���x�N�g�����擾
		// ===============================
		const Vector4& KOVector4Normalize(const Vector3& vec)noexcept;
		// Vector4���m�̍�����vector4�^�Ŏ擾
		// ===============================
		const Vector4& KOVectorSubtract(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4���m�̍�����Vector3�^�Ŏ擾
		// ===============================
		const Vector3& KOVectorSubtractVec3(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector3���m��Vector3�̓��ς��擾
		// ===============================
		const Vector3& KOVector3Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector4���m��Vector3�̓��ς��擾
		// _w�͖���
		// ===============================
		const Vector3& KOVector3Dot(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4���m��Vector4�̓��ς��擾
		// ===============================
		const Vector4& KOVector4Dot(const Vector4& vec1, const Vector4& vec2)noexcept;
		// vector3���m��vector4�̓��ς��擾
		// _w��0.0f�Œ�
		// ===============================
		const Vector4& KOVector4Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3���m��Vector3�̊O�ς��擾
		// ===============================
		const Vector3& KOVector3Cross(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector4���m��Vector3�̊O�ς��擾
		// _w�͖���
		// ===============================
		const Vector3& KOVector3Cross(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4�^3��Vector4�^�̊O�ς��擾
		// ===============================
		const Vector4& KOVector4Cross(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3)noexcept;
		// Vector3�^3��Vector4�^�̊O�ς��擾
		// ===============================
		const Vector4& KOVector4Cross(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3)noexcept;
		// 3�v�f�������������o
		// ===============================
		const bool& KOVector3Equal(Vector4& vec1, Vector4& vec2)noexcept;
		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(Vector4& vec1, Vector4& vec2)noexcept;
		// 2�v�f�������������o
		// ===============================
		const bool& KOVector2Equal(Vector3& vec1, Vector3& vec2)noexcept;
	}

	namespace koMatrix
	{
		// �P�ʍs��𐶐�
		// ===============================
		const Matrix& KOMatrixIdentity(void)noexcept;
		// �X�P�[���̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixScaling(float scaleX, float scaleY, float scaleZ)noexcept;
		// Vector3����X�P�[���s��𐶐�
		// ===============================
		const Matrix& KOMatrixScaling(Vector3 scale)noexcept;
		// ��]�s��𐶐�
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(float rotX, float rotY, float rotZ)noexcept;
		// Vector3�����]�s��𐶐�
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(Vector3 rot)noexcept;
		// �ړ��s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranslation(float offsetX, float offsetY, float offsetZ)noexcept;
		// Vector3����ړ��s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranslation(Vector3 offset)noexcept;
		// Matrix���m�̍s��̊|���Z���s��
		// ===============================
		const Matrix& KOMatrixMultiply(const Matrix& m1, const Matrix& m2)noexcept;
		// KOVECTOR���王�_�̌����𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToLH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept;
		// Vector4���王�_�̌����𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToLH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept;
		// KOVECTOR���璍���_�𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtLH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept;
		// Vector4���璍���_�𗘗p����������W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtLH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept;
		// KOVECTOR���王�_�̌����𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToRH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept;
		// KOVECTOR���王�_�̌����𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookToRH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept;
		// KOVECTOR���璍���_�𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtRH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept;
		// Vector4���璍���_�𗘗p�����E����W�n�r���[�s��𐶐�
		// ===============================
		const Matrix& KOMatrixLookAtRH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept;
		// �t�s��𐶐�
		// ===============================
		const Matrix& KOMatrixInverse(const Matrix& mat)noexcept;
		// �������e�̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ)noexcept;
		// ���s���e�̍s��𐶐�
		// ===============================
		const Matrix& KOMatrixOrthographicOffCenterLH(float viewLeft, float viewRight, float viewBottom, float viewTop, float nearZ, float farZ)noexcept;
		// ���s���e�̍s��𐶐�(Part2)
		// ===============================
		const Matrix& KOMatrixOrthographicLH(float viewWidth, float viewHeight, float nearZ, float farZ)noexcept;
		// �]�u�s��𐶐�
		// ===============================
		const Matrix& KOMatrixTranspose(const Matrix& mat)noexcept;
	}

	namespace koMath
	{
		// �������ق���ԋp�B���l��value1��ԋp
		// ===============================
		template<class T>
		const T& Min(const T& value1, const T& value2)noexcept
		{
			return (value1 <= value2) ? value1 : value2;
		}

		// �傫���ق���ԋp�B���l��value1��ԋp
		// ===============================
		template<class T>
		const T& Max(const T& value1, const T& value2)noexcept
		{
			return (value1 >= value2) ? value1 : value2;
		}

		// min,max�͈͓̔��ɒ������ĕԋp
		// ===============================
		template<class T>
		const T& Clamp(const T& value, const T& min, const T& max)noexcept
		{
			return Max(min, Min(value, max));
		}

		// �ݏ���v�Z���ĕԋp
		// ===============================
		template<class T>
		const T& Pow(const T& value, const int& count)noexcept
		{
			if (count == 0) {
				return 1.0;
			}
			else if (count > 0) {
				return value * Pow(value, count - 1);
			}
			else {
				// ���̎w���̏ꍇ
				return 1.0 / (value * Pow(value, -count - 1));
			}
		}

		// ��Βl���v�Z
		// ===============================
		template<class T>
		const T& Abs(const T& value)
		{
			if (value == 0)
				return value;

			return value > 0 ? value : -value;
		}

		// 2�l�Ԃ���`�⊮���ĕԋp
		// ===============================
		template<class T>
		const T& SingleLerp(const T& start, const T& end, const T& t)
		{
			return start + t * (end - start);
		}

		// �e�v�f��min�`max�Ɏ��߂Ď擾
		// ===============================
		const Color& ColorClamp(const Color& color, const Color& min, const Color& max)noexcept;
		// �e�v�f�̏������l�̕��ŐF���擾
		// ���l��color1�̗v�f��ԋp
		// ===============================
		const Color& ColorMin(const Color& color1, const Color& color2)noexcept;
		// �e�v�f�̑傫���l�̕��ŐF���擾
		// ���l��color1�̗v�f��ԋp
		// ===============================
		const Color& ColorMax(const Color& color1, const Color& color2)noexcept;

		/// �p�x��Degree�P�ʂ���Radian�P�ʂɕϊ�����B
		// ===============================
		const float& DegToRad(const float& deg)noexcept;

		/// �p�x��Radian�P�ʂ���Degree�P�ʂɕϊ�����B
		// ===============================
		const float& RadToDeg(const float& rad)noexcept;
		
		// viewMatrix����J�����̉�]�p�����߂�
		// ===============================
		const Vector3& ExtractRotationAnglesFromViewMatrix(const Matrix& viewMatrix);
	}
}

#endif // KO_MATH_H_