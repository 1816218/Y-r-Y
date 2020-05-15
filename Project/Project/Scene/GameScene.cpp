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
	//ゲームメインの処理
	player->Update();

	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//ゲーム初期処理
	player = new Player();

	return true;
}

void GameScene::Draw(void)
{
	player->Draw();
}
