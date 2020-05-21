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
	_pos.x = GetRand(SCREEN_SIZE_X - _size.x);
	_pos.y=	GetRand(SCREEN_SIZE_Y-_size.y) ;
	_speed = 0.0f;
	_Flag = false;
	_size = { 32,32 };
	_moveFlag = false;
	_animeCnt = 0;
	_dir = EDIR_DOWN;
	return false;
}

void Enemy::Update(void)
{

	// GetRand(_pos.x);
		if (_moveFlag==false) {
			if (_pos.x + _size.x / 2 < _playerPos.x) {
				_pos.x += _speed;
			}
			else if (_pos.x + _size.x / 2 > _playerPos.x)
			{
				_pos.x -= _speed;
			}
			else if (_pos.x + _size.x / 2 == _playerPos.x)
			{
				_pos.x += 0;
			}

			if (_pos.y + _size.y / 2 < _playerPos.y) {
				_pos.y += _speed;
			}
			else if (_pos.y + _size.y / 2 > _playerPos.y)
			{
				_pos.y -= _speed;
			}
			else if (_pos.y + _size.y / 2 == _playerPos.y)
			{
				_pos.y += 0;
			}
			//PlaySoundMem(Enemysd, DX_PLAYTYPE_LOOP, false);
		}
	
	Draw();

}

void Enemy::Draw(void)
{
	_moveFlag != false ? _animeCnt++ : _animeCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, 1, 0,
		ImageMng::GetInstance().SetID("image/enemy1.png", { _size.x,_size.y }, { 4,4 })[(_dir * 4) + (_animeCnt / 4 % 4)], true);
}

void Enemy::SetPos(Vector2& pos)
{
	_playerPos = pos;
}
