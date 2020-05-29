#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "SceneMng.h"
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
	//起動したらフェードインさせる
	if (bright < 255)
	{
		bright += 3;
		SetDrawBright(bright, bright, bright);
	}

	Draw();

	return std::move(own);
}
//-----初期処理
bool TitleScene::Init(void)
{
	_sceneID = SCN_ID::TITLE;
	lpImageMng.SetID("title", "image/title.png");
	_ghTitleScreen = MakeScreen(lpSceneMng.screenSize.x, lpSceneMng.screenSize.y, true);
	return true;
}
//-----描画
void TitleScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghTitleScreen);
	ClsDrawScreen();

	DrawGraph(pos.x, pos.y, IMAGE_ID("title")[0], true);

	lpSceneMng.AddDrawQue(0, { _ghTitleScreen, 0, 0 });
	lpSceneMng.RevScreen();

}
//-----シーンIDを取得
SCN_ID TitleScene::GetSceneID(void)
{
	return _sceneID;
}
//-----シーンIDの設定
void TitleScene::SetSceneID(SCN_ID sceneID)
{
	_sceneID = sceneID;
}
