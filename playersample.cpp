#include "Player.h"

Player::Player()
{

	LoadDivGraph("プレイヤー.png",12,3,4,96/3,128/4,Pmodel);
}

Player::~Player()
{
	DeleteGraph(pmodel);
}

void Player::Init()
{
	pos.x = SCREEN_SIZE_X / 2;
	pos.y = SCREEN_SIZE_Y / 2;
	
}

void Player::Update()
{
if(CheckHitKey(KEY_INPUT_RIGHT))
{
pos.x+=5;
}
if(CheckHitKey(KEY_INPUT_LEFT))
{
pos.x-=5;
}
if(CheckHitKey(KEY_INPUT_UP))
{
pos.y-=5;
}
if(CheckHitKey(KEY_INPUT_DOWN))
{
pos.y+=5;
}
}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, pmodel[0],true);
}


