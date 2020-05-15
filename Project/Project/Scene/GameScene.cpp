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
	//�Q�[�����C���̏���
	player->Update();

	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//�Q�[����������
	player = new Player();

	return true;
}

void GameScene::Draw(void)
{
	player->Draw();
}
