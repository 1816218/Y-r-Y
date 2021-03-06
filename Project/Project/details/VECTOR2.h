#pragma once
#include "../VECTOR2.h"
#include <cmath>
template<class T>
Vector2Temple<T>::Vector2Temple()
{
	x = 0;
	y = 0;
}

template<class T>
Vector2Temple<T>::Vector2Temple(T x, T y)
{
	// thisﾎﾟｲﾝﾀから辿る(thisは実体)
	this->x = x;
	this->y = y;
}

template<class T>
Vector2Temple<T>::~Vector2Temple()
{
}

// 代入演算子
template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator=(const Vector2Temple<T> & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;	// 参照返し
}

// 添え字演算子
template<class T>
int & Vector2Temple<T>::operator[](int i)
{
	if (i == 0) 
	{
		return x;
	}
	else if(i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

// 比較演算子
template<class T>
bool Vector2Temple<T>::operator==(const Vector2Temple<T> & vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

template<class T>
bool Vector2Temple<T>::operator!=(const Vector2Temple<T> & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}

template<class T>
bool Vector2Temple<T>::operator<=(const Vector2Temple<T> & vec) const
{
	return ((this->x <= x) && (this->y <= y));
}

template<class T>
bool Vector2Temple<T>::operator<(const Vector2Temple<T> & vec) const
{
	return ((this->x < x) && (this->y < y));
}

template<class T>
bool Vector2Temple<T>::operator>=(const Vector2Temple<T> & vec) const
{
	return ((this->x >= x) && (this->y >= y));
}

template<class T>
bool Vector2Temple<T>::operator>(const Vector2Temple<T> & vec) const
{
	return ((this->x > x) && (this->y > y));
}

// 単項演算子
// とりあえず返り値を返す (比較したりするときなどに使える)
template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator+=(const Vector2Temple<T> & vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return (*this);
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator-=(const Vector2Temple<T> & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return (*this);
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator*=(T k)
{
	this->x *= k;
	this->y *= k;
	return (*this);
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator/=(T k)
{
	this->x /= k;
	this->y /= k;
	return (*this);
}

// プラスを掛ける
template<class T>
Vector2Temple<T> Vector2Temple<T>::operator+() const
{
	return *this;
}

// マイナスを掛ける
template<class T>
Vector2Temple<T> Vector2Temple<T>::operator-() const
{
	return Vector2Temple<T>(-this->x, -this->y);
}

template<class T>
float Vector2Temple<T>::Magnitude() const
{
	return hypot(this->x, this->y);
}

template<class T>
void Vector2Temple<T>::Normalize()
{
	float mag = Magnitude();
	this->x /= mag;
	this->y /= mag;
}

template<class T>
Vector2Temple<T> Vector2Temple<T>::Normalized()
{
	float mag = Magnitude();
	return Vector2Temple<T>(this->x / mag, this->x / mag);
}

// ベクトルの演算
// 参照で渡した瞬間は値を保持しているが渡した後は保持している保証はないからコピーで渡す
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T> & u, T v)
{
	return Vector2Temple<T>(u.x + v, u.y + v);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T> & u, const T v)
{
	return Vector2Temple<T>(u.x - v, u.y - v);
}

template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T> & u, const Vector2Temple<T> & v)
{
	return Vector2Temple<T>(u.x + v.x, u.y + v.y);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T> & u, const Vector2Temple<T> & v)
{
	return Vector2Temple<T>(u.x - v.x, u.y - v.y);
}

template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& u, const Vector2Temple<T>& v)
{
	return Vector2Temple<T>(u.x * v.x, u.y * v.y);
}

template<class T>
Vector2Temple<T> operator*(const T k, const Vector2Temple<T> & v)
{
	return Vector2Temple<T>(k * v.x, k * v.y);
}

template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T> & v, const T k)
{
	return Vector2Temple<T>(v.x * k, v.y * k);
}

template<class T>
Vector2Temple<T> operator/(const Vector2Temple<T> & v, const T k)
{
	return Vector2Temple<T>(v.x / k, v.y / k);
}

template<class T>
Vector2Temple<T> operator%(const Vector2Temple<T> & v, const T k)
{
	return Vector2Temple<T>(v.x % k, v.y % k);
}
