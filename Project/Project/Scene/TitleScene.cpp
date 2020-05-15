#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::UpDate(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}

SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
