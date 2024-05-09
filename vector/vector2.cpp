// ------------------------------------------------------------------------------------------------
// vector2.cpp								�I���W�i���x�N�g��(Vector2)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTOR�ɂ��Ă͑S��float�^���Q�Ƃ���
// ------------------------------------------------------------------------------------------------
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "koVector.h"

namespace ko
{
	// =====================================
	// Vector2
	// =====================================

	// �R���X�g���N�^
	// =====================================
	Vector2::Vector2(const Vector3& v) :_x(v._x), _y(v._y) {}
	Vector2::Vector2(const Vector4& v) :_x(v._x), _y(v._y) {}
	Vector2::Vector2(const KOVECTOR& v) :_x(v._xFloat), _y(v._yFloat) {}

	// �ÓI�ϐ��̏�����
	// =====================================
	// Vector2�̒l�S��0.0f�𐶐�
	// ===============================
	const Vector2 Vector2::zero(0.0f, 0.0f);
	// Vector2�̒l�S��1.0f�𐶐�
	// ===============================
	const Vector2 Vector2::one(1.0f, 1.0f);
	// _y =  1.0f��Vector2�𐶐�
	// ===============================
	const Vector2 Vector2::up(0.0f, 1.0f);
	// _y = -1.0f��Vector2�𐶐�
	// ===============================
	const Vector2 Vector2::down(0.0f, -1.0f);
	// _x =  1.0f��Vector2�𐶐�
	// ===============================
	const Vector2 Vector2::right(1.0f, 0.0f);
	// _x = -1.0f��Vector2�𐶐�
	// ===============================
	const Vector2 Vector2::left(-1.0f, 0.0f);

	// +Vector2
	// ===============================
	Vector2 Vector2::operator+ (void)const
	{
		return *this;
	}

	// -Vector2
	// ===============================
	Vector2 Vector2::operator- (void)const
	{
		return Vector2(-_x, -_y);
	}

	// Vector2 + Vector2
	// ===============================
	Vector2 Vector2::operator+ (const Vector2& vec)const
	{
		return Vector2(_x + vec._x, _y + vec._y);
	}

	// Vector2 - Vector2
	// ===============================
	Vector2 Vector2::operator- (const Vector2& vec)const
	{
		return Vector2(_x - vec._x, _y - vec._y);
	}

	// Vector2 * Vector2
	// ===============================
	Vector2 Vector2::operator* (const Vector2& vec)const
	{
		return Vector2(_x * vec._x, _y * vec._y);
	}

	// Vector2 / Vector2
	// ===============================
	Vector2 Vector2::operator/ (const Vector2& vec)const
	{
		return Vector2(_x / vec._x, _y / vec._y);
	}

	// Vector2 + float
	// ===============================
	Vector2 Vector2::operator+ (const float& t)const
	{
		return Vector2(_x + t, _y + t);
	}

	// Vector2 - float
	// ===============================
	Vector2 Vector2::operator- (const float& t)const
	{
		return Vector2(_x - t, _y - t);
	}

	// Vector2 * float
	// ===============================
	Vector2 Vector2::operator* (const float& t)const
	{
		return Vector2(_x * t, _y * t);
	}
	// Vector2 / float
	// ===============================
	Vector2 Vector2::operator/ (const float& t)const
	{
		return Vector2(_x / t, _y / t);
	}

	// Vector2 + Vector3
	// ===============================
	Vector2 Vector2::operator+ (const Vector3& vec)const
	{
		return Vector2(_x + vec._x, _y + vec._y);
	}

	// Vector2 - Vector3
	// ===============================
	Vector2 Vector2::operator- (const Vector3& vec)const
	{
		return Vector2(_x - vec._x, _y - vec._y);
	}

	// Vector2 * Vector3
	// ===============================
	Vector2 Vector2::operator* (const Vector3& vec)const
	{
		return Vector2(_x * vec._x, _y * vec._y);
	}

	// Vector2 / Vector3
	// ===============================
	Vector2 Vector2::operator/ (const Vector3& vec)const
	{
		return Vector2(_x / vec._x, _y / vec._y);
	}

	// Vector2 + Vector4
	// ===============================
	Vector2 Vector2::operator+ (const Vector4& vec)const
	{
		return Vector2(_x + vec._x, _y + vec._y);
	}

	// Vector2 - Vector4
	// ===============================
	Vector2 Vector2::operator- (const Vector4& vec)const
	{
		return Vector2(_x - vec._x, _y - vec._y);
	}

	// Vector2 * Vector4
	// ===============================
	Vector2 Vector2::operator* (const Vector4& vec)const
	{
		return Vector2(_x * vec._x, _y * vec._y);
	}

	// Vector2 / Vector4
	// ===============================
	Vector2 Vector2::operator/ (const Vector4& vec)const
	{
		return Vector2(_x / vec._x, _y / vec._y);
	}

	// Vector2 + KOVECTOR
	// ===============================
	Vector2 Vector2::operator+ (const KOVECTOR& vec)const
	{
		return Vector2(_x + vec._xFloat, _y + vec._yFloat);
	}

	// Vector2 - KOVECTOR
	// ===============================
	Vector2 Vector2::operator- (const KOVECTOR& vec)const
	{
		return Vector2(_x - vec._xFloat, _y - vec._yFloat);
	}

	// Vector2 * KOVECTOR
	// ===============================
	Vector2 Vector2::operator* (const KOVECTOR& vec)const
	{
		return Vector2(_x * vec._xFloat, _y * vec._yFloat);
	}

	// Vector2 / KOVECTOR
	// ===============================
	Vector2 Vector2::operator/ (const KOVECTOR& vec)const
	{
		return Vector2(_x / vec._xFloat, _y / vec._yFloat);
	}

