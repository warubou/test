// ------------------------------------------------------------------------------------------------
// koVector.cpp								オリジナルベクトル(KOVECTOR)
// Date 2023/12/26
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#include "koVector.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

namespace ko
{
	// =====================================
	// 疑似的DirectX::XMVECTOR
	// =====================================

	// コンストラクタ
	// =====================================
	KOVECTOR::KOVECTOR(const Vector2& v) :_xFloat(v._x), _yFloat(v._y), _zFloat(0.0f), _wFloat(0.0f) {}
	KOVECTOR::KOVECTOR(const Vector2& v1, const Vector2& v2) : _xFloat(v1._x), _yFloat(v1._y), _zFloat(v2._x), _wFloat(v2._y) {}
	KOVECTOR::KOVECTOR(const Vector2& v, const float& t1, const float& t2) :_xFloat(v._x), _yFloat(v._y), _zFloat(t1), _wFloat(t2) {}
	KOVECTOR::KOVECTOR(const Vector3& v) :_xFloat(v._x), _yFloat(v._y), _zFloat(v._z), _wFloat(0.0f) {}
	KOVECTOR::KOVECTOR(const Vector3& v, const float& t) : _xFloat(v._x), _yFloat(v._y), _zFloat(v._z), _wFloat(t) {}
	KOVECTOR::KOVECTOR(const Vector4& v) :_xFloat(v._x), _yFloat(v._y), _zFloat(v._z), _wFloat(v._w) {}

	// 静的変数の初期化
	// =====================================
	// KOVECTORの値全て 0.0fを生成
	// ===============================
	const KOVECTOR KOVECTOR::zero(0.0f, 0.0f, 0.0f, 0.0f);
	// KOVECTORの値全て 1.0fを生成
	// ===============================
	const KOVECTOR KOVECTOR::one(1.0f, 1.0f, 1.0f, 1.0f);
	// KOVECTORの値全て-1.0fを生成
	// ===============================
	const KOVECTOR KOVECTOR::allminus(-1.0f, -1.0f, -1.0f, -1.0f);
	// _yFloat =  1.0fのKOVECTORを生成
	// ===============================
	const KOVECTOR KOVECTOR::up(0.0f, 1.0f, 0.0f, 0.0f);
	// _yFloat = -1.0fのKOVECTORを生成
	// ===============================
	const KOVECTOR KOVECTOR::down(0.0f, -1.0f, 0.0f, 0.0f);
	// _xFloat =  1.0fのKOVECTORを生成
	// ===============================
	const KOVECTOR KOVECTOR::right(1.0f, 0.0f, 0.0f, 0.0f);
	// _xFloat = -1.0fのKOVECTORを生成
	// ===============================
	const KOVECTOR KOVECTOR::left(-1.0f, 0.0f, 0.0f, 0.0f);
	// _zFloat =  1.0fのKOVECTORを生成(左手座標系)
	// ===============================
	const KOVECTOR KOVECTOR::frontLH(0.0f, 0.0f, -1.0f, 0.0f);
	// _zFloat = -1.0fのKOVECTORを生成(左手座標系)
	// ===============================
	const KOVECTOR KOVECTOR::backLH(0.0f, 0.0f, 1.0f, 0.0f);
	// _zFloat = -1.0fのKOVECTORを生成(右手座標系)
	// ===============================
	const KOVECTOR KOVECTOR::frontRH(0.0f, 0.0f, 1.0f, 0.0f);
	// _zFloat =  1.0fのKOVECTORを生成(右手座標系)
	// ===============================
	const KOVECTOR KOVECTOR::backRH(0.0f, 0.0f, -1.0f, 0.0f);

	// +KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator+ (void)const
	{
		return *this;
	}

	// -KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator- (void)const
	{
		return KOVECTOR(-_xFloat, -_yFloat, -_zFloat, -_wFloat);
	}

	// KOVECTOR + KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator+ (const KOVECTOR& vec)const
	{
		return KOVECTOR(_xFloat + vec._xFloat, _yFloat + vec._yFloat, _zFloat + vec._zFloat, _wFloat + vec._wFloat);
	}

