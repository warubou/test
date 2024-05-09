// ------------------------------------------------------------------------------------------------
// vector4.cpp								�I���W�i���x�N�g��(Vector4)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTOR�ɂ��Ă͑S��float�^���Q�Ƃ���
// ------------------------------------------------------------------------------------------------
#include "vector4.h"
#include "vector2.h"
#include "vector3.h"
#include "koVector.h"

namespace ko
{
	// =====================================
	// Vector4
	// =====================================

	// �R���X�g���N�^
	// =====================================
	Vector4::Vector4(const Vector2& v) :_x(v._x), _y(v._y), _z(0.0f), _w(0.0f) {}
	Vector4::Vector4(const Vector2& v1, const Vector2& v2) : _x(v1._x), _y(v1._y), _z(v2._x), _w(v2._y) {}
	Vector4::Vector4(const Vector2& v, const float& t1, const float& t2) : _x(v._x), _y(v._y), _z(t1), _w(t2) {}
	Vector4::Vector4(const Vector3& v) :_x(v._x), _y(v._y), _z(v._z), _w(0.0f) {}
	Vector4::Vector4(const Vector3& v, const float& t) : _x(v._x), _y(v._y), _z(v._z), _w(t) {}
	Vector4::Vector4(const KOVECTOR& v) :_x(v._xFloat), _y(v._yFloat), _z(v._zFloat), _w(v._wFloat) {}

	// �ÓI�ϐ��̏�����
	// =====================================
	// Vector4�̒l�S��1.0f�𐶐�
	// ===============================
	const Vector4 Vector4::zero(0.0f, 0.0f, 0.0f, 0.0f);
	// Vector4�̒l�S��1.0f�𐶐�
	// ===============================
	const Vector4 Vector4::one(1.0f, 1.0f, 1.0f, 1.0f);
	// _y =  1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::up(0.0f, 1.0f, 0.0f, 0.0f);
	// _y = -1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::down(0.0f, -1.0f, 0.0f, 0.0f);
	// _x =  1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::right(1.0f, 0.0f, 0.0f, 0.0f);
	// _x = -1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::left(-1.0f, 0.0f, 0.0f, 0.0f);
	// _z =  1.0f��Vector4�𐶐�(������W�n)
	// ===============================
	const Vector4 Vector4::frontLH(0.0f, 0.0f,-1.0f, 0.0f);
	// _z = -1.0f��Vector4�𐶐�(������W�n)
	// ===============================
	const Vector4 Vector4::backLH(0.0f, 0.0f,  1.0f, 0.0f);
	// _z = -1.0f��Vector4�𐶐�(�E����W�n)
	// ===============================
	const Vector4 Vector4::frontRH(0.0f, 0.0f, 1.0f, 0.0f);
	// _z =  1.0f��Vector4�𐶐�(�E����W�n)
	// ===============================
	const Vector4 Vector4::backRH(0.0f, 0.0f, -1.0f, 0.0f);
	// _w =  1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::plusW(0.0f, 0.0f, 0.0f, 1.0f);
	// _w = -1.0f��Vector4�𐶐�
	// ===============================
	const Vector4 Vector4::minusW(0.0f, 0.0f, 0.0f, -1.0f);

	// +Vector4
	// ===============================
	Vector4 Vector4::operator+ (void)const
	{
		return *this;
	}

	// -Vector4
	// ===============================
	Vector4 Vector4::operator- (void)const
	{
		return Vector4(-_x, -_y, -_z, -_w);
	}

	// Vector4 + Vector4
	// ===============================
	Vector4 Vector4::operator+(const Vector4& vec)const
	{
		return Vector4(_x + vec._x, _y + vec._y, _z + vec._z, _w + vec._w);
	}

	// Vector4 - Vector4
	// ===============================
	Vector4 Vector4::operator- (const Vector4& vec)const
	{
		return Vector4(_x - vec._x, _y - vec._y, _z - vec._z, _w - vec._w);
	}

	// Vector4 * Vector4
	// ===============================
	Vector4 Vector4::operator* (const Vector4& vec)const
	{
		return Vector4(_x * vec._x, _y * vec._y, _z * vec._z, _w * vec._w);
	}

	// Vector4 / Vector4
	// ===============================
	Vector4 Vector4::operator/ (const Vector4& vec)const
	{
		return Vector4(_x / vec._x, _y / vec._y, _z / vec._z, _w / vec._w);
	}

	// Vector4 + float
	// ===============================
	Vector4 Vector4::operator+ (const float& t)const
	{
		return Vector4(_x + t, _y + t, _z + t, _w + t);
	}

	// Vector4 - float
	// ===============================
	Vector4 Vector4::operator- (const float& t)const
	{
		return Vector4(_x - t, _y - t, _z - t, _w - t);
	}

	// Vector4 * float
	// ===============================
	Vector4 Vector4::operator* (const float& t)const
	{
		return Vector4(_x * t, _y * t, _z * t, _w * t);
	}

