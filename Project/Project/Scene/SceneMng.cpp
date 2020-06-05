#include <DxLib.h>
#include <algorithm>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//-----���C������
void SceneMng::Run(void)
{
	SysInit();

	//���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		lpInputKey.Update();
		DeleteAllDrawList();
		//���삳����V�[������
		if (_activeScene != nullptr)
		{
			_sceneID = _activeScene->GetSceneID();
			_activeScene = _activeScene->Update(std::move(_activeScene));
		}
		_activeScene = SelectScene();

		Draw();
	}
}
//-----�`�揈��
void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	for (auto drawQue : _drawList)
	{
		DrawGraph(std::get<static_cast<int>(DRAW_QUE::X)>(drawQue.second),
			std::get<static_cast<int>(DRAW_QUE::Y)>(drawQue.second),
			std::get<static_cast<int>(DRAW_QUE::IMAGE)>(drawQue.second), true);
	}
	ScreenFlip();
}
//-----�`�悷���ʂ�ݒ肷��
bool SceneMng::SetScreen(int ghScreen)
{
	_ghBefor = GetDrawScreen();
	SetDrawScreen(ghScreen);
	return true;
}
//-----�\����������
bool SceneMng::RevScreen(void)
{
	SetDrawScreen(_ghBefor);
	return true;
}
//-----�`�悵����ʂ̒ǉ�
bool SceneMng::AddDrawQue(const int localZorder, DrawQueT que)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que) == -1)
	{
		return false;
	}
	_drawList.push_back(std::make_pair(localZorder, que));
	std::sort(_drawList.begin(), _drawList.end());
	return true;
}
//-----�`��Ώۂ����ׂď���
bool SceneMng::DeleteAllDrawList(void)
{
	if (!_drawList.empty())
	{
		_drawList.clear();
		return true;
	}
	return false;
}

const Vector2F& SceneMng::GetScreenSize(void)
{
	return _screenSize;
}

SceneMng::SceneMng() : _screenSize(800, 600), _ghBefor(0)
{
}

SceneMng::~SceneMng()
{
}

//-----�V�X�e������������
bool SceneMng::SysInit(void)
{
	ChangeWindowMode(true);				//true:window false:�t���X�N���[��
	SetWindowText("Coronet Pandemic");	//window��
	SetGraphMode((int)_screenSize.x, (int)_screenSize.y, 32);	//�P�U�U�V���F���[�h�ɂ���

	//DXײ���؏���������
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	_sceneID = SCN_ID::TITLE;
	_activeScene = nullptr;

	return true;
}
//-----�V�[���؂�ւ�
unique_Base SceneMng::SelectScene(void)
{
	switch (_sceneID)
	{
	case SCN_ID::TITLE:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new TitleScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
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
