#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"
#include "Scene/TitleScene.h"

Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
}

bool Enemy::Init(void)
{
	_pos = { 0.0f, 0.0f };
	_speed = 0.0f;
	_Flag = false;
	_size = { 32,32 };
	_moveFlag = false;
	_animeCnt = 0;
	return false;
}

void Enemy::Update(Vector2& pos)
{
	if (_Flag) {
		if (_pos.x + _size.x / 2 < pos.x) {
			_pos.x += _speed;
		}
		else if (_pos.x + _size.x / 2 > pos.x)
		{
			_pos.x -= _speed;
		}
		else if (_pos.x + _size.x / 2 == pos.x)
		{
			_pos.x += 0;
		}

		if (_pos.y + _size.y / 2 < pos.y) {
			_pos.y += _speed;
		}
		else if (_pos.y + _size.y / 2 > pos.y)
		{
			_pos.y -= _speed;
		}
		else if (_pos.y + _size.y / 2 == pos.y)
		{
			_pos.y += 0;
		}
		//PlaySoundMem(Enemysd, DX_PLAYTYPE_LOOP, false);
	}



}

void Enemy::Draw(void)
{
	_moveFlag != false ? _animeCnt++ : _animeCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, 1, 0,
		ImageMng::GetInstance().SetID("image/player2.png", { _size.x,_size.y }, { 4,4 })[(_dir * 4) + (_animeCnt / 4 % 4)], true);

}

void Enemy::SetPos(Vector2& pos)
{
	_playerPos = pos;
}
