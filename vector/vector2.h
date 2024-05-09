// ------------------------------------------------------------------------------------------------
// vector2.h								オリジナルベクトル(Vector2)
// Date 2023/12/26
// Author Keigo Onari
// KOVECTORについては全てfloat型を参照する
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <DirectXMath.h>

namespace ko {

	// ==========================================================
	// 前方宣言
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
		// コンストラクタ
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
		// DirectX::XM系との暗黙的変換
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_x, _y, 0.0f, 0.0f);
		}

		operator DirectX::XMFLOAT2() const {
			return DirectX::XMFLOAT2(_x, _y);
		}

		// ==========================================================
		// 演算子のオーバーロード！！
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
		// 引数の_zは無視
		// ===============================
		Vector2& operator+= (const Vector3& vec);
		// Vector2 -= Vector3
		// 引数の_zは無視
		// ===============================
		Vector2& operator-= (const Vector3& vec);
		// Vector2 *= Vector3
		// 引数の_zは無視
		// ===============================
		Vector2& operator*= (const Vector3& vec);
		// Vector2 /= Vector3
		// 引数の_zは無視
		// ===============================
		Vector2& operator/= (const Vector3& vec);
		// Vector2 += Vector4
		// 引数の_z、_wは無視
		// ===============================
		Vector2& operator+= (const Vector4& vec);
		// Vector2 -= Vector4
		// 引数の_z、_wは無視
		// ===============================
		Vector2& operator-= (const Vector4& vec);
		// Vector2 *= Vector4
		// 引数の_z、_wは無視
		// ===============================
		Vector2& operator*= (const Vector4& vec);
		// Vector2 /= Vector4
		// 引数の_z、_wは無視
		// ===============================
		Vector2& operator/= (const Vector4& vec);
		// Vector2 += KOVECTOR
		// 引数の_zFloat、_wFloatは無視
		// ===============================
		Vector2& operator+= (const KOVECTOR& vec);
		// Vector2 -= KOVECTOR
		// 引数の_zFloat、_wFloatは無視
		// ===============================
		Vector2& operator-= (const KOVECTOR& vec);
		// Vector2 *= KOVECTOR
		// 引数の_zFloat、_wFloatは無視
		// ===============================
		Vector2& operator*= (const KOVECTOR& vec);
		// Vector2 /= KOVECTOR
		// 引数の_zFloat、_wFloatは無視
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

		// Vector2の値全て0.0fを生成
		// ===============================
		static const Vector2 zero;
		// Vector2の値全て1.0fを生成
		// ===============================
		static const Vector2 one;
		// _y =  1.0fのVector2を生成
		// ===============================
		static const Vector2 up;
		// _y = -1.0fのVector2を生成
		// ===============================
		static const Vector2 down;
		// _x =  1.0fのVector2を生成
		// ===============================
		static const Vector2 right;
		// _x = -1.0fのVector2を生成
		// ===============================
		static const Vector2 left;
	};

}

#endif // VECTOR2_H_