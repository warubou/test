// ------------------------------------------------------------------------------------------------
// color.h								オリジナルベクトル(Color)
// Date 2023/12/26
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef COLOR_H_
#define COLOR_H_

namespace ko
{
	// ========================================
	// Color
	// ========================================
	struct Color
	{
		union {
			float _color[4];
			struct {
				float _r, _g, _b, _a;
			};

			struct {
				float _x, _y, _z, _w;
			};
		};

		// コンストラクタ
		// ===============================
		Color() :Color(1.0f, 1.0f, 1.0f, 1.0f) {}
		Color(float R, float G, float B, float A) :_r(R), _g(G), _b(B), _a(A) {}
		Color(unsigned int color) {
			_r = static_cast<float>((color & 0xFF0000) >> 16) / 255.0f;
			_g = static_cast<float>((color & 0x00FF00) >> 8) / 255.0f;
			_b = static_cast<float>(color & 0x0000FF) / 255.0f;
			_a = 1.0f;
		}

		// Color + Color
		// ===============================
		Color operator+(const Color& color)const;
		// Color - Color
		// ===============================
		Color operator-(const Color& color)const;
		// Color * Color
		// ===============================
		Color operator*(const Color& color)const;
		// Color / Color
		// ===============================
		Color operator/(const Color& color)const;

		// Color += Color
		// ===============================
		Color& operator+=(const Color& color);
		// Color -= Color
		// ===============================
		Color& operator-=(const Color& color);
		// Color *= Color
		// ===============================
		Color& operator*=(const Color& color);
		// Color /= Color
		// ===============================
		Color& operator/=(const Color& color);

		// if(Color == Color)
		// ===============================
		bool operator== (const Color& color)const;
		// if(Color != Color)
		// ===============================
		bool operator!= (const Color& color)const;

		// Color = Color
		// ===============================
		Color& operator= (const Color& color);
		// Color = float
		// ===============================
		Color& operator= (const float t);

		// Color(1.0f,1.0f,1.0f,1.0f)を取得
		// ===============================
		static const Color white;
		// Color(0.0f,0.0f,0.0f,1.0f)を取得
		// ===============================
		static const Color black;
		// Color(1.0f,0.0f,0.0f,1.0f)を取得
		// ===============================
		static const Color red;
		// Color(0.0f,1.0f,0.0f,1.0f)を取得
		// ===============================
		static const Color green;
		// Color(0.0f,0.0f,1.0f,1.0f)を取得
		// ===============================
		static const Color blue;
		// Color(1.0f,0.0f,1.0f,1.0f)を取得
		// ===============================
		static const Color mazenta;
		// Color(0.0f,1.0f,1.0f,1.0f)を取得
		// ===============================
		static const Color syan;
		// Color(1.0f,1.0f,0.0f,1.0f)を取得
		// ===============================
		static const Color yellow;
	};
}

#endif // COLOR_H_