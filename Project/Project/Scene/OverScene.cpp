#include <DxLib.h>
#include "OverScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"
const int OANIME_FRAME_MAX = 1000;	//アニメーションフレームの最大数
const int OBLEND_MAX = 255;			//ブレンド最大値
OverScene::OverScene(): _bright(0),
_ghOverScreen(0),
_OanimFrame(0),
_OalphaCount(OBLEND_MAX)
{
	Init();
}

OverScene::~OverScene()
{
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	StopMusic();
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
		if (lpInputKey.trgKey[_1P_START])
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
	lpImageMng.SetID("flame3", "image/flame3.png", Vector2F(640, 480), Vector2(2, 5));
	lpImageMng.SetID("press", "image/press_space.png");

	//描画する画面データの作成
	_ghOverScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	//音
	PlayMusic("Sound/over.mp3", DX_PLAYTYPE_BACK);
	return true;
}
//-----描画
void OverScene::Draw(void)
{
	int alpha = abs(_OalphaCount - OBLEND_MAX);
	lpSceneMng.SetScreen(_ghOverScreen);
	ClearDrawScreen();
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2, 1.3, 0.0, IMAGE_ID("flame3")[_OanimFrame / 5 % 10], true);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2, 1.0, 0.0, IMAGE_ID("over")[0], true);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, alpha);
	DrawRotaGraph(lpSceneMng.GetScreenSize().x / 2, lpSceneMng.GetScreenSize().y / 2 + 100, 0.5, 0.0, IMAGE_ID("press")[0], true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	

	
	lpSceneMng.AddDrawQue(0, { _ghOverScreen, 0, 0 });
	lpSceneMng.RevScreen();
	_OanimFrame < OANIME_FRAME_MAX ? _OanimFrame++ : _OanimFrame = 0;
	_OalphaCount < OBLEND_MAX * 2 ? _OalphaCount++ : _OalphaCount = 0;
}
//-----シーンIDを取得
SCN_ID OverScene::GetSceneID(void)
{
	return SCN_ID::OVER;
}
