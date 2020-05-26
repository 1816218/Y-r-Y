#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng.h"

TitleScene::TitleScene() : pos(200.0f, 200.0f), bright(0.0f)
{
	Init();
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	//�N��������t�F�[�h�C��������
	if (bright < 255)
	{
		bright += 3;
		SetDrawBright(bright, bright, bright);
	}

	Draw();

	return std::move(own);
}
//-----��������
bool TitleScene::Init(void)
{
	_sceneID = SCN_ID::TITLE;
	lpImageMng.SetID("title", "image/title.png");
	return true;
}
//-----�`��
void TitleScene::Draw(void)
{
	DrawGraph(pos.x, pos.y, IMAGE_ID("title")[0], true);
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
