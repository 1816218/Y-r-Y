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
	//アニメーション
	_moveFlag != false ? _animeCnt++ : _animeCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, 1, 0, 
		ImageMng::GetInstance().SetID("image/player2.png", { 32,32 }, { 4,4 })[(_dir*4) + (_animeCnt/4%4)], true);
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



bool Player::IntersectRectRect(int _x1, int _y1, int _w1, int _h1, int _x2, int _y2, int _w2, int _h2)
{
	if (
		(_x1 <= _x2 + _w2)  //・・・①
		&& (_x1 + _w1 >= _x2)  //・・・② 
		&& (_y1 <= _y2 + _h2)  //・・・③ 
		&& (_y1 + _h1 >= _y2)  //・・・④
		)
	{
		return true;
	}
	return false;
}

Vector2F& Player::GetPos(void)
{
	return _pos;
}



