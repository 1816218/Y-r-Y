#include <DxLib.h>
#include "SceneMng.h"
#include "../ImageMng.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	SysInit();

	//int i = 0;

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();

		//DrawRotaGraph(100, 100, 1, 0, ImageMng::GetInstance().SetID("image/player.png", { 32,32 }, { 3,4 })[i/10%12], true);

		ScreenFlip();
		//i++;
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
	
	return true;
}

