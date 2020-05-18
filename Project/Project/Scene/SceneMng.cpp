#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//-----���C������
void SceneMng::Run(void)
{
	SysInit();

	//���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();

		lpInputKey.Update();

		//���삳����V�[������
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
	ChangeWindowMode(true);				//true:window false:�t���X�N���[��
	SetWindowText("Coronet Pandemic");	//window��
	SetGraphMode(800, 640, 16);			//65536�F���[�h�ɂ���
	if (DxLib_Init() == -1)
	{
		return -1;	//DXײ���؏���������
	}
	SetDrawScreen(DX_SCREEN_BACK);
	
	_activeScene = std::make_unique<GameScene>();

	return true;
}