	// KOVECTOR - KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator- (const KOVECTOR& vec)const
	{
		return KOVECTOR(_xFloat - vec._xFloat, _yFloat - vec._yFloat, _zFloat - vec._zFloat, _wFloat - vec._wFloat);
	}

	// KOVECTOR * KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator* (const KOVECTOR& vec)const
	{
		return KOVECTOR(_xFloat * vec._xFloat, _yFloat * vec._yFloat, _zFloat * vec._zFloat, _wFloat * vec._wFloat);
	}

	// KOVECTOR / KOVECTOR
	// ===============================
	KOVECTOR KOVECTOR::operator/ (const KOVECTOR& vec)const
	{
		return KOVECTOR(_xFloat / vec._xFloat, _yFloat / vec._yFloat, _zFloat / vec._zFloat, _wFloat / vec._wFloat);
	}

	// KOVECTOR + float
	// ===============================
	KOVECTOR KOVECTOR::operator+(const float& t)const
	{
		return KOVECTOR(_xFloat + t, _yFloat + t, _zFloat + t, _wFloat + t);
	}

	// KOVECTOR - float
	// ===============================
	KOVECTOR KOVECTOR::operator- (const float& t)const
	{
		return KOVECTOR(_xFloat - t, _yFloat - t, _zFloat - t, _wFloat - t);
	}

	// KOVECTOR * float
	// ===============================
	KOVECTOR KOVECTOR::operator* (const float& t)const
	{
		return KOVECTOR(_xFloat * t, _yFloat * t, _zFloat * t, _wFloat * t);
	}

	// KOVECTOR / float
	// ===============================
	KOVECTOR KOVECTOR::operator/ (const float& t)const
	{
		return KOVECTOR(_xFloat / t, _yFloat / t, _zFloat / t, _wFloat / t);
	}

	// KOVECTOR + Vector2
	// ===============================
	KOVECTOR KOVECTOR::operator+ (const Vector2& vec)const
	{
		return KOVECTOR(_xFloat + vec._x, _yFloat + vec._y, _zFloat, _wFloat);
	}

	// KOVECTOR - Vector2
	// ===============================
	KOVECTOR KOVECTOR::operator- (const Vector2& vec)const
	{
		return KOVECTOR(_xFloat - vec._x, _yFloat - vec._y, _zFloat, _wFloat);
	}

	// KOVECTOR * Vector2
	// ===============================
	KOVECTOR KOVECTOR::operator* (const Vector2& vec)const
	{
		return KOVECTOR(_xFloat * vec._x, _yFloat * vec._y, _zFloat, _wFloat);
	}

	// KOVECTOR / Vector2
	// ===============================
	KOVECTOR KOVECTOR::operator/ (const Vector2& vec)const
	{
		return KOVECTOR(_xFloat / vec._x, _yFloat / vec._y, _zFloat, _wFloat);
	}

	// KOVECTOR + Vector3
	// ===============================
	KOVECTOR KOVECTOR::operator+ (const Vector3& vec)const
	{
		return KOVECTOR(_xFloat + vec._x, _yFloat + vec._y, _zFloat + vec._z, _wFloat);
	}

	// KOVECTOR - Vector3
	// ===============================
	KOVECTOR KOVECTOR::operator- (const Vector3& vec)const
	{
		return KOVECTOR(_xFloat - vec._x, _yFloat - vec._y, _zFloat - vec._z, _wFloat);
	}

	// KOVECTOR * Vector3
	// ===============================
	KOVECTOR KOVECTOR::operator* (const Vector3& vec)const
	{
		return KOVECTOR(_xFloat * vec._x, _yFloat * vec._y, _zFloat * vec._z, _wFloat);
	}

	// KOVECTOR / Vector3
	// ===============================
	KOVECTOR KOVECTOR::operator/ (const Vector3& vec)const
	{
		return KOVECTOR(_xFloat / vec._x, _yFloat / vec._y, _zFloat / vec._z, _wFloat);
	}

