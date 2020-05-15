#include <DxLib.h>
#include "GameScene.h"
#include"../Player.h"

GameScene::GameScene()
{
	Init();

	player->Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpDate(unique_Base own)
{
	//ƒQ[ƒ€ƒƒCƒ“‚Ìˆ—
	player->Update();

	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//ƒQ[ƒ€‰Šúˆ—
	player = new Player();

	return true;
}

void GameScene::Draw(void)
{
	player->Draw();
}
