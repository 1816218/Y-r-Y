#include <DxLib.h>
#include "OverScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

OverScene::OverScene(const Vector2F& pos, const int bright)
{
	_pos	= pos;
	_bright = bright;
	Init();
}

OverScene::~OverScene()
{
	//�폜
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}
//-----���C������
void OverScene::Update(void)
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
			lpSceneMng.SetSceneID(SCN_ID::TITLE);
		}
	}

	Draw();
}
//-----��������
bool OverScene::Init(void)
{
	//�摜�̓ǂݍ���
	lpImageMng.SetID("over", "image/over.png");
	

	//�`�悷���ʃf�[�^�̍쐬
	_ghOverScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	return true;
}
//-----�`��
void OverScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghOverScreen);
	ClearDrawScreen();
	DrawGraph(_pos.x, _pos.y, IMAGE_ID("over")[0], true);
	lpSceneMng.AddDrawQue(0, { _ghOverScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----�V�[��ID���擾
SCN_ID OverScene::GetSceneID(void)
{
	return SCN_ID::OVER;
}
