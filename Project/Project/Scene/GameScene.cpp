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
	_player->Draw();
}
