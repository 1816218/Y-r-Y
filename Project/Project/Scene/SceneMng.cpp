#include <DxLib.h>
#include "SceneMng.h"
#include "../ImageMng.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	SysInit();

	//int i = 0;

	//���C�����[�v
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
	ChangeWindowMode(true);				//true:window false:�t���X�N���[��
	SetWindowText("Coronet Pandemic");	//window��
	SetGraphMode(800, 640, 16);			//65536�F���[�h�ɂ���
	if (DxLib_Init() == -1)
	{
		return -1;	//DXײ���؏���������
	}
	SetDrawScreen(DX_SCREEN_BACK);
	
	return true;
}

