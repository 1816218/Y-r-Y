#include <DxLib.h>
#include "GameScene.h"
#include "../Player.h"
#include"../Enemy.h"
#include "../ImageMng.h"
#include "../Map.h"

GameScene::GameScene(): _gameScreenSize(800, 640)
{
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	//ゲームメインの処理
	for (auto obj : _objects)
	{
		obj->SetPos(_player->GetPos());
		obj->Update();
	}

	_player->Update();

	Draw();

	return std::move(own);
}
//-----シーンIDを取得
SCN_ID GameScene::GetSceneID(void)
{
	return _sceneID;
}
//-----シーンIDの設定
void GameScene::SetSceneID(SCN_ID sceneID)
{
	_sceneID = sceneID;
}

bool GameScene::Init(void)
{
	//ゲーム初期処理
	_player = new Player({ 800/2, 640/3 }, { 32, 32 });
	_objects.push_back(new Enemy({ 100, 100 }, { 32,32 }));

	_sceneID = SCN_ID::MAIN;

	return true;
}

void GameScene::Draw(void)
{
	lpMap.Draw();
	for (auto obj : _objects)
	{
		obj->Draw();
	}
	_player->Draw();
}
