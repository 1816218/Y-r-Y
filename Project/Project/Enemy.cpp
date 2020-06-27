#include <DxLib.h>
#include "Enemy.h"
#include "ImageMng.h"
#include "Map.h"

const float PI = 3.141592653589793f;	//円周率(16桁)

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

	_edg = { Vector2F(-_size.x / 2, -_size.y / 4),
			 Vector2F( _size.x / 2, -_size.y / 4),
			 Vector2F(-_size.x / 2,  _size.y / 2),
			 Vector2F( _size.x / 2,  _size.y / 2) };

	return true;
}

void Enemy::Update(void)
{
	_moveFlag = false;

	//プレイヤーと敵との距離を計算
	Vector2F distance = _playerPos - _pos;
	//正規化
	distance.Normalize();

	//角度を求める計算
	double radian = atan2(distance.y, distance.x);
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
	SetMove(CHARA_DIR::UP, { _pos.x - 48, _pos.y - 32 * 3 }, _playerPos);
	SetMove(CHARA_DIR::RIGHT, { _pos.x, _pos.y - 48 }, _playerPos);
	SetMove(CHARA_DIR::LEFT, { _pos.x - 32 * 3, _pos.y - 48 }, _playerPos);
	SetMove(CHARA_DIR::DOWN, { _pos.x - 48, _pos.y }, _playerPos);
	//エネミーに接触したらゲームオーバーに遷移
	if (_pos.x-16<_playerPos.x&&_playerPos.x<_pos.x+16&&_pos.y-16<_playerPos.y&&_playerPos.y < _pos.y+16)
	{
		lpSceneMng.SetSceneID(SCN_ID::OVER);
	}
}

void Enemy::Draw(void)
{
	_moveFlag != false ? _animCnt++ : _animCnt = 0;

	DrawRotaGraphF( _pos.x - lpMap.GetScrooll().x,
					_pos.y - lpMap.GetScrooll().y,
					_exRate, _angle, IMAGE_ID("enemy")[(static_cast<int>(_dir) * 4) + (_animCnt / 20 % 4)], true);
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

void Enemy::SetMove(const CHARA_DIR& dir, const Vector2F& ePos, const Vector2F& pPos)
{
	Vector2F move = _pos;
	Vector2F distance = pPos - _pos;
	distance.Normalize();

	auto flag = [&]()
	{
		for (auto edg : _edg)
		{
			if (lpMap.Collision(move, edg))
			{
				return true;
			}
		}
		return false;
	};

	if (_dir == dir)
	{
		if (ePos.x < pPos.x && pPos.x < ePos.x + 32.0f * 3
			&& ePos.y < pPos.y && pPos.y < ePos.y + 32 * 3)
		{
			_moveFlag = true;
			move += distance * _speed;
			if (flag())
			{
				_pos = move;
			}
			else
			{
				_pos = move - (distance * _speed);
			}
		}
	}
}
