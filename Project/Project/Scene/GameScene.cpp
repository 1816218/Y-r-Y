#include <DxLib.h>
#include "GameScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../Obj.h"
#include "../Player.h"
#include "../Enemy.h"
#include "../Map.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	StopMusic();
}
//-----ゲームメイン処理
void GameScene::Update(void)
{
	for (auto obj : _objects)
	{
		obj->SetPos(_player->GetPos());
		obj->Update();
		
	}
	_player->Update();

	Draw();
}
//-----シーン情報を取得
SCN_ID GameScene::GetSceneID(void)
{
	return SCN_ID::MAIN;
}
//-----初期化処理
bool GameScene::Init(void)
{
	//画像の読み込み
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("enemy", "image/enemy1.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,7 });
	lpImageMng.SetID("light", "image/light.png");
	
	//描画対象にする画面の作成
	_ghGameScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	_player = new Player({ 800 / 2, 640 / 3 }, { 32, 32 });
	_objects.push_back(new Enemy({ 200, 200 }, { 32,32 }));
	PlayMusic("Sound/main.mp3", DX_PLAYTYPE_LOOP);
	return true;
}
//-----描画処理
void GameScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghGameScreen);
	ClearDrawScreen();
	lpMap.Draw();
	for (auto obj : _objects)
	{
		obj->Draw();
	}
	_player->Draw();
	lpSceneMng.AddDrawQue( 1, { _ghGameScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
