// ------------------------------------------------------------------------------------------------
// koMath.cpp								オリジナルベクトル計算数学関数
// Date 2023/12/27
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#include "koMath.h"

#include <DirectXMath.h>

namespace ko
{
	namespace vector2
	{
		// Vector2からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector2& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y);
		}

		// Vector2の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			Vector2 temp = ko::vector2::Subtract(vec2, vec1);
			return ko::vector2::LengthSq(temp);
		}

		// Vector2からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector2& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y);
		}

		// Vector2の2点間の距離を計算
		// ===============================
		const float& Length(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			Vector2 temp = ko::vector2::Subtract(vec2, vec1);
			return ko::vector2::Length(temp);
		}

		// Vector2から正規化したVector2型を取得
		// ===============================
		const Vector2& Normalize(const Vector2& vec)noexcept
		{
			float length = ko::vector2::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector3から正規化したVector2型を取得
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

		// Vector4から正規化したVector2型を取得
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

		// Vector2からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1._x * vec2._x + vec1._y * vec2._y;
		}

		// Vector2からVector2型の外積を取得
		// ===============================
		const float& Cross(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1._x * vec2._y - vec1._y * vec2._x;
		}

		// Vector2からVector2同士の差分を取得(Vector2型)
		// ===============================
		const Vector2& Subtract(const Vector2& vec1, const Vector2& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector2間を線形補完して返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector2& vec1, const Vector2& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}
	}

	namespace vector3
	{
		// Vector3からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector3& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y + vec._z * vec._z);
		}

		// Vector3の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 temp = ko::vector3::Subtract(vec2, vec1);
			return ko::vector3::LengthSq(temp);
		}

		// Vector3からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector3& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y + vec._z * vec._z);
		}

		// Vector3の2点間の長さを取得
		// ===============================
		const float& Length(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 temp = ko::vector3::Subtract(vec2, vec1);
			return ko::vector3::Length(temp);
		}

		// Vector3から正規化したVector3型を取得
		// ===============================
		const Vector3& Normalize(const Vector3& vec)noexcept
		{
			float length = ko::vector3::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector4から正規化したVector3型を取得
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

		// Vector3からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			return (vec1._x * vec2._x + vec1._y * vec2._y + vec1._z * vec2._z);
		}

		// Vector3からVector3型の外積を取得
		// ===============================
		const Vector3& Cross(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			Vector3 v;

			v._x = vec1._y * vec2._z - vec1._z * vec2._y;
			v._y = vec1._z * vec2._x - vec1._x * vec2._z;
			v._z = vec1._x * vec2._y - vec1._y * vec2._x;

			return v;
		}

		// Vector3からVector3同士の差分を取得(Vector3型)
		// ===============================
		const Vector3& Subtract(const Vector3& vec1, const Vector3& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector3間を線形補完してVector2型として返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}

		// Vector3間を線形補完してVector3型として返却
		// ===============================
		const Vector3& Vec3Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept
		{
			return Vector3(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z));
		}
	}

	namespace vector4
	{
		// Vector4からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector4& vec)noexcept
		{
			return (vec._x * vec._x + vec._y * vec._y + vec._z * vec._z + vec._w * vec._w);
		}

		// Vector4の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector4 temp = ko::vector4::Subtract(vec2, vec1);
			return ko::vector4::LengthSq(temp);
		}

		// Vector4からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector4& vec)noexcept
		{
			return sqrtf(vec._x * vec._x + vec._y * vec._y + vec._z * vec._z + vec._w * vec._w);
		}

		// Vector4の2点間の長さを取得
		// ===============================
		const float& Length(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector4 temp = ko::vector4::Subtract(vec2, vec1);
			return ko::vector4::Length(temp);
		}

		// Vector4から正規化したVector4型を取得
		// ===============================
		const Vector4& Normalize(const Vector4& vec)noexcept
		{
			float length = ko::vector4::Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// Vector4からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector4& vec1, const Vector4 vec2)noexcept
		{
			return (vec1._x * vec2._x + vec1._y * vec2._y + vec1._z * vec2._z + vec1._w * vec2._w);
		}

		// Vector4からVector4型の外積を取得
		// 未実装
		// ===============================
		const Vector4& Cross(const Vector4& vec1, const Vector4 vec2)noexcept
		{
			return Vector4::zero;
		}

		// Vector4からVector4同士の差分を取得(Vector4型)
		// ===============================
		const Vector4& Subtract(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector2(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y));
		}

		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector3& Vec3Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector3(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z));
		}

		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector4& Vec4Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept
		{
			return Vector4(vec1._x + t * (vec2._x - vec1._x), vec1._y + t * (vec2._y - vec1._y), vec1._z + t * (vec2._z - vec1._z), vec1._w + t * (vec2._w - vec1._w));
		}
	}

	namespace color
	{
		// 基本的なグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScale(const Color& color)noexcept
		{
			Color temp;
			temp = (color._a * 0.2126f + color._g * 0.7152f + color._b * 0.0722f) / 3;
			return temp;
		}

		// Rを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleR(const Color& color)noexcept
		{
			return Color(color._r, color._r, color._r, color._a);
		}

		// Gを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleG(const Color& color)noexcept
		{
			return Color(color._g, color._g, color._g, color._a);
		}

		// Bを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleB(const Color& color)noexcept
		{
			return Color(color._b, color._b, color._b, color._a);
		}

		// R,G,Bをそれぞれ反転した色を取得
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

		// セピア調の色を取得
		// ===============================
		const Color& KOColorSepia(const Color& color)noexcept
		{
			float Y = 0.299f * color._r + 0.587f * color._g + 0.114f * color._b;

			// セピア調ではモノクロ化とは違い、R,G,Bに明るさをそのまま代入はしない
			// 今回の実装では、赤みの成分に0.9、緑に0.7、bに0.4の重みを乗算している
			Color temp = Color();
			temp._r = Y * 0.9f;
			temp._g = Y * 0.7f;
			temp._b = Y * 0.4f;

			return temp;
		}

		// モノクロ調の色を取得
		// ===============================
		const Color& KOColorMonocrome(const Color& color)noexcept
		{
			// 画像をモノクロに変化させていく
			// ピクセルの明るさを計算する
			float Y = 0.299f * color._r + 0.587 * color._g + 0.114f * color._b;

			Color temp = Color();
			temp = Y;

			return temp;
		}

		// Rの値のみ取得
		// ===============================
		const Color& KOColorRScale(const Color& color)noexcept
		{
			return Color(color._r, 0.0f, 0.0f, color._a);
		}

		// Gの値のみ取得
		// ===============================
		const Color& KOColorGScale(const Color& color)noexcept
		{
			return Color(0.0f, color._g, 0.0f, color._a);
		}

		// Bの値のみ取得
		// ===============================
		const Color& KOCOlorBScale(const Color& color)noexcept
		{
			return Color(0.0f, 0.0f, color._b, color._a);
		}

		// 0.0f～1.0fの値に収めて取得
		// ===============================
		const Color& KOColorSaturate(const Color& color)noexcept
		{
			return ko::koMath::ColorClamp(color, Color::white, Color::black);
		}
	}

	namespace koVector
	{
		// KOVECTORを返り値に引数をセット
		// ===============================
		const KOVECTOR& KOVectorSet(const float& X, const float& Y, const float& Z, const float& W)noexcept
		{
			return KOVECTOR(X, Y, Z, W);
		}

		// KOVECTORから_xFloat,_yFloatを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector2Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat);
		}

		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector3Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat + vec._zFloat * vec._zFloat);
		}

		// KOVECTORから値全てを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector4Length(const KOVECTOR& vec)noexcept
		{
			return sqrtf(vec._xFloat * vec._xFloat + vec._yFloat * vec._yFloat + vec._zFloat * vec._zFloat + vec._wFloat * vec._wFloat);
		}

		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector2Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector2Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// KOVECTORから_xFloat,_yFloat, _zFloatを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector3Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector3Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// KOVECTORから値全てを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector4Normalize(const KOVECTOR& vec)noexcept
		{
			float length = ko::koVector::KOVector4Length(vec);
			if (length != 0)
				return vec / length;
			return vec;
		}

		// 2値のKOVECTORからvec1からvec2を引いた差分をKOVECTOR型で取得
		// ===============================
		const KOVECTOR& KOVectorSubtract(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で内積を取得
		// ===============================
		const KOVECTOR& KOVector2Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しKOVECTOR型で内積を取得
		// ===============================
		const KOVECTOR& KOVector3Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat + vec1._zFloat * vec2._zFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTORから全ての値を取得しKOVECTOR型で内積を取得
		// ===============================
		const KOVECTOR& KOVector4Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			float t = vec1._xFloat * vec2._xFloat + vec1._yFloat * vec2._yFloat + vec1._zFloat * vec2._zFloat + vec1._wFloat * vec2._wFloat;
			KOVECTOR vec;
			vec = t;
			return vec;
		}

		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で外積を取得
		// ===============================
		const KOVECTOR& KOVector2Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			KOVECTOR vec;
			float t = vec1._xFloat * vec2._yFloat - vec1._yFloat * vec2._xFloat;
			vec = t;
			return vec;
		}

		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しKOVECTOR型で外積を取得
		// ===============================
		const KOVECTOR& KOVector3Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			KOVECTOR v;

			v._xFloat = vec1._yFloat * vec2._zFloat - vec1._zFloat * vec2._yFloat;
			v._yFloat = vec1._zFloat * vec2._xFloat - vec1._xFloat * vec2._zFloat;
			v._zFloat = vec1._xFloat * vec2._yFloat - vec1._yFloat * vec2._xFloat;

			return v;
		}

		// KOVECTORから全値を取得しKOVECTOR型で外積を取得
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

		// KOVECTORからX成分をfloat型で取得
		// ===============================
		const float& KOVectorGetXF(const KOVECTOR& vec)noexcept
		{
			return vec._xFloat;
		}

		// KOVECTORからY成分をfloat型で取得
		// ===============================
		const float& KOVectorGetYF(const KOVECTOR& vec)noexcept
		{
			return vec._yFloat;
		}

		// KOVECTORからZ成分をfloat型で取得
		// ===============================
		const float& KOVectorGetZF(const KOVECTOR& vec)noexcept
		{
			return vec._zFloat;
		}

		// KOVECTORからZ成分をfloat型で取得
		// ===============================
		const float& KOVectorGetWF(const KOVECTOR& vec)noexcept
		{
			return vec._wFloat;
		}

		// KOVECTORから否定を計算(DirectX::XMVectorNegate()に準拠)
		// ===============================
		const KOVECTOR& KOVectorNegate(const KOVECTOR& vec)noexcept
		{
			__m128 changeVec;
			__m128 temp;

			for (int index = 0; index < 4; ++index)
			{
				changeVec.m128_f32[index] = vec._vec[index];
			}

			// SIMD命令
			temp = _mm_setzero_ps();

			__m128 resultM = _mm_sub_ps(temp, changeVec);

			KOVECTOR resultVec;
			for (int index = 0; index < 4; ++index)
			{
				resultVec._vec[index] = resultM.m128_f32[index];
			}

			return resultVec;
		}

		// Vector4から否定を計算(DirectX::XMVectorNegate()に準拠)
		// ===============================
		const KOVECTOR& KOVectorNegate(const Vector4& vec)noexcept
		{
			KOVECTOR v;
			v = vec;
			v = ko::koVector::KOVectorNegate(v);
			return v;
		}

		// まぁとりあえずすげぇ関数(DirectX::XMVectorSelect()に準拠)
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

			// SIMD命令
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

		// 全要素が等しいか検出
		// ===============================
		const bool& KOVector4Equal(KOVECTOR& vec1, KOVECTOR& vec2)noexcept
		{
			return vec1 == vec2;
		}

		// 3要素が等しいか検出
		// ===============================
		const bool& KOVector3Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			Vector3 v1, v2;
			v1 = vec1;
			v2 = vec2;

			return v1 == v2;
		}

		// 2要素が等しいか検出
		// ===============================
		const bool& KOVector2Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept
		{
			Vector2 v1, v2;
			v1 = vec1;
			v2 = vec2;

			return v1 == v2;
		}

		// Vector3型からVector3型の正規化ベクトルを取得
		// ===============================
		const Vector3& KOVector3Normalize(const Vector3& vec)noexcept
		{
			Vector3 v;
			v = ko::vector3::Normalize(vec);
			return v;
		}

		// Vector4型からVector3型の正規化ベクトルを取得
		// ===============================
		const Vector3& KOVector3Normalize(const Vector4& vec)noexcept
		{
			Vector3 v;
			v = ko::vector3::Normalize(vec);
			return v;
		}

		// Vector4型からVector4型の正規化ベクトルを取得
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

		// Vector3型からVector4型の正規化ベクトルを取得
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

		// Vector4同士の差分をvector4型で取得
		// ===============================
		const Vector4& KOVectorSubtract(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			return vec1 - vec2;
		}

		// Vector4同士の差分をVector3型で取得
		// ===============================
		const Vector3& KOVectorSubtractVec3(const Vector4& vec1, const Vector4& vec2)noexcept
		{
			Vector3 v1, v2, v3;
			v1 = vec1;
			v2 = vec2;
			v3 = v1 - v2;
			return v3;
		}

		// Vector3同士でVector3の内積を取得
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

		// Vector4同士でVector3の内積を取得
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

		// Vector4同士でVector4の内積を取得
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

		// vector3同士でvector4の内積を取得
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

		// Vector3同士でVector3の外積を取得
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

		// Vector4同士でVector3の外積を取得
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

		// Vector4型3つでVector4型の外積を取得
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

		// Vector3型3つでVector4型の外積を取得
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

		// 3要素が等しいか検出
		// ===============================
		const bool& KOVector3Equal(Vector4& vec1, Vector4& vec2)noexcept
		{
			Vector3 v1, v2;
			v1 = vec1;
			v2 = vec2;
			return v1 == v2;
		}

		// 2要素が等しいか検出
		// ===============================
		const bool& KOVector2Equal(Vector4& vec1, Vector4& vec2)noexcept
		{
			Vector2 v1, v2;
			v1 = vec1;
			v2 = vec2;
			return v1 == v2;
		}

		// 2要素が等しいか検出
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
		// 単位行列を生成
		// ===============================
		const Matrix& KOMatrixIdentity(void)noexcept
		{
			return Matrix::identity;
		}

		// スケールの行列を生成
		// ===============================
		const Matrix& KOMatrixScaling(float scaleX, float scaleY, float scaleZ)noexcept
		{
			return Matrix(scaleX, 0.0f, 0.0f, 0.0f,
				0.0f, scaleY, 0.0f, 0.0f,
				0.0f, 0.0f, scaleZ, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		// Vector3からスケール行列を生成
		// ===============================
		const Matrix& KOMatrixScaling(Vector3 scale)noexcept
		{
			return ko::koMatrix::KOMatrixScaling(scale._x, scale._y, scale._z);
		}

		// 回転行列を生成
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(float rotX, float rotY, float rotZ)noexcept
		{
			ko::Matrix result;

			// 行列の設定
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

		// Vector3から回転行列を生成
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(Vector3 rot)noexcept
		{
			return ko::koMatrix::KOMatrixYawPitchRoll(rot._x, rot._y, rot._z);
		}

		// 移動行列を生成
		// ===============================
		const Matrix& KOMatrixTranslation(float offsetX, float offsetY, float offsetZ)noexcept
		{
			return Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, offsetX, offsetY, offsetZ, 1.0f);
		}

		// Vector3から移動行列を生成
		// ===============================
		const Matrix& KOMatrixTranslation(Vector3 offset)noexcept
		{
			return ko::koMatrix::KOMatrixTranslation(offset._x, offset._y, offset._z);
		}

		// Matrix同士の行列の掛け算を行う
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

		// KOVECTORから視点の向きを利用した左手座標系ビュー行列を生成
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

		// Vector4から視点の向きを利用した左手座標系ビュー行列を生成
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

		// KOVECTORから注視点を利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtLH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR eyeDirection = ko::koVector::KOVectorSubtract(focusPosition, eyePosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, eyeDirection, upDirection);
		}

		// Vector4から注視点を利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtLH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept
		{
			Vector4 eyeDirection = ko::koVector::KOVectorSubtract(focusPosition, eyePosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, eyeDirection, upDirection);
		}

		// KOVECTORから視点の向きを利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookToRH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR NegEyeDirection = ko::koVector::KOVectorNegate(eyeDirection);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, NegEyeDirection, upDirection);
		}

		// KOVECTORから視点の向きを利用した右手座標系ビュー行列を生成
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

		// KOVECTORから注視点を利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtRH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept
		{
			KOVECTOR NegEyeDirection = ko::koVector::KOVectorSubtract(eyePosition, focusPosition);
			return ko::koMatrix::KOMatrixLookToLH(eyePosition, NegEyeDirection, upDirection);
		}

		// Vector4から注視点を利用した右手座標系ビュー行列を生成
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

		// 逆行列を生成
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

		// 透視投影の行列を生成
		// ===============================
		const Matrix& KOMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ)noexcept
		{
			float tanHalfFovY = tanf(fovAngleY * 0.5f);

			float scaleY = 1.0f / tanHalfFovY;
			float scaleX = scaleY / aspectRatio;

			float rangeInv = 1.0f / (farZ - nearZ);

			return Matrix(scaleX, 0.0f, 0.0f, 0.0f, 0.0f, scaleY, 0.0f, 0.0f, 0.0f, 0.0f, farZ * rangeInv, 1.0f, 0.0f, 0.0f, -nearZ * farZ * rangeInv, 0.0f);
		}

		// 平行投影の行列を生成
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

		// 平行投影の行列を生成(Part2)
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

		// 転置行列を生成
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
		// 各要素をmin～maxに収めて取得
		// ===============================
		const Color& ColorClamp(const Color& color, const Color& min, const Color& max)noexcept
		{
			return ko::koMath::ColorMax(min, ko::koMath::ColorMin(color, max));
		}

		// 各要素の小さい値の方で色を取得
		// 同値はcolor1の要素を返却
		// ===============================
		const Color& ColorMin(const Color& color1, const Color& color2)noexcept
		{
			Color temp = Color();
			color1._a <= color2._a ? (temp._a = color1._a) : (temp._a = color2._a);
			color1._g <= color2._g ? (temp._g = color1._g) : (temp._g = color2._g);
			color1._b <= color2._b ? (temp._b = color1._b) : (temp._b = color2._b);
			return temp;
		}

		// 各要素の大きい値の方で色を取得
		// 同値はcolor1の要素を返却
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

			// ビューマトリックスから座標と注視点を取得
			KOVECTOR eye = koVector::KOVectorSet(view._m41, view._m42, view._m43, 1.0f);
			KOVECTOR focus = koVector::KOVectorSet(view._m31 + view._m41, view._m32 + view._m42, view._m33 + view._m43, 1.0f);

			// ビューマトリックスの前方ベクトルからYaw（Y軸回りの回転角）とPitch（X軸回りの回転角）を求める
			KOVECTOR forward = koVector::KOVector3Normalize(focus - eye);
			resultRot._x = asinf(-koVector::KOVectorGetYF(forward));
			resultRot._y = atan2f(koVector::KOVectorGetXF(forward), koVector::KOVectorGetZF(forward));

			// ビューマトリックスの右方向ベクトルからRoll（Z軸回りの回転角）を求める
			KOVECTOR right = koVector::KOVector3Cross(koVector::KOVectorSet(0.0f, 1.0f, 0.0f, 0.0f), forward);
			right = koVector::KOVector3Normalize(right);
			resultRot._z = atan2f(koVector::KOVectorGetYF(right), koVector::KOVectorGetXF(right));

			return resultRot;
		}
	}
}