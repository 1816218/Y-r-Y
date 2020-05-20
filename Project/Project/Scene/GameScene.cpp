#include <DxLib.h>
#include "GameScene.h"
#include "../Player.h"
#include"../Enemy.h"
#include "../ImageMng.h"
#include "../Map.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	//ゲームメインの処理
	_player->Update();
	_enemy->Update();
	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//ゲーム初期処理
	_player = new Player();
	_enemy->Init();
	return true;
}

void GameScene::Draw(void)
{
	DrawGraph(0, 0, IMAGE_ID.SetID("image/map.png"), true);
	_player->Draw();
	_enemy->Draw();
	lpMap.Init();
}
