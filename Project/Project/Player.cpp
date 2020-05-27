#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"

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

	_moveFlag = false;
	_direction = CHARA_DIR::DOWN;
	_animCnt = 0;
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
	auto move = [&](bool flag, const CHARA_DIR& dir, const Vector2F& speed)
	{
		if (!flag)
		{
			_moveFlag = true;
		}

		if (_direction != dir)
		{
			_direction = dir;
		}
		_pos += speed;
	};

	//キー入力による移動
	if (lpInputKey.newKey[KEY_CODE::KEY_UP])
	{
		if (!lpMap.Collision(_pos, { 0, 0 }))
		{
			move(_moveFlag, CHARA_DIR::UP, { 0, -1 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_RIGHT])
	{
		if (!lpMap.Collision(_pos, { 16, 0 }))
		{
			move(_moveFlag, CHARA_DIR::RIGHT, { 1, 0 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_LEFT])
	{
		if (!lpMap.Collision(_pos, { -16, 0 }))
		{
			move(_moveFlag, CHARA_DIR::LEFT, { -1, 0 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_DOWN])
	{
		if (!lpMap.Collision(_pos, { 0, 16 }))
		{
			move(_moveFlag, CHARA_DIR::DOWN, { 0, 1 });
		}
	}
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


