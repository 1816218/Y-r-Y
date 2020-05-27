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
	// this�߲������H��(this�͎���)
	this->x = x;
	this->y = y;
}

template<class T>
Vector2Temple<T>::~Vector2Temple()
{
}

// ������Z�q
template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator=(const Vector2Temple<T> & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;	// �Q�ƕԂ�
}

// �Y�������Z�q
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

// ��r���Z�q
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

// �P�����Z�q
// �Ƃ肠�����Ԃ�l��Ԃ� (��r�����肷��Ƃ��ȂǂɎg����)
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

// �v���X���|����
template<class T>
Vector2Temple<T> Vector2Temple<T>::operator+() const
{
	return *this;
}

// �}�C�i�X���|����
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

// �x�N�g���̉��Z
// �Q�Ƃœn�����u�Ԃ͒l��ێ����Ă��邪�n������͕ێ����Ă���ۏ؂͂Ȃ�����R�s�[�œn��
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
