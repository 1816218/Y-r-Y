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
	//起動したらフェードインさせる
	if (_bright < 255)
	{
		_bright += 3;
		DxLib::SetDrawBright(_bright, _bright, _bright);
	}

	Draw();

	return std::move(own);
}
//-----初期処理
bool TitleScene::Init(void)
{
	//画像の読み込み
	lpImageMng.SetID("title", "image/title.png");

	//描画する画面データの作成
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	_sceneID = SCN_ID::TITLE;

	return true;
}
//-----描画
void TitleScene::Draw(void)
{
	//描画する画面を設定
	lpSceneMng.SetScreen(_ghTitleScreen);
	ClsDrawScreen();

	DrawGraph(_pos.x, _pos.y, IMAGE_ID("title")[0], true);

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
