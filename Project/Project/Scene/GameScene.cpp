#include <DxLib.h>
#include "GameScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../Obj.h"
#include "../Player.h"
#include"../Item.h"
#include "../Enemy.h"
#include "../Map.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
	//íœ
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	StopMusic();
}
//-----ƒQ[ƒ€ƒƒCƒ“ˆ—
void GameScene::Update(void)
{
	for (auto obj : _objects)
	{
		obj->SetPos(_player->GetPos());
		obj->Update();
		//SetDrawBright(0, 0, 0);
		
	}
	
	_player->Update();
	_item->Update();
	Draw();
}
//-----ƒV[ƒ“î•ñ‚ðŽæ“¾
SCN_ID GameScene::GetSceneID(void)
{
	return SCN_ID::MAIN;
}
//-----‰Šú‰»ˆ—
bool GameScene::Init(void)
{
	//‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("enemy", "image/enemy1.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,7 });
	lpImageMng.SetID("light", "image/light.png");
	lpImageMng.SetID("Elixir", "image/Elixir.png");
	//•`‰æ‘ÎÛ‚É‚·‚é‰æ–Ê‚Ìì¬
	_ghGameScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	
	_player = new Player({ 800 / 2, 640 / 3 }, { 32, 32 });
	_objects.push_back(new Enemy({ 200, 200 }, { 32,32 }));
	_item=new Item({ 1200, 140 }, { 32, 32 });
	PlayMusic("Sound/main.mp3", DX_PLAYTYPE_LOOP);
	return true;
}
//-----•`‰æˆ—
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
	_item->Draw();
	lpSceneMng.AddDrawQue( 1, { _ghGameScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
