#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng.h"

TitleScene::TitleScene() : pos(200.0f, 200.0f), bright(0.0f)
{
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	//SPACEキーが押されたらゲームシーンに切り替える
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>();
	}

	//起動したらフェードインさせる
	if (bright < 255)
	{
		bright += 3;
		SetDrawBright(bright, bright, bright);
	}

	Draw();

	return std::move(own);
}
//-----シーンIDを取得
SCN_ID TitleScene::GetSceneID(void)
{
	return SCN_ID::TITLE;
}
//-----初期処理
bool TitleScene::Init(void)
{
	return false;
}
//-----描画
void TitleScene::Draw(void)
{
	DrawGraph(pos.x, pos.y, IMAGE_ID.SetID("image/title.png"), true);
}
