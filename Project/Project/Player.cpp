#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
Player::Player()
{
	Init();
}

Player::~Player()
{
	DeleteGraph(model);
}

void Player::Init(void)
{
	pos.x = SCREEN_SIZE_X / 2;
	pos.y = SCREEN_SIZE_Y / 2;
	dir = DIR_DOWN;
	speed = 4;
	movFlag = 0;
	 i = 0;
}

void Player::Update(void)
{
	{



			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				dir = DIR_RIGHT;
				movFlag = 1;

			}
			if (CheckHitKey(KEY_INPUT_LEFT))
			{
				dir = DIR_LEFT;
				movFlag = 1;

			}
			if (CheckHitKey(KEY_INPUT_UP))
			{
				dir = DIR_UP;
				movFlag = 1;

			}
			if (CheckHitKey(KEY_INPUT_DOWN))
			{
				dir = DIR_DOWN;
				movFlag = 1;
			}
		
		
		if (movFlag == 1)
		{
			i++;
			movepos = pos;

			switch (dir)
			{

			case DIR_UP:
				movepos.y -= speed;
				break;
			case DIR_RIGHT:
				movepos.x += speed;
				break;
			case DIR_DOWN:
				movepos.y += speed;
				break;
			case DIR_LEFT:
				movepos.x -= speed;
				break;
			}
			pos = movepos;
		}

	}
}

void Player::Draw(void)
{
	DrawRotaGraph(pos.x, pos.y, 1, 0, ImageMng::GetInstance().SetID("image/player2.png", { 32,32 }, { 4,4 })[dir*4+i / 6 % 4], true);
	
}

Vector2& Player::GetPos(void)
{
	return pos;
}