	// Vector2 += Vector2
	// ===============================
	Vector2& Vector2::operator+= (const Vector2& vec)
	{
		_x += vec._x;
		_y += vec._y;
		return *this;
	}

	// Vector2 -= Vector2
	// ===============================
	Vector2& Vector2::operator-= (const Vector2& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		return *this;
	}

	// Vector2 *= Vector2
	// ===============================
	Vector2& Vector2::operator*= (const Vector2& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		return *this;
	}

	// Vector2 /= Vector2
	// ===============================
	Vector2& Vector2::operator/= (const Vector2& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		return *this;
	}

	// Vector2 += float
	// ===============================
	Vector2& Vector2::operator+= (const float& t)
	{
		_x += t;
		_y += t;
		return *this;
	}

	// Vector2 -= float
	// ===============================
	Vector2& Vector2::operator-= (const float& t)
	{
		_x -= t;
		_y -= t;
		return *this;
	}

	// Vector2 *= float
	// ===============================
	Vector2& Vector2::operator*= (const float& t)
	{
		_x *= t;
		_y *= t;
		return *this;
	}

	// Vector2 /= float
	// ===============================
	Vector2& Vector2::operator/= (const float& t)
	{
		_x /= t;
		_y /= t;
		return *this;
	}

	// Vector2 += Vector3
	// ===============================
	Vector2& Vector2::operator+= (const Vector3& vec)
	{
		_x += vec._x;
		_y += vec._y;
		return *this;
	}

	// Vector2 -= Vector3
	// ===============================
	Vector2& Vector2::operator-= (const Vector3& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		return *this;
	}

	// Vector2 *= Vector3
	// ===============================
	Vector2& Vector2::operator*= (const Vector3& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		return *this;
	}

	// Vector2 /= Vector3
	// ===============================
	Vector2& Vector2::operator/= (const Vector3& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		return *this;
	}

	// Vector2 += Vector4
	// ===============================
	Vector2& Vector2::operator+= (const Vector4& vec)
	{
		_x += vec._x;
		_y += vec._y;
		return *this;
	}

	// Vector2 -= Vector4
	// ===============================
	Vector2& Vector2::operator-= (const Vector4& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		return *this;
	}

	// Vector2 *= Vector4
	// ===============================
	Vector2& Vector2::operator*= (const Vector4& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		return *this;
	}

	// Vector2 /= Vector4
	// ===============================
	Vector2& Vector2::operator/= (const Vector4& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		return *this;
	}

	// Vector2 += KOVECTOR
	// ===============================
	Vector2& Vector2::operator+= (const KOVECTOR& vec)
	{
		_x += vec._xFloat;
		_y += vec._yFloat;
		return *this;
	}

	// Vector2 -= KOVECTOR
	// ===============================
	Vector2& Vector2::operator-= (const KOVECTOR& vec)
	{
		_x -= vec._xFloat;
		_y -= vec._yFloat;
		return *this;
	}

	// Vector2 *= KOVECTOR
	// ===============================
	Vector2& Vector2::operator*= (const KOVECTOR& vec)
	{
		_x *= vec._xFloat;
		_y *= vec._yFloat;
		return *this;
	}

	// Vector2 /= KOVECTOR
	// ===============================
	Vector2& Vector2::operator/= (const KOVECTOR& vec)
	{
		_x /= vec._xFloat;
		_y /= vec._yFloat;
		return *this;
	}

	// if(Vector2 == Vector2)
	// ===============================
	bool Vector2::operator== (const Vector2& vec)const
	{
		return (_x == vec._x && _y == vec._y);
	}

	// if(Vector2 != Vector2)
	// ===============================
	bool Vector2::operator!= (const Vector2& vec)const
	{
		return (_x != vec._x && _y != vec._y);
	}

	// if(Vector2 == Vector3)
	// ===============================
	bool Vector2::operator== (const Vector3& vec)const
	{
		return (_x == vec._x && _y == vec._y);
	}

	// if(Vector2 != Vector3)
	// ===============================
	bool Vector2::operator!= (const Vector3& vec)const
	{
		return (_x != vec._x && _y != vec._y);
	}

	// if(Vector2 == Vector4)
	// ===============================
	bool Vector2::operator== (const Vector4& vec)const
	{
		return (_x == vec._x && _y == vec._y);
	}
	
	// if(Vector2 != Vector4)
	// ===============================
	bool Vector2::operator!= (const Vector4& vec)const
	{
		return (_x != vec._x && _y != vec._y);
	}
	
	// if(Vector2 == KOVECTOR)
	// ===============================
	bool Vector2::operator== (const KOVECTOR& vec)const
	{
		return (_x == vec._xFloat && _y == vec._yFloat);
	}
	
	// if(Vector2 != KOVECTOR)
	// ===============================
	bool Vector2::operator!= (const KOVECTOR& vec)const
	{
		return (_x != vec._xFloat && _y != vec._yFloat);
	}

	// Vector2 = Vector3
	// ===============================
	Vector2& Vector2::operator= (const Vector3& vec)
	{
		_x = vec._x;
		_y = vec._y;
		return *this;
	}

	// Vector2 = Vector4
	// ===============================
	Vector2& Vector2::operator= (const Vector4& vec)
	{
		_x = vec._x;
		_y = vec._y;
		return *this;
	}

	// Vector2 = KOVECTOR
	// ===============================
	Vector2& Vector2::operator= (const KOVECTOR& vec)
	{
		_x = vec._xFloat;
		_y = vec._yFloat;
		return *this;
	}
}