#include<DxLib.h>
#include "Enemy.h"
#include"ImageMng.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	pos.x = SCREEN_SIZE_X / 3;
	pos.y = SCREEN_SIZE_Y / 3;

	i = 0;

}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	DrawRotaGraph(pos.x, pos.y, 1, 0, ImageMng::GetInstance().SetID("image/.png", { 32,32 }, { 4,4 })[dir * 4 + i / 6 % 4], true);

}
