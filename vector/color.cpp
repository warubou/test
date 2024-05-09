// ------------------------------------------------------------------------------------------------
// color.cpp								オリジナルベクトル(Color)
// Date 2023/12/26
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#include "color.h"

namespace ko
{
	// =====================================
	// Color
	// =====================================

	// 静的変数の初期化
	// =====================================
	// Color(1.0f,1.0f,1.0f,1.0f)を取得
	// ===============================
	const Color Color::white = Color(1.0f, 1.0f, 1.0f, 1.0f);
	// Color(0.0f,0.0f,0.0f,1.0f)を取得
	// ===============================
	const Color Color::black = Color(0.0f, 0.0f, 0.0f, 1.0f);
	// Color(1.0f,0.0f,0.0f,1.0f)を取得
	// ===============================
	const Color Color::red = Color(1.0f, 0.0f, 0.0f, 1.0f);
	// Color(0.0f,1.0f,0.0f,1.0f)を取得
	// ===============================
	const Color Color::green = Color(0.0f, 1.0f, 0.0f, 1.0f);
	// Color(0.0f,0.0f,1.0f,1.0f)を取得
	// ===============================
	const Color Color::blue = Color(0.0f, 0.0f, 1.0f, 1.0f);
	// Color(1.0f,0.0f,1.0f,1.0f)を取得
	// ===============================
	const Color Color::mazenta = Color(1.0f, 0.0f, 1.0f, 1.0f);
	// Color(0.0f,1.0f,1.0f,1.0f)を取得
	// ===============================
	const Color Color::syan = Color(0.0f, 1.0f, 1.0f, 1.0f);
	// Color(1.0f,1.0f,0.0f,1.0f)を取得
	// ===============================
	const Color Color::yellow = Color(1.0f, 1.0f, 0.0f, 1.0f);

	// Color + Color
	// ===============================
	Color Color::operator+(const Color& color)const
	{
		return Color(_x + color._x, _y + color._y, _z + color._z, _w + color._w);
	}

	// Color - Color
	// ===============================
	Color Color::operator-(const Color& color)const
	{
		return Color(_x - color._x, _y - color._y, _z - color._z, _w - color._w);
	}

	// Color * Color
	// ===============================
	Color Color::operator*(const Color& color)const
	{
		return Color(_x * color._x, _y * color._y, _z * color._z, _w * color._w);
	}

	// Color / Color
	// ===============================
	Color Color::operator/(const Color& color)const
	{
		return Color(_x / color._x, _y / color._y, _z / color._z, _w / color._w);
	}

	// Color += Color
	// ===============================
	Color& Color::operator+=(const Color& color)
	{
		_x += color._x;
		_y += color._y;
		_z += color._z;
		_w += color._w;
		return *this;
	}

	// Color -= Color
	// ===============================
	Color& Color::operator-=(const Color& color)
	{
		_x -= color._x;
		_y -= color._y;
		_z -= color._z;
		_w -= color._w;
		return *this;
	}

	// Color *= Color
	// ===============================
	Color& Color::operator*=(const Color& color)
	{
		_x *= color._x;
		_y *= color._y;
		_z *= color._z;
		_w *= color._w;
		return *this;
	}

	// Color /= Color
	// ===============================
	Color& Color::operator/=(const Color& color)
	{
		_x /= color._x;
		_y /= color._y;
		_z /= color._z;
		_w /= color._w;
		return *this;
	}

	// if(Color == Color)
	// ===============================
	bool Color::operator== (const Color& color)const
	{
		return (_x == color._x && _y == color._y && _z == color._z && _w == color._w);
	}

	// if(Color != Color)
	// ===============================
	bool Color::operator!= (const Color& color)const
	{
		return (_x != color._x && _y != color._y && _z != color._z && _w != color._w);
	}

	// Color = Color
	// ===============================
	Color& Color::operator= (const Color& color)
	{
		_r = color._r;
		_g = color._g;
		_b = color._b;
		_a = color._a;
		return *this;
	}

	// Color = float
	// ===============================
	Color& Color::operator= (const float t)
	{
		_a = t;
		_g = t;
		_b = t;
		return *this;
	}
}