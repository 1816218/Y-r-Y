#include "Obj.h"

Obj::Obj()
{
	Init();
}

Obj::~Obj()
{
}

bool Obj::Init(void)
{
	_pos = { 0.0f, 0.0f };
	_size = { 0.0f, 0.0f };
	_exRate = 1.0;
	_angle = 0.0;
	_alive = true;
	_death = false;
	return true;
}

void Obj::Update(void)
{
}

void Obj::DrawRotaF(int GHandle, int TransFlag)
{
	DrawRotaGraphF(_pos.x, _pos.y, _exRate, _angle, GHandle, TransFlag);
}

bool Obj::DeathPro(void)
{
	//ê∂Ç´ÇƒÇ¢ÇÈÇ∆Ç´ÇÕéÄÇÒÇ≈Ç¢ÇÈèÛë‘Ç…ÇµÇ»Ç¢
	if (_alive)
	{
		return false;
	}

	//éÄÇÒÇ≈Ç¢ÇÈèÛë‘Ç…Ç∑ÇÈ
	_death = true;

	return true;
}

const Vector2F& Obj::GetPos(void)
{
	return _pos;
}

void Obj::SetPos(const Vector2F& pos)
{
	_pos = pos;
}

const Vector2F& Obj::GetSize(void)
{
	return _size;
}

void Obj::SetSize(const Vector2F& size)
{
	_size = size;
}

const double Obj::GetAngle(void)
{
	return _angle;
}

void Obj::SetAngle(const double angle)
{
	_angle = angle;
}

const double Obj::GetExRate(void)
{
	return _exRate;
}

void Obj::SetExRate(const double exRate)
{
	_exRate = exRate;
}
