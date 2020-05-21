#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include"main.h"
#include"HitCheck.h"
Player::Player()
{
	Init();
}

Player::~Player()
{

}

void Player::Init(void)
{
	_pos = {SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2};
	_dir = DIR_DOWN;
	_speed = { 0,0 };
	_moveFlag = false;
	_animeCnt = 0;
	_size = { 32,32 };

}

void Player::Update(void)
{
	SetMove(KEY_UP,    DIR_UP,    {  0, -0.5 }, true);
	SetMove(KEY_RIGHT, DIR_RIGHT, { 0.5,  0 }, true);
	SetMove(KEY_LEFT,  DIR_LEFT,  { -0.5,  0 }, true);
	SetMove(KEY_DOWN,  DIR_DOWN,  {  0,  0.5 }, true);
	/*
	SetMove(_1P_UP, DIR_UP, { 0, -2 }, true);
	SetMove(_1P_RIGHT, DIR_RIGHT, { 2,  0 }, true);
	SetMove(_1P_LEFT, DIR_LEFT, { -2,  0 }, true);
	SetMove(_1P_DOWN, DIR_DOWN, { 0,  2 }, true);
<<<<<<< HEAD
	if (_pos.x < 0+48)
=======
	*/
	if (_pos.x < 0+16)
>>>>>>> bdb3d1291db9210f6e0411fef9329f7f7fd71acf
	{
		_pos.x = 0+48;
	}
	if (_pos.x > SCREEN_SIZE_X-48)
	{
		_pos.x = SCREEN_SIZE_X-48;
	}
	if (_pos.y < 0+144)
	{
		_pos.y = 0+144;
	}
	if (_pos.y > SCREEN_SIZE_Y-48)
	{
		_pos.y = SCREEN_SIZE_Y-48;
	}

	Draw();
}

void Player::Draw(void)
{
	//アニメーション
	_moveFlag != false ? _animeCnt++ : _animeCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, 1, 0,
		ImageMng::GetInstance().SetID("image/player.png", { _size.x,_size.y }, { 5,4 })[(_dir * 5) + (_animeCnt / 20 % 5)], true);

}

void Player::SetMove(const KEY_CODE& key, const P_DIR& dir, const Vector2F& speed, bool flg)
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
}

Vector2F& Player::GetPos(void)
{
	return _pos;
}



