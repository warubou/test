// ------------------------------------------------------------------------------------------------
// vector3.h								オリジナルベクトル(Vector3)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTORについては全てfloat型を参照する
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <DirectXMath.h>

namespace ko 
{
	// ==========================================================
	// 前方宣言
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
		// コンストラクタ
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
		// DirectX::XM系との暗黙的変換
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_x, _y, _z, 0.0f);
		}

		operator DirectX::XMFLOAT3() const {
			return DirectX::XMFLOAT3(_x, _y, _z);
		}

		// ==========================================================
		// 演算子のオーバーロード！！
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
		// _zは無視
		// ===============================
		Vector3 operator+ (const Vector2& vec)const;
		// Vector3 - Vector2
		// _zは無視
		// ===============================
		Vector3 operator- (const Vector2& vec)const;
		// Vector3 * Vector2
		// _zは無視
		// ===============================
		Vector3 operator* (const Vector2& vec)const;
		// Vector3 / Vector2
		// _zは無視
		// ===============================
		Vector3 operator/ (const Vector2& vec)const;
		// Vector3 + Vector4
		// 引数の_wは無視
		// ===============================
		Vector3 operator+ (const Vector4& vec)const;
		// Vector3 - Vector4
		// 引数の_wは無視
		// ===============================
		Vector3 operator- (const Vector4& vec)const;
		// Vector3 * Vector4
		// 引数の_wは無視
		// ===============================
		Vector3 operator* (const Vector4& vec)const;
		// Vector3 / Vector4
		// 引数の_wは無視
		// ===============================
		Vector3 operator/ (const Vector4& vec)const;
		// Vector3 + KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3 operator+ (const KOVECTOR& vec)const;
		// Vector3 - KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3 operator- (const KOVECTOR& vec)const;
		// Vector3 * KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3 operator* (const KOVECTOR& vec)const;
		// Vector3 / KOVECTOR
		// 引数の_wFloatは無視
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
		// _zは無視
		// ===============================
		Vector3& operator+= (const Vector2& vec);
		// Vector3 -= Vector2
		// _zは無視
		// ===============================
		Vector3& operator-= (const Vector2& vec);
		// Vector3 *= Vector2
		// _zは無視
		// ===============================
		Vector3& operator*= (const Vector2& vec);
		// Vector3 /= Vector2
		// _zは無視
		// ===============================
		Vector3& operator/= (const Vector2& vec);
		// Vector3 += Vector4
		// 引数の_wは無視
		// ===============================
		Vector3& operator+= (const Vector4& vec);
		// Vector3 -= Vector4
		// 引数の_wは無視
		// ===============================
		Vector3& operator-= (const Vector4& vec);
		// Vector3 *= Vector4
		// 引数の_wは無視
		// ===============================
		Vector3& operator*= (const Vector4& vec);
		// Vector3 /= Vector4
		// 引数の_wは無視
		// ===============================
		Vector3& operator/= (const Vector4& vec);
		// Vector3 += KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3& operator+= (const KOVECTOR& vec);
		// Vector3 -= KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3& operator-= (const KOVECTOR& vec);
		// Vector3 *= KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3& operator*= (const KOVECTOR& vec);
		// Vector3 /= KOVECTOR
		// 引数の_wFloatは無視
		// ===============================
		Vector3& operator/= (const KOVECTOR& vec);

		// if(Vector3 == Vector3)
		// ===============================
		bool operator== (const Vector3& vec)const;
		// if(Vector3 != Vector3)
		// ===============================
		bool operator!= (const Vector3& vec)const;
		// if(Vector3 == Vector2)
		// _zは比較しない
		// ===============================
		bool operator== (const Vector2& vec)const;
		// if(Vector3 != Vector2)
		// _zは比較しない
		// ===============================
		bool operator!= (const Vector2& vec)const;
		// if(Vector3 == Vector4)
		// 引数の_wは比較しない
		// ===============================
		bool operator== (const Vector4& vec)const;
		// if(Vector3 != Vector4)
		// 引数の_wは比較しない
		// ===============================
		bool operator!= (const Vector4& vec)const;
		// if(Vector3 == KOVECTOR)
		// 引数の_wFloatは比較しない
		// ===============================
		bool operator== (const KOVECTOR& vec)const;
		// if(Vector3 != KOVECTOR)
		// 引数の_wFloatは比較しない
		// ===============================
		bool operator!= (const KOVECTOR& vec)const;

		// Vector3 = float
		// _zは0
		// ===============================
		Vector3& operator= (const float& t);
		// Vector3 = Vector2
		// _zは0
		// ===============================
		Vector3& operator= (const Vector2& vec);
		// Vector3 = Vector4
		// ===============================
		Vector3& operator= (const Vector4& vec);
		// Vector3 = KOVECTOR
		// ===============================
		Vector3& operator= (const KOVECTOR& vec);

		// Vector3の値全て0.0fを生成
		// ===============================
		static const Vector3 zero;
		// Vector3の値全て1.0fを生成
		// ===============================
		static const Vector3 one;
		// _y =  1.0fのVector3を生成
		// ===============================
		static const Vector3 up;
		// _y = -1.0fのVector3を生成
		// ===============================
		static const Vector3 down;
		// _x =  1.0fのVector3を生成
		// ===============================
		static const Vector3 right;
		// _x = -1.0fのVector3を生成
		// ===============================
		static const Vector3 left;
		// _z =  1.0fのVector3を生成(左手座標系)
		// ===============================
		static const Vector3 frontLH;
		// _z = -1.0fのVector3を生成(左手座標系)
		// ===============================
		static const Vector3 backLH;
		// _z = -1.0fのVector3を生成(右手座標系)
		// ===============================
		static const Vector3 frontRH;
		// _z =  1.0fのVector3を生成(右手座標系)
		// ===============================
		static const Vector3 backRH;
	};

}

#endif // VECTOR3_H_