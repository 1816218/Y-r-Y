#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::Init(void)
{
	_pos = {800 / 2, 640 / 2};
	_dir = DIR_DOWN;
	_speed = { 0,0 };
	_moveFlag = false;
	_animeCnt = 0;
}

void Player::Update(void)
{
	SetMove(KEY_UP,    DIR_UP,    {  0, -2 }, true);
	SetMove(KEY_RIGHT, DIR_RIGHT, {  2,  0 }, true);
	SetMove(KEY_LEFT,  DIR_LEFT,  { -2,  0 }, true);
	SetMove(KEY_DOWN,  DIR_DOWN,  {  0,  2 }, true);

	Draw();
}

void Player::Draw(void)
{
	_moveFlag != false ? _animeCnt++ : _animeCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, 1, 0, 
		ImageMng::GetInstance().SetID("image/player2.png", { 32,32 }, { 4,4 })[(_dir*4) + (_animeCnt/4%4)], true);
}

Vector2F& Player::SetMove(const KEY_CODE& key, const P_DIR& dir, const Vector2F& speed, bool flg)
{
	if (lpInputKey.newKey[key])
	{
		_dir = dir;
		_moveFlag = flg;
		_speed = speed;
		_pos += _speed;
	}
	else if(lpInputKey.upKey[key])
	{
		_speed = { 0,0 };
		_moveFlag = false;
	}
	return _speed;
}

Vector2F& Player::GetPos(void)
{
	return _pos;
}


