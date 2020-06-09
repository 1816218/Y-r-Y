#include <DxLib.h>
#include "TitleScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

TitleScene::TitleScene(const Vector2F& pos, const int bright)
{
	_pos	= pos;
	_bright = bright;
	Init();
}

TitleScene::~TitleScene()
{
	//�폜
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}
//-----���C������
void TitleScene::Update(void)
{
	//�N��������t�F�[�h�C��������
	if (_bright < 255)
	{
		_bright += 3;
		DxLib::SetDrawBright(_bright, _bright, _bright);
	}
	else//�t�F�[�h�C�����I�������
	{
		//SPACE�L�[�������ꂽ��GameMain��
		//�V�[����؂�ւ���
		if (lpInputKey.trgKey[KEY_SPACE])
		{
			lpSceneMng.SetSceneID(SCN_ID::MAIN);
		}
	}

	Draw();
}
//-----��������
bool TitleScene::Init(void)
{
	//�摜�̓ǂݍ���
	lpImageMng.SetID("title", "image/title.png");

	//�`�悷���ʃf�[�^�̍쐬
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	return true;
}
//-----�`��
void TitleScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghTitleScreen);
	ClearDrawScreen();
	DrawGraph(_pos.x, _pos.y, IMAGE_ID("title")[0], true);
	lpSceneMng.AddDrawQue(0, { _ghTitleScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----�V�[��ID���擾
SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
