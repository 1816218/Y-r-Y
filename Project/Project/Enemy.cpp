#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"

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

	return false;
}

void Enemy::Update(void)
{
}

void Enemy::Draw(void)
{
}

void Enemy::SetPos(Vector2& pos)
{
	_playerPos = pos;
}
