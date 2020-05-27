#pragma once

// ﾍﾞｸﾄﾙを扱うｸﾗｽ
// ｸﾗｽﾃﾝﾌﾟﾚｰﾄ
template<class T> class Vector2Temple
{
public:
	Vector2Temple();
	Vector2Temple(T x, T y);
	~Vector2Temple();
	T x;	// X座標
	T y;	// Y座標

	// ｵｰﾊﾞｰﾛｰﾄﾞ
	// 代入演算子
	Vector2Temple& operator = (const Vector2Temple& vec);

	// 添え字演算子
	int& operator[](int i);

	// 比較演算子
	bool operator==(const Vector2Temple& vec) const;
	bool operator!=(const Vector2Temple& vec) const;
	bool operator<=(const Vector2Temple& vec) const;
	bool operator<(const Vector2Temple& vec) const;
	bool operator>=(const Vector2Temple& vec) const;
	bool operator>(const Vector2Temple& vec) const;

	// 単項演算子
	Vector2Temple& operator+=(const Vector2Temple& vec);
	Vector2Temple& operator-=(const Vector2Temple& vec);
	Vector2Temple& operator*=(T k);
	Vector2Temple& operator/=(T k);
	Vector2Temple operator+() const;	// プラスを掛ける
	Vector2Temple operator-() const;	// マイナスを掛ける

	///ベクトルの大きさを返します
	float Magnitude()const;

	///正規化(大きさを１に)します
	void Normalize();

	///正規化ベクトルを返します
	Vector2Temple<T> Normalized();
};

// ベクトルの演算
// Vector2Temple + int
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& u, const T v);
// Vector2Temple - int
template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& u, const T v);
// Vector2Temple + Vector2Temple
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& u, const Vector2Temple<T>& v);
// Vector2Temple - Vector2Temple
template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& u, const Vector2Temple<T>& v);
// Vector2Temple * Vector2Temple
template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& u, const Vector2Temple<T>& v);
// int * Vector2Temple
template<class T>
Vector2Temple<T> operator*(const T k, const Vector2Temple<T>& v);
// Vector2Temple * int
template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& v, const T k);
// Vector2Temple / int
template<class T>
Vector2Temple<T> operator/(const Vector2Temple<T>& v, const T k);
// Vector2Temple % int
template<class T>
Vector2Temple<T> operator%(const Vector2Temple<T>& v, const T k);

using Vector2 = Vector2Temple<int>;
using Vector2Dbl = Vector2Temple<double>;
using Vector2F = Vector2Temple<float>;

#include "./details/VECTOR2.h"