	// KOVECTOR + Vector4
	// ===============================
	KOVECTOR KOVECTOR::operator+ (const Vector4& vec)const
	{
		return KOVECTOR(_xFloat + vec._x, _yFloat + vec._y, _zFloat + vec._z, _wFloat + vec._w);
	}

	// KOVECTOR - Vector4
	// ===============================
	KOVECTOR KOVECTOR::operator- (const Vector4& vec)const
	{
		return KOVECTOR(_xFloat - vec._x, _yFloat - vec._y, _zFloat - vec._z, _wFloat - vec._w);
	}

	// KOVECTOR * Vector4
	// ===============================
	KOVECTOR KOVECTOR::operator* (const Vector4& vec)const
	{
		return KOVECTOR(_xFloat * vec._x, _yFloat * vec._y, _zFloat * vec._z, _wFloat * vec._w);
	}

	// KOVECTOR / Vector4
	// ===============================
	KOVECTOR KOVECTOR::operator/ (const Vector4& vec)const
	{
		return KOVECTOR(_xFloat / vec._x, _yFloat / vec._y, _zFloat / vec._z, _wFloat / vec._w);
	}

	// KOVECTOR += KOVECTOR
	// ===============================
	KOVECTOR& KOVECTOR::operator+= (const KOVECTOR& vec)
	{
		_xFloat += vec._xFloat;
		_yFloat += vec._yFloat;
		_zFloat += vec._zFloat;
		_wFloat += vec._wFloat;
		return *this;
	}

	// KOVECTOR -= KOVECTOR
	// ===============================
	KOVECTOR& KOVECTOR::operator-= (const KOVECTOR& vec)
	{
		_xFloat -= vec._xFloat;
		_yFloat -= vec._yFloat;
		_zFloat -= vec._zFloat;
		_wFloat -= vec._wFloat;
		return *this;
	}

	// KOVECTOR *= KOVECTOR
	// ===============================
	KOVECTOR& KOVECTOR::operator*= (const KOVECTOR& vec)
	{
		_xFloat *= vec._xFloat;
		_yFloat *= vec._yFloat;
		_zFloat *= vec._zFloat;
		_wFloat *= vec._wFloat;
		return *this;
	}

	// KOVECTOR /= KOVECTOR
	// ===============================
	KOVECTOR& KOVECTOR::operator/= (const KOVECTOR& vec)
	{
		_xFloat /= vec._xFloat;
		_yFloat /= vec._yFloat;
		_zFloat /= vec._zFloat;
		_wFloat /= vec._wFloat;
		return *this;
	}

	// KOVECTOR += Vector4
	// ===============================
	KOVECTOR& KOVECTOR::operator+= (const Vector4& vec)
	{
		_xFloat += vec._x;
		_yFloat += vec._y;
		_zFloat += vec._z;
		_wFloat += vec._w;
		return *this;
	}

	// KOVECTOR -= Vector4
	// ===============================
	KOVECTOR& KOVECTOR::operator-= (const Vector4& vec)
	{
		_xFloat -= vec._x;
		_yFloat -= vec._y;
		_zFloat -= vec._z;
		_wFloat -= vec._w;
		return *this;
	}

	// KOVECTOR *= Vector4
	// ===============================
	KOVECTOR& KOVECTOR::operator*= (const Vector4& vec)
	{
		_xFloat *= vec._x;
		_yFloat *= vec._y;
		_zFloat *= vec._z;
		_wFloat *= vec._w;
		return *this;
	}

	// KOVECTOR /= Vector4
	// ===============================
	KOVECTOR& KOVECTOR::operator/= (const Vector4& vec)
	{
		_xFloat /= vec._x;
		_yFloat /= vec._y;
		_zFloat /= vec._z;
		_wFloat /= vec._w;
		return *this;
	}

	// KOVECTOR += float
	// ===============================
	KOVECTOR& KOVECTOR::operator+=(const float& t)
	{
		_xFloat += t;
		_yFloat += t;
		_zFloat += t;
		_wFloat += t;
		return *this;
	}

