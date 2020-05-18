#include <DxLib.h>
#include "GameScene.h"
#include"../Player.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpDate(unique_Base own)
{
	//ゲームメインの処理
	_player->Update();

	_enemy->SetPos(_player->GetPos());

	_enemy->UpDate();

	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//ゲーム初期処理
	_player = new Player();
	_enemy = new Enemy();

	return true;
}

void GameScene::Draw(void)
{
	_player->Draw();
	_enemy->Draw();
}
