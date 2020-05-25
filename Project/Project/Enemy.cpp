#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"
#include "Scene/TitleScene.h"
#include"HitCheck.h"
#include"main.h"

Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
}

bool Enemy::Init(void)
{
	for (int i = 0; i < 100; i++)
	{

		_pos.x = GetRand(SCREEN_SIZE_X - _size.x);
		_pos.y = GetRand(SCREEN_SIZE_Y - _size.y);
		_speed.x = 0.0f;
		_speed.y = 0.0f;
		_Flag = false;
		_size = { 32,32 };
		_moveFlag = false;
		_animeCnt = 0;
		_scale = 0;
		_dir = EDIR_DOWN;
	}	
	return false;

}

void Enemy::Update(void)
{

	//// GetRand(_pos.x);
	//if (EnemyCnt % 60 == 0)
	//{
	//	for (int i = 0; i < 100; i++)
	//	{
	//		if (_Flag == false)
	//		{
	//			_Flag = true;
	//			_pos.x = GetRand(SCREEN_SIZE_X - _size.x);
	//			_pos.y = GetRand(SCREEN_SIZE_Y - _size.y);
	//			_speed.x = GetRand(1) ? 1 : -1;
	//			_speed.y = GetRand(1) ? 1 : -1;
	//			switch (GetRand(3))
	//			{
	//			case 0:
	//				_pos.y = 0;
	//				break;
	//			case 1:
	//				_pos.y = SCREEN_SIZE_Y;
	//				break;
	//			case 2:
	//				_pos.x = 0;
	//				break;
	//			case 3:
	//				_pos.x = SCREEN_SIZE_X;
	//				break;
	//			default:
	//				break;
	//			}

	//			break;
	//		}
	//	}
	//}
	//for (int i = 0; i < 100; i++)
	//{
	//	if (_Flag == false)
	//	{
	//		continue;
	//	}
	//	if (_scale < 1)
	//	{
	//		_scale += 1 / 60.f;
	//		if (_scale > 1)
	//		{
	//			_scale = 1;
	//		}
	//		//continue;

	//	}
	//	_pos.x += _speed.x;
	//	_pos.y += _speed.y;
	//	if (_pos.x < 0)
	//	{
	//		_pos.x = 0;
	//		_speed.x = 1;
	//	}
	//	if (_pos.x > SCREEN_SIZE_X - _size.x)
	//	{
	//		_pos.x = SCREEN_SIZE_X - _size.y;
	//		_speed.x = -1;
	//	}
	//	if (_pos.y < 0)
	//	{
	//		_pos.y = 0;
	//		_speed.y = 1;
	//	}
	//	if (_pos.y > SCREEN_SIZE_Y - _size.x)
	//	{
	//		_pos.y = SCREEN_SIZE_Y - _size.y;
	//		_speed.y = -1;
	//	}
	//}

		//if (_moveFlag==false) {
		//	if (_pos.x + _size.x / 2 < _playerPos.x) {
		//		_pos.x += _speed;
		//	}
		//	else if (_pos.x + _size.x / 2 > _playerPos.x)
		//	{
		//		_pos.x -= _speed;
		//	}
		//	else if (_pos.x + _size.x / 2 == _playerPos.x)
		//	{
		//		_pos.x += 0;
		//	}

		//	if (_pos.y + _size.y / 2 < _playerPos.y) {
		//		_pos.y += _speed;
		//	}
		//	else if (_pos.y + _size.y / 2 > _playerPos.y)
		//	{
		//		_pos.y -= _speed;
		//	}
		//	else if (_pos.y + _size.y / 2 == _playerPos.y)
		//	{
		//		_pos.y += 0;
		//	}
		//	//PlaySoundMem(Enemysd, DX_PLAYTYPE_LOOP, false);
		//}
	
	Draw();

}

void Enemy::Draw(void)
{
		_moveFlag != false ? _animeCnt++ : _animeCnt = 0;
	DrawRotaGraphF(0, 0, 1, 0,
		ImageMng::GetInstance().SetID("image/enemy1.png", { _size.x,_size.y }, { 4,4 })[(_dir * 4) + (_animeCnt / 4 % 4)], true);


	
}


void Enemy::SetPos(Vector2& pos)
{
	_playerPos = pos;
}