	// KOVECTOR -= float
	// ===============================
	KOVECTOR& KOVECTOR::operator-=(const float& t)
	{
		_xFloat -= t;
		_yFloat -= t;
		_zFloat -= t;
		_wFloat -= t;
		return *this;
	}

	// KOVECTOR *= float
	// ===============================
	KOVECTOR& KOVECTOR::operator*=(const float& t)
	{
		_xFloat *= t;
		_yFloat *= t;
		_zFloat *= t;
		_wFloat *= t;
		return *this;
	}

	// KOVECTOR /= float
	// ===============================
	KOVECTOR& KOVECTOR::operator/=(const float& t)
	{
		_xFloat /= t;
		_yFloat /= t;
		_zFloat /= t;
		_wFloat /= t;
		return *this;
	}

	// if(KOVECTOR == KOVECTOR)
	// ===============================
	bool KOVECTOR::operator== (const KOVECTOR& vec)
	{
		return (_xFloat == vec._xFloat && _yFloat == vec._yFloat && _zFloat == vec._zFloat && _wFloat == vec._wFloat);
	}

	// if(KOVECTOR != KOVECTOR)
	// ===============================
	bool KOVECTOR::operator!= (const KOVECTOR& vec)
	{
		return (_xFloat != vec._xFloat && _yFloat != vec._yFloat && _zFloat != vec._zFloat && _wFloat != vec._wFloat);
	}

	// if(KOVECTOR == Vector2)
	// ===============================
	bool KOVECTOR::operator== (const Vector2& vec)
	{
		return (_xFloat == vec._x && _yFloat == vec._y);
	}

	// if(KOVECTOR != Vector2)
	// ===============================
	bool KOVECTOR::operator!= (const Vector2& vec)
	{
		return (_xFloat != vec._x && _yFloat != vec._y);
	}

	// if(KOVECTOR == Vector3)
	// ===============================
	bool KOVECTOR::operator== (const Vector3& vec)
	{
		return (_xFloat == vec._x && _yFloat == vec._y && _zFloat == vec._z);
	}

	// if(KOVECTOR != Vector3)
	// ===============================
	bool KOVECTOR::operator!= (const Vector3& vec)
	{
		return (_xFloat != vec._x && _yFloat != vec._y && _zFloat != vec._z);
	}

	// if(KOVECTOR == Vecror4)
	// ===============================
	bool KOVECTOR::operator== (const Vector4& vec)
	{
		return (_xFloat == vec._x && _yFloat == vec._y && _zFloat == vec._z && _wFloat == vec._w);
	}

	// if(KOVECTOR != Vecror4)
	// ===============================
	bool KOVECTOR::operator!= (const Vector4& vec)
	{
		return (_xFloat != vec._x && _yFloat != vec._y && _zFloat != vec._z && _wFloat != vec._w);
	}

	// KOVECTOR = float
	// ===============================
	KOVECTOR& KOVECTOR::operator=(const float& t)
	{
		_xFloat = t;
		_yFloat = t;
		_zFloat = t;
		_wFloat = t;
		return *this;
	}

	// KOVECTOR = Vector2
	// ===============================
	KOVECTOR& KOVECTOR::operator= (const Vector2& vec)
	{
		_xFloat = vec._x;
		_yFloat = vec._y;
		_zFloat = 0.0f;
		_wFloat = 0.0f;
		return *this;
	}

	// KOVECTOR = Vector3
	// ===============================
	KOVECTOR& KOVECTOR::operator=(const Vector3& vec)
	{
		_xFloat = vec._x;
		_yFloat = vec._y;
		_zFloat = vec._z;
		_wFloat = 0.0f;
		return *this;
	}

	// KOVECTOR = Vector4
	// ===============================
	KOVECTOR& KOVECTOR::operator=(const Vector4& vec)
	{
		_xFloat = vec._x;
		_yFloat = vec._y;
		_zFloat = vec._z;
		_wFloat = vec._w;
		return *this;
	}
}