#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"

#define PI 3.141592653589793

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
	_dir = CHARA_DIR::DOWN;
	_moveFlag = false;
	_animCnt = 0;
	_animDir = _dir;

	return true;
}

void Enemy::Update(void)
{
	_moveFlag = false;

	//プレイヤーと敵との距離を計算
	Vector2F direction = _playerPos - _pos;
	//正規化
	direction.Normalize();

	//角度を求める計算
	double radian = atan2(direction.y, direction.x);
	double degree = radian * 180.0 / PI;

	//角度に応じで敵の向きを決める
	if (45 <= degree && degree < 135)
	{
		_dir = CHARA_DIR::DOWN;
	}
	else if (135 <= degree && degree < 225)
	{
		_dir = CHARA_DIR::LEFT;
	}
	else if (-135 <= degree && degree < -45)
	{
		_dir = CHARA_DIR::UP;
	}
	else if (-45 <= degree && degree < 45)
	{
		_dir = CHARA_DIR::RIGHT;
	}

	//移動方向上の範囲内にプレイヤーがいたら追いかける
	auto tracking = [&](const CHARA_DIR dir, Vector2F ePos, Vector2F pPos)
	{
		if (_dir == dir)
		{
			DrawBox(ePos.x, ePos.y, ePos.x + 32 * 3, ePos.y + 32 * 3, 0xffffff, false);
			if (ePos.x < pPos.x && pPos.x < ePos.x + 32.0f * 3
				&& ePos.y < pPos.y && pPos.y < ePos.y + 32 * 3)
			{
				_pos += direction * _speed;
				_animDir = _dir;
				_moveFlag = true;
			}
		}
	};

	tracking(CHARA_DIR::UP, { _pos.x - 48, _pos.y - 32 * 3 }, _playerPos);
	tracking(CHARA_DIR::RIGHT, { _pos.x, _pos.y - 48 }, _playerPos);
	tracking(CHARA_DIR::LEFT, { _pos.x - 32 * 3, _pos.y - 48 }, _playerPos);
	tracking(CHARA_DIR::DOWN, { _pos.x - 48, _pos.y }, _playerPos);
}

void Enemy::Draw(void)
{
	_moveFlag != false ? _animCnt++ : _animCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, _exRate, _angle, IMAGE_ID("enemy")[(static_cast<int>(_animDir) * 4) + (_animCnt / 20 % 4)], true);
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
