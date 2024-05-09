// ------------------------------------------------------------------------------------------------
// koVector.h								オリジナルベクトル(KOVECTOR)
// Date 2023/12/26
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef KO_VECTOR_H_
#define KO_VECTOR_H_

#include <Windows.h>
#include <DirectXMath.h>

#define KOAssert(item, text, windowName)\
{\
    if(!item)\
    {\
        (void)MessageBox(NULL,text, windowName, MB_OK);\
    }\
}
typedef unsigned int kouint32_t;

namespace ko
{
	// ==========================================================
	// 前方宣言
	// ========================================================== 
	struct Vector2;
	struct Vector3;
	struct Vector4;

	// ==========================================================
	// 疑似的DirectX::XMVECTOR
	// ========================================================== 
	struct KOVECTOR
	{
		union {
			float _vec[4];

			kouint32_t _vecInt[4];

			struct
			{
				float _xFloat, _yFloat, _zFloat, _wFloat;
			};

			struct
			{
				int _xInt, _yInt, _zInt, _wInt;
			};

			struct
			{
				char _xChar[4];
				char _yChar[4];
				char _zChar[4];
				char _wChar[4];
			};
		};

		// コンストラクタ
		// ===============================
		//KOVECTOR() :KOVECTOR(0.0f, 0.0f, 0.0f, 0.0f) {}
		KOVECTOR() = default;
		KOVECTOR(const Vector2& v);
		KOVECTOR(const Vector2& v1, const Vector2& v2);
		KOVECTOR(const Vector2& v, const float& t1, const float& t2);
		KOVECTOR(const Vector3& v);
		KOVECTOR(const Vector3& v, const float& t);
		KOVECTOR(const Vector4& v);
		KOVECTOR(float X, float Y, float Z, float W) :_xFloat(X), _yFloat(Y), _zFloat(Z), _wFloat(W) {}
		KOVECTOR(int X, int Y, int Z, int W) :_xInt(X), _yInt(Y), _zInt(Z), _wInt(W) {}
		KOVECTOR(float XYZWf) :_xFloat(XYZWf), _yFloat(XYZWf), _zFloat(XYZWf), _wFloat(XYZWf) {}
		KOVECTOR(int XYZWi) :_xInt(XYZWi), _yInt(XYZWi), _zInt(XYZWi), _wInt(XYZWi) {}

		// ==========================================================
		// DirectX::XM系との暗黙的変換
		// ==========================================================
		operator DirectX::XMVECTOR() const {
			return DirectX::XMVectorSet(_xFloat, _yFloat, _zFloat, _wFloat);
		}

		// ==========================================================
		// 演算子のオーバーロード！！
		// ==========================================================
		// +KOVECTOR
		// ===============================
		KOVECTOR operator+ (void)const;
		// -KOVECTOR
		// ===============================
		KOVECTOR operator- (void)const;

		// KOVECTOR + KOVECTOR
		// ===============================
		KOVECTOR operator+ (const KOVECTOR& vec)const;
		// KOVECTOR - KOVECTOR
		// ===============================
		KOVECTOR operator- (const KOVECTOR& vec)const;
		// KOVECTOR * KOVECTOR
		// ===============================
		KOVECTOR operator* (const KOVECTOR& vec)const;
		// KOVECTOR / KOVECTOR
		// ===============================
		KOVECTOR operator/ (const KOVECTOR& vec)const;
		// KOVECTOR + float
		// ===============================
		KOVECTOR operator+ (const float& t)const;
		// KOVECTOR - float
		// ===============================
		KOVECTOR operator- (const float& t)const;
		// KOVECTOR * float
		// ===============================
		KOVECTOR operator* (const float& t)const;
		// KOVECTOR / float
		// ===============================
		KOVECTOR operator/ (const float& t)const;
		// KOVECTOR + Vector2
		// _zFloat,_wFloatは無視
		// ===============================
		KOVECTOR operator+ (const Vector2& vec)const;
		// KOVECTOR - Vector2
		// _zFloat,_wFloatは無視
		// ===============================
		KOVECTOR operator- (const Vector2& vec)const;
		// KOVECTOR * Vector2
		// _zFloat,_wFloatは無視
		// ===============================
		KOVECTOR operator* (const Vector2& vec)const;
		// KOVECTOR / Vector2
		// _zFloat,_wFloatは無視
		// ===============================
		KOVECTOR operator/ (const Vector2& vec)const;
		// KOVECTOR + Vector3
		// ===============================
		KOVECTOR operator+ (const Vector3& vec)const;
		// KOVECTOR - Vector3
		// _wFloatは無視
		// ===============================
		KOVECTOR operator- (const Vector3& vec)const;
		// KOVECTOR * Vector3
		// _wFloatは無視
		// ===============================
		KOVECTOR operator* (const Vector3& vec)const;
		// KOVECTOR / Vector3
		// _wFloatは無視
		// ===============================
		KOVECTOR operator/ (const Vector3& vec)const;
		// KOVECTOR + Vector4
		// ===============================
		KOVECTOR operator+ (const Vector4& vec)const;
		// KOVECTOR - Vector4
		// ===============================
		KOVECTOR operator- (const Vector4& vec)const;
		// KOVECTOR * Vector4
		// ===============================
		KOVECTOR operator* (const Vector4& vec)const;
		// KOVECTOR / Vector4
		// ===============================
		KOVECTOR operator/ (const Vector4& vec)const;

