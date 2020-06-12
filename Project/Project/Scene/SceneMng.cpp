#include <DxLib.h>
#include <algorithm>
#include "SceneMng.h"
#include "TitleScene.h"
#include"OverScene.h"
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
		DeleteAllDrawList();

		lpInputKey.Update();

		SelectScene();

		//���삳����V�[������
		if (_activeScene != nullptr)
		{
			_activeScene->Update();
		}

		Draw();
	}
}
//-----�`�揈��
void SceneMng::Draw(void)
{
	//�����ɕ��בւ���
	std::sort(_drawList.begin(), _drawList.end());

	//��ʂ�`�悷��
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
	//�`��Ώۂɂ������̨������ق�
	//���Ӗ��Ȓl�������珈�����Ȃ�
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que) == -1)
	{
		return false;
	}
	_drawList.push_back(std::make_pair(localZorder, que));
	return true;
}
//-----�`��Ώۂ����ׂč폜
bool SceneMng::DeleteAllDrawList(void)
{
	//�󂶂�Ȃ������炷�ׂĂ��폜
	if (!_drawList.empty())
	{
		_drawList.clear();
		return true;
	}
	return false;
}
//-----��ʃT�C�Y���擾
const Vector2F& SceneMng::GetScreenSize(void)
{
	return _screenSize;
}

void SceneMng::SetSceneID(const SCN_ID id)
{
	//���݂̃V�[���Ɠ����Ȃ珈�����Ȃ�
	if (_sceneID == id)
	{
		return;
	}
	_sceneID = id;
}

SceneMng::SceneMng()
	: _screenSize(800, 600), 
	_ghBefor(0), 
	_sceneID(SCN_ID::MAX),
	_activeScene(nullptr)
{
}

SceneMng::~SceneMng()
{
}

//-----�V�X�e������������
bool SceneMng::SysInit(void)
{
	DxLib::ChangeWindowMode(true);										//true:window false:�t���X�N���[��
	DxLib::SetWindowText("Coronet Pandemic");							//window��
	DxLib::SetGraphMode((int)_screenSize.x, (int)_screenSize.y, 32);	//�P�U�U�V���F���[�h�ɂ���

	//DXײ���؏���������
	if (DxLib::DxLib_Init())
	{
		return -1;//�ُ�I��
	}

	_sceneID = SCN_ID::TITLE;
	_activeScene = std::make_unique<TitleScene>(Vector2F(_screenSize.x / 4, _screenSize.y / 3), 0);

	return true;
}
//-----�V�[���؂�ւ�
void SceneMng::SelectScene(void)
{
	if (ResetActiveScene())
	{
		switch (_sceneID)
		{
		case SCN_ID::TITLE:
			_activeScene.reset(new TitleScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
			break;
		case SCN_ID::MAIN:
			_activeScene.reset(new GameScene());
			break;
		case SCN_ID::OVER:
			_activeScene.reset(new OverScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
			break;
		}
	}
}
//-----�V�[���̉��
bool SceneMng::ResetActiveScene(void)
{
	//���݂̃V�[����񂪍X�V����Ă�����
	//���\�[�X���������
	if (_activeScene->GetSceneID() != _sceneID)
	{
		_activeScene.reset();//���\�[�X�̉��
		return true;
	}
	return false;
}
