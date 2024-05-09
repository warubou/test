// ------------------------------------------------------------------------------------------------
// koMath.h								オリジナルベクトル計算数学関数
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
		// Vector2からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector2& vec)noexcept;
		// Vector2の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector2& vec)noexcept;
		// Vector2の2点間の長さを計算
		// ===============================
		const float& Length(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2から正規化したVector2型を取得
		// ===============================
		const Vector2& Normalize(const Vector2& vec)noexcept;
		// Vector3から正規化したVector2型を取得
		// ===============================
		const Vector2& Normalize(const Vector3& vec)noexcept;
		// Vector4から正規化したVector2型を取得
		// ===============================
		const Vector2& Normalize(const Vector4& vec)noexcept;
		// Vector2からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2からfloat型の外積を取得
		// ===============================
		const float& Cross(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2からVector2同士の差分を取得(Vector2型)
		// ===============================
		const Vector2& Subtract(const Vector2& vec1, const Vector2& vec2)noexcept;
		// Vector2間を線形補完して返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector2& vec1, const Vector2& vec2, float t)noexcept;
	}

	namespace vector3
	{
		// Vector3からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector3& vec)noexcept;
		// Vector3の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector3& vec)noexcept;
		// Vector3の2点間の長さを取得
		// ===============================
		const float& Length(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3から正規化したVector3型を取得
		// ===============================
		const Vector3& Normalize(const Vector3& vec)noexcept;
		// Vector4から正規化したVector3型を取得
		// ===============================
		const Vector3& Normalize(const Vector4& vec)noexcept;
		// Vector3からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3からVector3型の外積を取得
		// ===============================
		const Vector3& Cross(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3からVector3同士の差分を取得(Vector3型)
		// ===============================
		const Vector3& Subtract(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3間を線形補完してVector2型として返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept;
		// Vector3間を線形補完してVector3型として返却
		// ===============================
		const Vector3& Vec3Lerp(const Vector3& vec1, const Vector3& vec2, float t)noexcept;
	}

	namespace vector4
	{
		// Vector4からfloat型の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector4& vec)noexcept;
		// Vector4の2点間の長さの2乗を取得
		// ===============================
		const float& LengthSq(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4からfloat型の長さを取得
		// ===============================
		const float& Length(const Vector4& vec)noexcept;
		// Vector4の2点間の長さを取得
		// ===============================
		const float& Length(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4から正規化したVector4型を取得
		// ===============================
		const Vector4& Normalize(const Vector4& vec)noexcept;
		// Vector4からfloat型の内積を取得
		// ===============================
		const float& Dot(const Vector4& vec1, const Vector4 vec2)noexcept;
		// Vector4からVector4型の外積を取得
		// 未実装
		// ===============================
		const Vector4& Cross(const Vector4& vec1, const Vector4 vec2)noexcept;
		// Vector4からVector4同士の差分を取得(Vector4型)
		// ===============================
		const Vector4& Subtract(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector2& Vec2Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector3& Vec3Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
		// Vector4間を線形補完してVector3型として返却
		// ===============================
		const Vector4& Vec4Lerp(const Vector4& vec1, const Vector4& vec2, float t)noexcept;
	}

	namespace color
	{
		// 基本的なグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScale(const Color& color)noexcept;
		// Rを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleR(const Color& color)noexcept;
		// Gを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleG(const Color& color)noexcept;
		// Bを基調としたグレースケールの色を取得
		// ===============================
		const Color& KOColorGrayScaleB(const Color& color)noexcept;
		// R,G,Bをそれぞれ反転した色を取得
		// ===============================
		const Color& KOColorNegapoji(const Color& color)noexcept;
		// セピア調の色を取得
		// ===============================
		const Color& KOColorSepia(const Color& color)noexcept;
		// モノクロ調の色を取得
		// ===============================
		const Color& KOColorMonocrome(const Color& color)noexcept;
		// Rの値のみ取得
		// ===============================
		const Color& KOColorRScale(const Color& color)noexcept;
		// Gの値のみ取得
		// ===============================
		const Color& KOColorGScale(const Color& color)noexcept;
		// Bの値のみ取得
		// ===============================
		const Color& KOCOlorBScale(const Color& color)noexcept;
		// 0.0f～1.0fの値に収めて取得
		// ===============================
		const Color& KOColorSaturate(const Color& color)noexcept;
	}

	namespace koVector
	{
		// KOVECTORを返り値に引数をセット
		// ===============================
		const KOVECTOR& KOVectorSet(const float& X, const float& Y, const float& Z, const float& W)noexcept;
		// KOVECTORから_xFloat,_yFloatを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector2Length(const KOVECTOR& vec)noexcept;
		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector3Length(const KOVECTOR& vec)noexcept;
		// KOVECTORから値全てを取得しfloat型で長さを取得
		// ===============================
		const float& KOVector4Length(const KOVECTOR& vec)noexcept;
		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector2Normalize(const KOVECTOR& vec)noexcept;
		// KOVECTORから_xFloat,_yFloat, _zFloatを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector3Normalize(const KOVECTOR& vec)noexcept;
		// KOVECTORから値全てを取得しKOVECTOR型で正規化を取得
		// ===============================
		const KOVECTOR& KOVector4Normalize(const KOVECTOR& vec)noexcept;
		// 2値のKOVECTORからvec1からvec2を引いた差分をKOVECTOR型で取得
		// ===============================
		const KOVECTOR& KOVectorSubtract(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で内積を取得
		// 全値は全て同じになる
		// ===============================
		const KOVECTOR& KOVector2Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しKOVECTOR型で内積を取得
		// 全値は全て同じになる
		// ===============================
		const KOVECTOR& KOVector3Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから全ての値を取得しKOVECTOR型で内積を取得
		// 全値は全て同じになる
		// ===============================
		const KOVECTOR& KOVector4Dot(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから_xFloat,_yFloatを取得しKOVECTOR型で外積を取得
		// 全値は全て同じになる
		// ===============================
		const KOVECTOR& KOVector2Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから_xFloat,_yFloat,_zFloatを取得しKOVECTOR型で外積を取得
		// ===============================
		const KOVECTOR& KOVector3Cross(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// KOVECTORから全値を取得しKOVECTOR型で外積を取得
		// ===============================
		const KOVECTOR& KOVector4Cross(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& vec3)noexcept;
		// KOVECTORからX成分をfloat型で取得
		// ===============================
		const float& KOVectorGetXF(const KOVECTOR& vec)noexcept;
		// KOVECTORからY成分をfloat型で取得
		// ===============================
		const float& KOVectorGetYF(const KOVECTOR& vec)noexcept;
		// KOVECTORからZ成分をfloat型で取得
		// ===============================
		const float& KOVectorGetZF(const KOVECTOR& vec)noexcept;
		// KOVECTORからZ成分をfloat型で取得
		// ===============================
		const float& KOVectorGetWF(const KOVECTOR& vec)noexcept;
		// KOVECTORから否定を計算(DirectX::XMVectorNegate()に準拠)
		// ===============================
		const KOVECTOR& KOVectorNegate(const KOVECTOR& vec)noexcept;
		// Vector4から否定を計算(DirectX::XMVectorNegate()に準拠)
		// ===============================
		const KOVECTOR& KOVectorNegate(const Vector4& vec)noexcept;
		// まぁとりあえずすげぇ関数(DirectX::XMVectorSelect()に準拠)
		// ===============================
		const KOVECTOR& KOVectorSelect(const KOVECTOR& vec1, const KOVECTOR& vec2, const KOVECTOR& controllVec)noexcept;
		// 全要素が等しいか検出
		// ===============================
		const bool& KOVector4Equal(KOVECTOR& vec1, KOVECTOR& vec2)noexcept;
		// 3要素が等しいか検出
		// ===============================
		const bool& KOVector3Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;
		// 2要素が等しいか検出
		// ===============================
		const bool& KOVector2Equal(const KOVECTOR& vec1, const KOVECTOR& vec2)noexcept;

		// Vector3型からVector3型の正規化ベクトルを取得
		// ===============================
		const Vector3& KOVector3Normalize(const Vector3& vec)noexcept;
		// Vector4型からVector3型の正規化ベクトルを取得
		// _wは無視
		// ===============================
		const Vector3& KOVector3Normalize(const Vector4& vec)noexcept;
		// Vector4型からVector4型の正規化ベクトルを取得
		// ===============================
		const Vector4& KOVector4Normalize(const Vector4& vec)noexcept;
		// Vector3型からVector4型の正規化ベクトルを取得
		// ===============================
		const Vector4& KOVector4Normalize(const Vector3& vec)noexcept;
		// Vector4同士の差分をvector4型で取得
		// ===============================
		const Vector4& KOVectorSubtract(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4同士の差分をVector3型で取得
		// ===============================
		const Vector3& KOVectorSubtractVec3(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector3同士でVector3の内積を取得
		// ===============================
		const Vector3& KOVector3Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector4同士でVector3の内積を取得
		// _wは無視
		// ===============================
		const Vector3& KOVector3Dot(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4同士でVector4の内積を取得
		// ===============================
		const Vector4& KOVector4Dot(const Vector4& vec1, const Vector4& vec2)noexcept;
		// vector3同士でvector4の内積を取得
		// _wは0.0f固定
		// ===============================
		const Vector4& KOVector4Dot(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector3同士でVector3の外積を取得
		// ===============================
		const Vector3& KOVector3Cross(const Vector3& vec1, const Vector3& vec2)noexcept;
		// Vector4同士でVector3の外積を取得
		// _wは無視
		// ===============================
		const Vector3& KOVector3Cross(const Vector4& vec1, const Vector4& vec2)noexcept;
		// Vector4型3つでVector4型の外積を取得
		// ===============================
		const Vector4& KOVector4Cross(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3)noexcept;
		// Vector3型3つでVector4型の外積を取得
		// ===============================
		const Vector4& KOVector4Cross(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3)noexcept;
		// 3要素が等しいか検出
		// ===============================
		const bool& KOVector3Equal(Vector4& vec1, Vector4& vec2)noexcept;
		// 2要素が等しいか検出
		// ===============================
		const bool& KOVector2Equal(Vector4& vec1, Vector4& vec2)noexcept;
		// 2要素が等しいか検出
		// ===============================
		const bool& KOVector2Equal(Vector3& vec1, Vector3& vec2)noexcept;
	}

	namespace koMatrix
	{
		// 単位行列を生成
		// ===============================
		const Matrix& KOMatrixIdentity(void)noexcept;
		// スケールの行列を生成
		// ===============================
		const Matrix& KOMatrixScaling(float scaleX, float scaleY, float scaleZ)noexcept;
		// Vector3からスケール行列を生成
		// ===============================
		const Matrix& KOMatrixScaling(Vector3 scale)noexcept;
		// 回転行列を生成
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(float rotX, float rotY, float rotZ)noexcept;
		// Vector3から回転行列を生成
		// ===============================
		const Matrix& KOMatrixYawPitchRoll(Vector3 rot)noexcept;
		// 移動行列を生成
		// ===============================
		const Matrix& KOMatrixTranslation(float offsetX, float offsetY, float offsetZ)noexcept;
		// Vector3から移動行列を生成
		// ===============================
		const Matrix& KOMatrixTranslation(Vector3 offset)noexcept;
		// Matrix同士の行列の掛け算を行う
		// ===============================
		const Matrix& KOMatrixMultiply(const Matrix& m1, const Matrix& m2)noexcept;
		// KOVECTORから視点の向きを利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookToLH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept;
		// Vector4から視点の向きを利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookToLH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept;
		// KOVECTORから注視点を利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtLH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept;
		// Vector4から注視点を利用した左手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtLH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept;
		// KOVECTORから視点の向きを利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookToRH(const KOVECTOR& eyePosition, const KOVECTOR& eyeDirection, const KOVECTOR& upDirection)noexcept;
		// KOVECTORから視点の向きを利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookToRH(const Vector4& eyePosition, const Vector4& eyeDirection, const Vector4& upDirection)noexcept;
		// KOVECTORから注視点を利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtRH(const KOVECTOR& eyePosition, const KOVECTOR& focusPosition, const KOVECTOR& upDirection)noexcept;
		// Vector4から注視点を利用した右手座標系ビュー行列を生成
		// ===============================
		const Matrix& KOMatrixLookAtRH(const Vector4& eyePosition, const Vector4& focusPosition, const Vector4& upDirection)noexcept;
		// 逆行列を生成
		// ===============================
		const Matrix& KOMatrixInverse(const Matrix& mat)noexcept;
		// 透視投影の行列を生成
		// ===============================
		const Matrix& KOMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ)noexcept;
		// 平行投影の行列を生成
		// ===============================
		const Matrix& KOMatrixOrthographicOffCenterLH(float viewLeft, float viewRight, float viewBottom, float viewTop, float nearZ, float farZ)noexcept;
		// 平行投影の行列を生成(Part2)
		// ===============================
		const Matrix& KOMatrixOrthographicLH(float viewWidth, float viewHeight, float nearZ, float farZ)noexcept;
		// 転置行列を生成
		// ===============================
		const Matrix& KOMatrixTranspose(const Matrix& mat)noexcept;
	}

	namespace koMath
	{
		// 小さいほうを返却。同値はvalue1を返却
		// ===============================
		template<class T>
		const T& Min(const T& value1, const T& value2)noexcept
		{
			return (value1 <= value2) ? value1 : value2;
		}

		// 大きいほうを返却。同値はvalue1を返却
		// ===============================
		template<class T>
		const T& Max(const T& value1, const T& value2)noexcept
		{
			return (value1 >= value2) ? value1 : value2;
		}

		// min,maxの範囲内に調整して返却
		// ===============================
		template<class T>
		const T& Clamp(const T& value, const T& min, const T& max)noexcept
		{
			return Max(min, Min(value, max));
		}

		// 累乗を計算して返却
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
				// 負の指数の場合
				return 1.0 / (value * Pow(value, -count - 1));
			}
		}

		// 絶対値を計算
		// ===============================
		template<class T>
		const T& Abs(const T& value)
		{
			if (value == 0)
				return value;

			return value > 0 ? value : -value;
		}

		// 2値間を線形補完して返却
		// ===============================
		template<class T>
		const T& SingleLerp(const T& start, const T& end, const T& t)
		{
			return start + t * (end - start);
		}

		// 各要素をmin～maxに収めて取得
		// ===============================
		const Color& ColorClamp(const Color& color, const Color& min, const Color& max)noexcept;
		// 各要素の小さい値の方で色を取得
		// 同値はcolor1の要素を返却
		// ===============================
		const Color& ColorMin(const Color& color1, const Color& color2)noexcept;
		// 各要素の大きい値の方で色を取得
		// 同値はcolor1の要素を返却
		// ===============================
		const Color& ColorMax(const Color& color1, const Color& color2)noexcept;

		/// 角度をDegree単位からRadian単位に変換する。
		// ===============================
		const float& DegToRad(const float& deg)noexcept;

		/// 角度をRadian単位からDegree単位に変換する。
		// ===============================
		const float& RadToDeg(const float& rad)noexcept;
		
		// viewMatrixからカメラの回転角を求める
		// ===============================
		const Vector3& ExtractRotationAnglesFromViewMatrix(const Matrix& viewMatrix);
	}
}

#endif // KO_MATH_H_