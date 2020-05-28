#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"

Enemy::Enemy()
{
	Init();
}

Enemy::Enemy(const Vector2F& pos, const Vector2F& size)
{
	_pos = pos;
	_size = size;
	Init();
}

Enemy::~Enemy()
{
}

bool Enemy::Init(void)
{
	_angle = 0.0;
	_exRate = 1.0;

	_alive = true;
	_death = false;

	_speed = { 1,1 };

	return true;
}

void Enemy::Update(void)
{
	Vector2F direction = _playerPos - _pos;
	direction.Normalize();

	direction.x < 0 ? _dir = CHARA_DIR::RIGHT : _dir = CHARA_DIR::LEFT;
	direction.y < 0 ? _dir = CHARA_DIR::UP : _dir = CHARA_DIR::DOWN;

	auto tracking = [&](const CHARA_DIR dir, Vector2F ePos, Vector2F pPos)
	{
		if (_dir == dir)
		{
			if (ePos.x < pPos.x && pPos.x < ePos.x + 32.0f * 3
				|| ePos.y < pPos.y && pPos.y < ePos.y + 32 * 3)
			{
				_pos += direction * _speed;
			}
		}
	};

	tracking(CHARA_DIR::UP, { _pos.x - 32, _pos.y + 32 * 3 }, _playerPos);
	tracking(CHARA_DIR::RIGHT, { _pos.x, _pos.y - 32 }, _playerPos);
	tracking(CHARA_DIR::LEFT, { _pos.x + 32 * 3, _pos.y - 32 }, _playerPos);
	tracking(CHARA_DIR::DOWN, { _pos.x - 32, _pos.y }, _playerPos);
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_pos.x, _pos.y, _exRate, _angle, IMAGE_ID("enemy")[0], true);
}

const Vector2F& Enemy::GetPos(void)
{
	return _pos;
}

void Enemy::SetPos(const Vector2F& pos)
{
	_playerPos = pos;
}

const Vector2F& Enemy::GetSize(void)
{
	return _size;
}

void Enemy::SetSize(const Vector2F& size)
{
	_size = size;
}

const double Enemy::GetAngle(void)
{
	return _angle;
}

void Enemy::SetAngle(const double angle)
{
	_angle = angle;
}

const double Enemy::GetExRate(void)
{
	return _exRate;
}

void Enemy::SetExRate(const double exRate)
{
	_exRate = exRate;
}
