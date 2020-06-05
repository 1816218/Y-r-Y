#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"

TitleScene::TitleScene(const Vector2F& pos, const int bright) : _pos(pos), _bright(bright)
{
	Init();
}

TitleScene::~TitleScene()
{
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}

unique_Base TitleScene::Update(unique_Base own)
{
	//�N��������t�F�[�h�C��������
	if (_bright < 255)
	{
		_bright += 3;
		DxLib::SetDrawBright(_bright, _bright, _bright);
	}

	Draw();

	return std::move(own);
}
//-----��������
bool TitleScene::Init(void)
{
	//�摜�̓ǂݍ���
	lpImageMng.SetID("title", "image/title.png");

	//�`�悷���ʃf�[�^�̍쐬
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	_sceneID = SCN_ID::TITLE;

	return true;
}
//-----�`��
void TitleScene::Draw(void)
{
	//�`�悷���ʂ�ݒ�
	lpSceneMng.SetScreen(_ghTitleScreen);
	ClsDrawScreen();

	DrawGraph(_pos.x, _pos.y, IMAGE_ID("title")[0], true);

	lpSceneMng.AddDrawQue(0, { _ghTitleScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----�V�[��ID���擾
SCN_ID TitleScene::GetSceneID(void)
{
	return _sceneID;
}
//-----�V�[��ID�̐ݒ�
void TitleScene::SetSceneID(SCN_ID sceneID)
{
	_sceneID = sceneID;
}