	// Vector4 / float
	// ===============================
	Vector4 Vector4::operator/ (const float& t)const
	{
		return Vector4(_x / t, _y / t, _z / t, _w / t);
	}

	// Vector4 + Vector2
	// ===============================
	Vector4 Vector4::operator+ (const Vector2& vec)const
	{
		return Vector4(_x + vec._x, _y + vec._y, _z, _w);
	}

	// Vector4 - Vector2
	// ===============================
	Vector4 Vector4::operator- (const Vector2& vec)const
	{
		return Vector4(_x - vec._x, _y - vec._y, _z, _w);
	}

	// Vector4 * Vector2
	// ===============================
	Vector4 Vector4::operator* (const Vector2& vec)const
	{
		return Vector4(_x * vec._x, _y * vec._y, _z, _w);
	}

	// Vector4 / Vector2
	// ===============================
	Vector4 Vector4::operator/ (const Vector2& vec)const
	{
		return Vector4(_x / vec._x, _y / vec._y, _z, _w);
	}

	// Vector4 + Vector3
	// ===============================
	Vector4 Vector4::operator+ (const Vector3& vec)const
	{
		return Vector4(_x + vec._x, _y + vec._y, _z + vec._z, _w);
	}

	// Vector4 - Vector3
	// ===============================
	Vector4 Vector4::operator- (const Vector3& vec)const
	{
		return Vector4(_x - vec._x, _y - vec._y, _z - vec._z, _w);
	}

	// Vector4 * Vector3
	// ===============================
	Vector4 Vector4::operator* (const Vector3& vec)const
	{
		return Vector4(_x * vec._x, _y * vec._y, _z * vec._z, _w);
	}

	// Vector4 / Vector3
	// ===============================
	Vector4 Vector4::operator/ (const Vector3& vec)const
	{
		return Vector4(_x / vec._x, _y / vec._y, _z / vec._z, _w);
	}

	// Vector4 + KOVECTOR
	// ===============================
	Vector4 Vector4::operator+ (const KOVECTOR& vec)const
	{
		return Vector4(_x + vec._xFloat, _y + vec._yFloat, _z + vec._zFloat, _w + vec._wFloat);
	}

	// Vector4 - KOVECTOR
	// ===============================
	Vector4 Vector4::operator- (const KOVECTOR& vec)const
	{
		return Vector4(_x - vec._xFloat, _y - vec._yFloat, _z - vec._zFloat, _w - vec._wFloat);
	}

	// Vector4 * KOVECTOR
	// ===============================
	Vector4 Vector4::operator* (const KOVECTOR& vec)const
	{
		return Vector4(_x * vec._xFloat, _y * vec._yFloat, _z * vec._zFloat, _w * vec._wFloat);
	}

	// Vector4 / KOVECTOR
	// ===============================
	Vector4 Vector4::operator/ (const KOVECTOR& vec)const
	{
		return Vector4(_x / vec._xFloat, _y / vec._yFloat, _z /vec._zFloat, _w / vec._wFloat);
	}

	// Vector4 += Vector4
	// ===============================
	Vector4& Vector4::operator+= (const Vector4& vec)
	{
		_x += vec._x;
		_y += vec._y;
		_z += vec._z;
		_w += vec._w;
		return *this;
	}

	// Vector4 -= Vector4
	// ===============================
	Vector4& Vector4::operator-= (const Vector4& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		_z -= vec._z;
		_w -= vec._w;
		return *this;
	}

	// Vector4 *= Vector4
	// ===============================
	Vector4& Vector4::operator*= (const Vector4& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		_z *= vec._z;
		_w *= vec._w;
		return *this;
	}

	// Vector4 /= Vector4
	// ===============================
	Vector4& Vector4::operator/= (const Vector4& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		_z /= vec._z;
		_w /= vec._w;
		return *this;
	}

	// Vector4 += float
	// ===============================
	Vector4& Vector4::operator+= (const float& t)
	{
		_x += t;
		_y += t;
		_z += t;
		_w += t;
		return *this;
	}

	// Vector4 -= float
	// ===============================
	Vector4& Vector4::operator-= (const float& t)
	{
		_x -= t;
		_y -= t;
		_z -= t;
		_w -= t;
		return *this;
	}

	// Vector4 *= float
	// ===============================
	Vector4& Vector4::operator*= (const float& t)
	{
		_x *= t;
		_y *= t;
		_z *= t;
		_w *= t;
		return *this;
	}

	// Vector4 /= float
	// ===============================
	Vector4& Vector4::operator/= (const float& t)
	{
		_x /= t;
		_y /= t;
		_z /= t;
		_w /= t;
		return *this;
	}

	// Vector4 += Vector2
	// ===============================
	Vector4& Vector4::operator+= (const Vector2& vec)
	{
		_x += vec._x;
		_y += vec._y;
		return *this;
	}

