#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//---------------------------------
//���C������
void SceneMng::Run(void)
{
	SysInit();

	//�摜�̓ǂݍ���
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4,4 });
	lpImageMng.SetID("enemy", "image/enemy1.png", {32.0f, 32.0f}, {4,4});

	//���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();

		lpInputKey.Update();

		//���삳����V�[������
		if (_activeScene != nullptr)
		{
			_sceneID = _activeScene->GetSceneID();
			_activeScene = _activeScene->Update(std::move(_activeScene));
		}
		_activeScene = SelectScene();

		ScreenFlip();
	}
}

unique_Base SceneMng::SelectScene(void)
{
	switch (_sceneID)
	{
	case SCN_ID::TITLE:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new TitleScene());
		}

		if (CheckHitKey(KEY_INPUT_A))
		{
			_sceneID = SCN_ID::MAIN;
			_activeScene.reset();
		}

		break;
	case SCN_ID::MAIN:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new GameScene());
		}
		break;
	case SCN_ID::OVER:
		break;
	default:
		_sceneID = SCN_ID::TITLE;
		break;
	}
	return std::move(_activeScene);
}

SceneMng::SceneMng()
{
}

SceneMng::~SceneMng()
{
}
//--------------------------------
//�V�X�e������������
bool SceneMng::SysInit(void)
{
	ChangeWindowMode(true);				//true:window false:�t���X�N���[��
	SetWindowText("Coronet Pandemic");	//window��
	SetGraphMode(800, 640, 16);			//65536�F���[�h�ɂ���

	//DXײ���؏���������
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);		//�ޯ��ޯ̧�ɕ`��
	
	_activeScene = std::make_unique<TitleScene>();

	return true;
}

