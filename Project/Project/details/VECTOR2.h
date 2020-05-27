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
	// thisÎß²İÀ‚©‚ç’H‚é(this‚ÍÀ‘Ì)
	this->x = x;
	this->y = y;
}

template<class T>
Vector2Temple<T>::~Vector2Temple()
{
}

// ‘ã“ü‰‰Zq
template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator=(const Vector2Temple<T> & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;	// QÆ•Ô‚µ
}

// “Y‚¦š‰‰Zq
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

// ”äŠr‰‰Zq
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

// ’P€‰‰Zq
// ‚Æ‚è‚ ‚¦‚¸•Ô‚è’l‚ğ•Ô‚· (”äŠr‚µ‚½‚è‚·‚é‚Æ‚«‚È‚Ç‚Ég‚¦‚é)
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

// ƒvƒ‰ƒX‚ğŠ|‚¯‚é
template<class T>
Vector2Temple<T> Vector2Temple<T>::operator+() const
{
	return *this;
}

// ƒ}ƒCƒiƒX‚ğŠ|‚¯‚é
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

// ƒxƒNƒgƒ‹‚Ì‰‰Z
// QÆ‚Å“n‚µ‚½uŠÔ‚Í’l‚ğ•Û‚µ‚Ä‚¢‚é‚ª“n‚µ‚½Œã‚Í•Û‚µ‚Ä‚¢‚é•ÛØ‚Í‚È‚¢‚©‚çƒRƒs[‚Å“n‚·
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
