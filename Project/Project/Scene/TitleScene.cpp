#include <DxLib.h>
#include "TitleScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

const int ANIME_FRAME_MAX = 1000;	//アニメーションフレームの最大数
const int BLEND_MAX = 255;			//ブレンド最大値

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
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	//音を止める
	StopMusic();
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
	lpImageMng.SetID("flame", "image/flame.png", Vector2F(640, 480), Vector2(2, 5));
	lpImageMng.SetID("press", "image/press_space.png");
	//描画する画面データの作成
	_ghTitleScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	//音
	PlayMusic("Sound/title.mp3", DX_PLAYTYPE_LOOP);

	return true;
}
//-----描画
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
//-----シーンIDを取得
SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
