#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
Player::Player()
{
	//LoadDivGraph("ÉvÉåÉCÉÑÅ[.png", 12, 3, 4, 96 / 3, 128 / 4, Pmodel);
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
	{
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			pos.x += 5;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			pos.x -= 5;
		}
		if (CheckHitKey(KEY_INPUT_UP))
		{
			pos.y -= 5;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			pos.y += 5;
		}
	}

}

void Player::Draw()
{
}


