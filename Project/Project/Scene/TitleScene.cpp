#include <DxLib.h>
#include "TitleScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

const int ANIME_FRAME_MAX = 1000;	//�A�j���[�V�����t���[���̍ő吔
const int BLEND_MAX = 255;			//�u�����h�ő�l

TitleScene::TitleScene() 
	: _bright(0), 
	_ghTitleScreen(0), 
	_animFrame(0),
	_alphaCount(BLEND_MAX)
{
	Init();
}

TitleScene::~TitleScene()
{
	//�폜
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	//�����~�߂�
	StopMusic();
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
	lpImageMng.SetID("flame", "image/flame.png", Vector2F(640, 480), Vector2(2, 5));
	lpImageMng.SetID("press", "image/press_space.png");
	//�`�悷���ʃf�[�^�̍쐬
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	//��
	PlayMusic("Sound/title.mp3", DX_PLAYTYPE_LOOP);

	return true;
}
//-----�`��
void TitleScene::Draw(void)
{
	int alpha = abs(_alphaCount - BLEND_MAX);

	lpSceneMng.SetScreen(_ghTitleScreen);
	ClearDrawScreen();
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2, 2.0, 0.0, IMAGE_ID("flame")[_animFrame / 5 % 10], true);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 3, 2.5, 0.0, IMAGE_ID("title")[0], true);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, alpha);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2 + 100, 1.0, 0.0, IMAGE_ID("press")[0], true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	lpSceneMng.AddDrawQue(0, { _ghTitleScreen, 0, 0 });
	lpSceneMng.RevScreen();
	
	_animFrame < ANIME_FRAME_MAX ? _animFrame++ : _animFrame = 0;
	_alphaCount < BLEND_MAX * 2 ? _alphaCount++ : _alphaCount = 0;
}
//-----�V�[��ID���擾
SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
