#include <DxLib.h>
#include "GameScene.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
	DeleteGraph(gHandle);
}

unique_Base GameScene::UpDate(unique_Base own)
{
	//�Q�[�����C���̏���
	Draw();

	return std::move(own);
}

bool GameScene::Init(void)
{
	//�Q�[����������
	gHandle = LoadGraph("image/player.png");

	return true;
}

void GameScene::Draw(void)
{
	DrawGraph(400, 320, gHandle, true);
}
