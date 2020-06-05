#include <DxLib.h>
#include "GameScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../Player.h"
#include "../Enemy.h"
#include "../Map.h"

GameScene::GameScene(): _gameScreenSize(800, 640)
{
	Init();
}

GameScene::~GameScene()
{
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
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

	_ghGameScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	//画像の読み込み
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("enemy", "image/enemy1.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,4 });

	return true;
}

void GameScene::Draw(void)
{
	lpMap.Draw();

	lpSceneMng.SetScreen(_ghGameScreen);
	SetDrawBright(255, 255, 255);
	ClsDrawScreen();

	for (auto obj : _objects)
	{
		obj->Draw();
	}
	_player->Draw();

	lpSceneMng.AddDrawQue( 1, { _ghGameScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
