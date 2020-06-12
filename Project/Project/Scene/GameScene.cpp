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
	//�폜
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}
//-----�Q�[�����C������
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
//-----�V�[�������擾
SCN_ID GameScene::GetSceneID(void)
{
	return SCN_ID::MAIN;
}
//-----����������
bool GameScene::Init(void)
{
	//�摜�̓ǂݍ���
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("enemy", "image/enemy1.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,7 });
	StopMusic();
	//�`��Ώۂɂ����ʂ̍쐬
	_ghGameScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	_player = new Player({ 800 / 2, 640 / 3 }, { 32, 32 });
	_objects.push_back(new Enemy({ 100, 100 }, { 32,32 }));

	return true;
}
//-----�`�揈��
void GameScene::Draw(void)
{
	lpMap.Draw();

	lpSceneMng.SetScreen(_ghGameScreen);
	ClearDrawScreen();
	for (auto obj : _objects)
	{
		obj->Draw();
	}
	_player->Draw();
	lpSceneMng.AddDrawQue( 1, { _ghGameScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
