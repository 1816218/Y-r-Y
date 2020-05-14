#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
Player::Player()
{
}

Player::~Player()
{
	DeleteGraph(model);
}

void Player::Init()
{
	pos.x = SCREEN_SIZE_X / 2;
	pos.y = SCREEN_SIZE_Y / 2;
	
}

void Player::Update()
{

}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, IMAGE_ID.SetID("image/player.png"),true);
}