		// KOVECTOR += KOVECTOR
		// ===============================
		KOVECTOR& operator+= (const KOVECTOR& vec);
		// KOVECTOR -= KOVECTOR
		// ===============================
		KOVECTOR& operator-= (const KOVECTOR& vec);
		// KOVECTOR *= KOVECTOR
		// ===============================
		KOVECTOR& operator*= (const KOVECTOR& vec);
		// KOVECTOR /= KOVECTOR
		// ===============================
		KOVECTOR& operator/= (const KOVECTOR& vec);
		// KOVECTOR += Vector4
		// ===============================
		KOVECTOR& operator+= (const Vector4& vec);
		// KOVECTOR -= Vector4
		// ===============================
		KOVECTOR& operator-= (const Vector4& vec);
		// KOVECTOR *= Vector4
		// ===============================
		KOVECTOR& operator*= (const Vector4& vec);
		// KOVECTOR /= Vector4
		// ===============================
		KOVECTOR& operator/= (const Vector4& vec);
		// KOVECTOR += float
		// ===============================
		KOVECTOR& operator+= (const float& t);
		// KOVECTOR -= float
		// ===============================
		KOVECTOR& operator-= (const float& t);
		// KOVECTOR *= float
		// ===============================
		KOVECTOR& operator*= (const float& t);
		// KOVECTOR /= float
		// ===============================
		KOVECTOR& operator/= (const float& t);

		// if(KOVECTOR == KOVECTOR)
		// ===============================
		bool operator== (const KOVECTOR& vec);
		// if(KOVECTOR != KOVECTOR)
		// ===============================
		bool operator!= (const KOVECTOR& vec);
		// if(KOVECTOR == Vector2)
		// _zFloat,_wFloatは比較しない
		// ===============================
		bool operator== (const Vector2& vec);
		// if(KOVECTOR != Vector2)
		// _zFloat,_wFloatは比較しない
		// ===============================
		bool operator!= (const Vector2& vec);
		// if(KOVECTOR == Vector3)
		// _wFloatは比較しない
		// ===============================
		bool operator== (const Vector3& vec);
		// if(KOVECTOR != Vector3)
		// _wFloatは比較しない
		// ===============================
		bool operator!= (const Vector3& vec);
		// if(KOVECTOR == Vecror4)
		// ===============================
		bool operator== (const Vector4& vec);
		// if(KOVECTOR != Vecror4)
		// ===============================
		bool operator!= (const Vector4& vec);

		// KOVECTOR = t
		// ===============================
		KOVECTOR& operator= (const float& t);
		// KOVECTOR = Vector2
		// _zFloat,_wFloatは0
		// ===============================
		KOVECTOR& operator= (const Vector2& vec);
		// KOVECTOR = Vector3
		// _wFloatは0
		// ===============================
		KOVECTOR& operator= (const Vector3& vec);
		// KOVECTOR = Vector4
		// ===============================
		KOVECTOR& operator= (const Vector4& vec);

		// KOVECTORの値全て 0.0fを生成
		// ===============================
		static const KOVECTOR zero;
		// KOVECTORの値全て 1.0fを生成
		// ===============================
		static const KOVECTOR one;
		// KOVECTORの値全て-1.0fを生成
		// ===============================
		static const KOVECTOR allminus;
		// _yFloat =  1.0fのKOVECTORを生成
		// ===============================
		static const KOVECTOR up;
		// _yFloat = -1.0fのKOVECTORを生成
		// ===============================
		static const KOVECTOR down;
		// _xFloat =  1.0fのKOVECTORを生成
		// ===============================
		static const KOVECTOR right;
		// _xFloat = -1.0fのKOVECTORを生成
		// ===============================
		static const KOVECTOR left;
		// _zFloat =  1.0fのKOVECTORを生成(左手座標系)
		// ===============================
		static const KOVECTOR frontLH;
		// _zFloat = -1.0fのKOVECTORを生成(左手座標系)
		// ===============================
		static const KOVECTOR backLH;
		// _zFloat = -1.0fのKOVECTORを生成(右手座標系)
		// ===============================
		static const KOVECTOR frontRH;
		// _zFloat =  1.0fのKOVECTORを生成(右手座標系)
		// ===============================
		static const KOVECTOR backRH;
	};
}

#endif // KO_VECTOR_H_