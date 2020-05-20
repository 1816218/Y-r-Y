#include <DxLib.h>
#include "GameScene.h"
#include "../Player.h"
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
	//�Q�[�����C���̏���
	_player->Update();

	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//�Q�[����������
	_player = new Player();
	return true;
}

void GameScene::Draw(void)
{
	lpMap.Draw();
	_player->Draw();
}
