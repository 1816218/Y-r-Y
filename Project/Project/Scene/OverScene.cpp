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
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
}
//-----メイン処理
void OverScene::Update(void)
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
			lpSceneMng.SetSceneID(SCN_ID::TITLE);
		}
	}

	Draw();
}
//-----初期処理
bool OverScene::Init(void)
{
	//画像の読み込み
	lpImageMng.SetID("over", "image/over.png");
	

	//描画する画面データの作成
	_ghOverScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);

	return true;
}
//-----描画
void OverScene::Draw(void)
{
	lpSceneMng.SetScreen(_ghOverScreen);
	ClearDrawScreen();
	DrawGraph(_pos.x, _pos.y, IMAGE_ID("over")[0], true);
	lpSceneMng.AddDrawQue(0, { _ghOverScreen, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----シーンIDを取得
SCN_ID OverScene::GetSceneID(void)
{
	return SCN_ID::OVER;
}
