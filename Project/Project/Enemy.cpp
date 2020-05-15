#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"

Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
}

bool Enemy::Init(void)
{
	_pos = { 0.0f, 0.0f };
	_speed = 0.0f;

	return false;
}

void Enemy::UpDate(void)
{
	if (_pos.x < _playerPos.x)
	{
		_pos.x++;
	}

	if (_pos.y < _playerPos.y)
	{
		_pos.y++;
	}

}

void Enemy::Draw(void)
{
	DrawBox(_pos.x - 15, _pos.y - 15, _pos.x + 15, _pos.y + 15, GetColor(255, 0, 0), true);
}

void Enemy::SetPos(Vector2& pos)
{
	_playerPos = pos;
}
