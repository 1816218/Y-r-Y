#include <DxLib.h>
#include "ClearScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

const int CANIME_FRAME_MAX = 1000;	//�A�j���[�V�����t���[���̍ő吔
const int CBLEND_MAX = 255;			//�u�����h�ő�l

ClearScene::ClearScene() 
	: _bright(0), 
	_ghClearScreen(0), 
	_CanimFrame(0),
	_CalphaCount(CBLEND_MAX)
{
	Init();
}

ClearScene::~ClearScene()
{
	//�폜
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	//�����~�߂�
	StopMusic();
}
//-----���C������
void ClearScene::Update(void)
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
bool ClearScene::Init(void)
{
	//�摜�̓ǂݍ���
	lpImageMng.SetID("clear", "image/clear.png");
	lpImageMng.SetID("flame2", "image/flame2.png", Vector2F(640, 480), Vector2(2, 5));
	lpImageMng.SetID("press", "image/press_space.png");
	//�`�悷���ʃf�[�^�̍쐬
	_ghClearScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	//��
	

	return true;
}
//-----�`��
void ClearScene::Draw(void)
{
	int alpha = abs(_CalphaCount - CBLEND_MAX);

	lpSceneMng.SetScreen(_ghClearScreen);
	ClearDrawScreen();
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2, 1.3, 0.0, IMAGE_ID("flame2")[_CanimFrame / 5 % 10], true);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 3, 1.0, 0.0, IMAGE_ID("clear")[0], true);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, alpha);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2 + 100, 0.5, 0.0, IMAGE_ID("press")[0], true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	lpSceneMng.AddDrawQue(0, { _ghClearScreen, 0, 0 });
	lpSceneMng.RevScreen();
	
	_CanimFrame < CANIME_FRAME_MAX ? _CanimFrame++ : _CanimFrame = 0;
	_CalphaCount < CBLEND_MAX * 2 ? _CalphaCount++ : _CalphaCount = 0;
}
//-----�V�[��ID���擾
SCN_ID ClearScene::GetSceneID(void)
{
	return SCN_ID::CLEAR;
}
