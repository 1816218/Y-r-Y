#include <DxLib.h>
#include "ClearScene.h"
#include "SceneMng.h"
#include "../ImageMng.h"
#include "../InputKey.h"

const int CANIME_FRAME_MAX = 1000;	//アニメーションフレームの最大数
const int CBLEND_MAX = 255;			//ブレンド最大値

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
	//削除
	lpImageMng.DeleteAllImageMap();
	lpSceneMng.DeleteAllDrawList();
	//音を止める
	StopMusic();
}
//-----メイン処理
void ClearScene::Update(void)
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
bool ClearScene::Init(void)
{
	//画像の読み込み
	lpImageMng.SetID("clear", "image/clear.png");
	lpImageMng.SetID("flame2", "image/flame2.png", Vector2F(640, 480), Vector2(2, 5));
	lpImageMng.SetID("press", "image/press_space.png");
	//描画する画面データの作成
	_ghClearScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	//音
	

	return true;
}
//-----描画
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
//-----シーンIDを取得
SCN_ID ClearScene::GetSceneID(void)
{
	return SCN_ID::CLEAR;
}
