#pragma once

// ΝήΈΔΩπ΅€ΈΧ½
// ΈΧ½ΓέΜίΪ°Δ
template<class T> class Vector2Temple
{
public:
	Vector2Temple();
	Vector2Temple(T x, T y);
	~Vector2Temple();
	T x;	// XΐW
	T y;	// YΐW

	// ΅°Κή°Ϋ°Δή
	// γόZq
	Vector2Temple& operator = (const Vector2Temple& vec);

	// Y¦Zq
	int& operator[](int i);

	// δrZq
	bool operator==(const Vector2Temple& vec) const;
	bool operator!=(const Vector2Temple& vec) const;
	bool operator<=(const Vector2Temple& vec) const;
	bool operator<(const Vector2Temple& vec) const;
	bool operator>=(const Vector2Temple& vec) const;
	bool operator>(const Vector2Temple& vec) const;

	// PZq
	Vector2Temple& operator+=(const Vector2Temple& vec);
	Vector2Temple& operator-=(const Vector2Temple& vec);
	Vector2Temple& operator*=(T k);
	Vector2Temple& operator/=(T k);
	Vector2Temple operator+() const;	// vXπ|―ι
	Vector2Temple operator-() const;	// }CiXπ|―ι
};

// xNgΜZ
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