	// Vector4 -= Vector2
	// ===============================
	Vector4& Vector4::operator-= (const Vector2& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		return *this;
	}

	// Vector4 *= Vector2
	// ===============================
	Vector4& Vector4::operator*= (const Vector2& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		return *this;
	}

	// Vector4 /= Vector2
	// ===============================
	Vector4& Vector4::operator/= (const Vector2& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		return *this;
	}

	// Vector4 += Vector3
	// ===============================
	Vector4& Vector4::operator+= (const Vector3& vec)
	{
		_x += vec._x;
		_y += vec._y;
		_z += vec._z;
		return *this;
	}

	// Vector4 -= Vector3
	// ===============================
	Vector4& Vector4::operator-= (const Vector3& vec)
	{
		_x -= vec._x;
		_y -= vec._y;
		_z -= vec._z;
		return *this;
	}

	// Vector4 *= Vector3
	// ===============================
	Vector4& Vector4::operator*= (const Vector3& vec)
	{
		_x *= vec._x;
		_y *= vec._y;
		_z *= vec._z;
		return *this;
	}

	// Vector4 /= Vector3
	// ===============================
	Vector4& Vector4::operator/= (const Vector3& vec)
	{
		_x /= vec._x;
		_y /= vec._y;
		_z /= vec._z;
		return *this;
	}

	// Vector4 += KOVECTOR
	// ===============================
	Vector4& Vector4::operator+= (const KOVECTOR& vec)
	{
		_x += vec._xFloat;
		_y += vec._yFloat;
		_z += vec._zFloat;
		_w += vec._wFloat;
		return *this;
	}

	// Vector4 -= KOVECTOR
	// ===============================
	Vector4& Vector4::operator-= (const KOVECTOR& vec)
	{
		_x -= vec._xFloat;
		_y -= vec._yFloat;
		_z -= vec._zFloat;
		_w -= vec._wFloat;
		return *this;
	}

	// Vector4 *= KOVECTOR
	// ===============================
	Vector4& Vector4::operator*= (const KOVECTOR& vec)
	{
		_x *= vec._xFloat;
		_y *= vec._yFloat;
		_z *= vec._zFloat;
		_w *= vec._wFloat;
		return *this;
	}

	// Vector4 /= KOVECTOR
	// ===============================
	Vector4& Vector4::operator/= (const KOVECTOR& vec)
	{
		_x /= vec._xFloat;
		_y /= vec._yFloat;
		_z /= vec._zFloat;
		_w /= vec._wFloat;
		return *this;
	}

	// if(Vector4 == Vector4)
	// ===============================
	bool Vector4::operator== (const Vector4& vec)const
	{
		return (_x == vec._x && _y == vec._y && _z == vec._z && _w == vec._w);
	}

	// if(Vector4 != Vector4)
	// ===============================
	bool Vector4::operator!= (const Vector4& vec)const
	{
		return (_x != vec._x && _y != vec._y && _z != vec._z && _w != vec._w);
	}

	// if(Vector4 == Vector2)
	// ===============================
	bool Vector4::operator== (const Vector2& vec)const
	{
		return (_x == vec._x && _y == vec._y);
	}

	// if(Vector4 != Vector2)
	// ===============================
	bool Vector4::operator!= (const Vector2& vec)const
	{
		return (_x != vec._x && _y != vec._y);
	}

	// if(Vector4 == Vector3)
	// ===============================
	bool Vector4::operator== (const Vector3& vec)const
	{
		return (_x == vec._x && _y == vec._y && _z == vec._z);
	}

	// if(Vector4 != Vector3)
	// ===============================
	bool Vector4::operator!= (const Vector3& vec)const
	{
		return (_x != vec._x && _y != vec._y && _z != vec._z);
	}

	// if(Vector4 == KOVECTOR)
	// ===============================
	bool Vector4::operator== (const KOVECTOR& vec)const
	{
		return (_x == vec._xFloat && _y == vec._yFloat && _z == vec._zFloat && _w == vec._wFloat);
	}

	// if(Vector4 != KOVECTOR)
	// ===============================
	bool Vector4::operator!= (const KOVECTOR& vec)const
	{
		return (_x != vec._xFloat && _y != vec._yFloat && _z != vec._zFloat && _w != vec._wFloat);
	}

	// Vector4 = Vector2
	// ===============================
	Vector4& Vector4::operator= (const Vector2& vec)
	{
		_x = vec._x;
		_y = vec._y;
		_z = 0.0f;
		_w = 0.0f;
		return *this;
	}

	// Vector4 = Vector3
	// ===============================
	Vector4& Vector4::operator= (const Vector3& vec)
	{
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
		_w = 0.0f;
		return *this;
	}

	// Vector4 = KOVECTOR
	// ===============================
	Vector4& Vector4::operator= (const KOVECTOR& vec)
	{
		_x = vec._xFloat;
		_y = vec._yFloat;
		_z = vec._zFloat;
		_w = vec._wFloat;
		return *this;
	}
}