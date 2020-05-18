#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//-----メイン処理
void SceneMng::Run(void)
{
	SysInit();

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();

		lpInputKey.Update();

		//動作させるシーン処理
		_activeScene = _activeScene->Update(std::move(_activeScene));

		ScreenFlip();
	}
}

SceneMng::SceneMng()
{
}

SceneMng::~SceneMng()
{
}

bool SceneMng::SysInit(void)
{
	ChangeWindowMode(true);				//true:window false:フルスクリーン
	SetWindowText("Coronet Pandemic");	//window名
	SetGraphMode(800, 640, 16);			//65536色モードにする
	if (DxLib_Init() == -1)
	{
		return -1;	//DXﾗｲﾌﾞﾗﾘ初期化処理
	}
	SetDrawScreen(DX_SCREEN_BACK);
	
	_activeScene = std::make_unique<GameScene>();

	return true;
}

