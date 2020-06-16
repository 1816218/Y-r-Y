#include <DxLib.h>
#include "Player.h"
#include "Scene/SceneMng.h"
#include "ImageMng.h"
#include "Map.h"

Player::Player()
{
	Init();
}

Player::Player(const Vector2F& pos, const Vector2F& size)
{
	_pos = pos;
	_size = size;
	Init();
}

Player::~Player()
{
}

bool Player::Init(void)
{
	_angle = 0.0;
	_exRate = 1.0;
	_alive = true;
	_death = false;

	_animCnt = 0;
	_moveFlag = false;
	_direction = CHARA_DIR::DOWN;
	_edg = { Vector2F(-_size.x / 2, -_size.y / 4),
			 Vector2F(_size.x / 2, -_size.y / 4),
			 Vector2F(-_size.x / 2, _size.y / 2),
			 Vector2F(_size.x / 2, _size.y / 2)};
	_speed = 1.5f;
	return true;
}

void Player::Update(void)
{
	_moveFlag = false;

	Move();
}
//-----描画
void Player::Draw(void)
{
	//-----アニメーション
	//動いている状態のときは
	//アニメーションカウントを増やす
	_moveFlag != false ? _animCnt++ : _animCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, _exRate, _angle, IMAGE_ID("player")[(static_cast<int>(_direction) * 4) + (_animCnt / 20 % 4)], true);
}
//-----移動処理
void Player::Move(void)
{
	_moveFlag = false;

	//衝突していなかったら移動する
	AddMove(_1P_UP,		CHARA_DIR::UP,		{       0, -_speed });
	AddMove(_1P_RIGHT,	CHARA_DIR::RIGHT,	{  _speed,       0 });
	AddMove(_1P_LEFT,	CHARA_DIR::LEFT,	{ -_speed,       0 });
	AddMove(_1P_DOWN,	CHARA_DIR::DOWN,	{       0,  _speed });
}

//-----Get・Set
//座標
const Vector2F& Player::GetPos(void)
{
	return _pos;
}

void Player::SetPos(const Vector2F& pos)
{
	_pos = pos;
}
//サイズ
const Vector2F& Player::GetSize(void)
{
	return _size;
}

void Player::SetSize(const Vector2F& size)
{
	_size = size;
}
//角度
const double Player::GetAngle(void)
{
	return _angle;
}

void Player::SetAngle(const double angle)
{
	_angle = angle;
}
//拡大率
const double Player::GetExRate(void)
{
	return _exRate;
}

void Player::SetExRate(const double exRate)
{
	_exRate = exRate;
}
//-----移動量の加算
void Player::AddMove(const KEY_CODE& key, const CHARA_DIR& dir, const Vector2F& add)
{
	Vector2F movePos = _pos;

	//衝突判定する箇所が一つでも当たっていた場合は真を返す
	auto hitFlag = [&](const Vector2F& move)
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

	if (lpInputKey.newKey[key])
	{
		_moveFlag = true;
		_direction = dir;
		movePos += add;

		if (hitFlag(movePos))
		{
			_pos = movePos - add;	//めり込んだ分戻す
		}
		else
		{
			_pos = movePos;	//移動
		}
	}
}

