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
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}
//-----メイン処理
void TitleScene::Update(void)
{
	//起動したらフェードインさせる
	if (_bright < 255)
	{
		_bright += 3;
		DxLib::SetDrawBright(_bright, _bright, _bright);
	}
	else//フェードインが終わったら
	{
		//SPACEキーが押されたらGameMainへ
		//シーンを切り替える
		if (lpInputKey.trgKey[KEY_SPACE])
		{
			lpSceneMng.SetSceneID(SCN_ID::MAIN);
		}
	}

	Draw();
}
//-----初期処理
bool TitleScene::Init(void)
{
	//画像の読み込み
	lpImageMng.SetID("title", "image/title.png");

	//描画する画面データの作成
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	return true;
}
//-----描画
void TitleScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghTitleScreen);
	ClearDrawScreen();
	DrawGraph(_pos.x, _pos.y, IMAGE_ID("title")[0], true);
	lpSceneMng.AddDrawQue(0, { _ghTitleScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----シーンIDを取得
SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
