#include <DxLib.h>
#include "SceneMng.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	SysInit();

	SetDrawScreen(DX_SCREEN_BACK);
	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();
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
	ChangeWindowMode(TRUE);				//true:window false:フルスクリーン
	SetWindowText("Coronet Pandemic");	//window名
	SetGraphMode(800, 640, 16);			//65536色モードにする
	if (DxLib_Init() == -1) return false;	//DXﾗｲﾌﾞﾗﾘ初期化処理

	return true;
}

