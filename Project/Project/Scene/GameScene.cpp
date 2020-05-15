#include <DxLib.h>
#include "GameScene.h"
#include"../Player.h"
Player player;

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
	DeleteGraph(gHandle);
}

unique_Base GameScene::UpDate(unique_Base own)
{
	//ƒQ[ƒ€ƒƒCƒ“‚Ìˆ—
	Draw();
	player.Update();
	return std::move(own);
}

bool GameScene::Init(void)
{
	//ƒQ[ƒ€‰Šúˆ—
	//gHandle = LoadGraph("image/player.png");
	player.Init();
	return true;
}

void GameScene::Draw(void)
{
	//DrawGraph(400, 320, gHandle, true);
	player.Draw();
}
