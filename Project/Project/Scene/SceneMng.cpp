#include <DxLib.h>
#include <algorithm>
#include "SceneMng.h"
#include "TitleScene.h"
#include"OverScene.h"
#include "GameScene.h"
#include "../ImageMng.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//-----メイン処理
void SceneMng::Run(void)
{
	SysInit();

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		DeleteAllDrawList();

		lpInputKey.Update();

		SelectScene();

		//動作させるシーン処理
		if (_activeScene != nullptr)
		{
			_activeScene->Update();
		}

		Draw();
	}
}
//-----描画処理
void SceneMng::Draw(void)
{
	//昇順に並べ替える
	std::sort(_drawList.begin(), _drawList.end());

	//画面を描画する
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	for (auto drawQue : _drawList)
	{
		DrawGraph(std::get<static_cast<int>(DRAW_QUE::X)>(drawQue.second),
			std::get<static_cast<int>(DRAW_QUE::Y)>(drawQue.second),
			std::get<static_cast<int>(DRAW_QUE::IMAGE)>(drawQue.second), true);
	}
	ScreenFlip();
}
//-----描画する画面を設定する
bool SceneMng::SetScreen(int ghScreen)
{
	_ghBefor = GetDrawScreen();
	SetDrawScreen(ghScreen);
	return true;
}
//-----表示させる画面
bool SceneMng::RevScreen(void)
{
	SetDrawScreen(_ghBefor);
	return true;
}
//-----描画した画面の追加
bool SceneMng::AddDrawQue(const int localZorder, DrawQueT que)
{
	//描画対象にしたｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙが
	//無意味な値だったら処理しない
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que) == -1)
	{
		return false;
	}
	_drawList.push_back(std::make_pair(localZorder, que));
	return true;
}
//-----描画対象をすべて削除
bool SceneMng::DeleteAllDrawList(void)
{
	//空じゃなかったらすべてを削除
	if (!_drawList.empty())
	{
		_drawList.clear();
		return true;
	}
	return false;
}
//-----画面サイズを取得
const Vector2F& SceneMng::GetScreenSize(void)
{
	return _screenSize;
}

void SceneMng::SetSceneID(const SCN_ID id)
{
	//現在のシーンと同じなら処理しない
	if (_sceneID == id)
	{
		return;
	}
	_sceneID = id;
}

SceneMng::SceneMng()
	: _screenSize(800, 600), 
	_ghBefor(0), 
	_sceneID(SCN_ID::MAX),
	_activeScene(nullptr)
{
}

SceneMng::~SceneMng()
{
}

//-----システム初期化処理
bool SceneMng::SysInit(void)
{
	DxLib::ChangeWindowMode(true);										//true:window false:フルスクリーン
	DxLib::SetWindowText("Coronet Pandemic");							//window名
	DxLib::SetGraphMode((int)_screenSize.x, (int)_screenSize.y, 32);	//１６６７万色モードにする

	//DXﾗｲﾌﾞﾗﾘ初期化処理
	if (DxLib::DxLib_Init())
	{
		return -1;//異常終了
	}

	_sceneID = SCN_ID::TITLE;
	_activeScene = std::make_unique<TitleScene>(Vector2F(_screenSize.x / 4, _screenSize.y / 3), 0);

	return true;
}
//-----シーン切り替え
void SceneMng::SelectScene(void)
{
	if (ResetActiveScene())
	{
		switch (_sceneID)
		{
		case SCN_ID::TITLE:
			_activeScene.reset(new TitleScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
			break;
		case SCN_ID::MAIN:
			_activeScene.reset(new GameScene());
			break;
		case SCN_ID::OVER:
			_activeScene.reset(new OverScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
			break;
		}
	}
}
//-----シーンの解放
bool SceneMng::ResetActiveScene(void)
{
	//現在のシーン情報が更新されていたら
	//リソースを解放する
	if (_activeScene->GetSceneID() != _sceneID)
	{
		_activeScene.reset();//リソースの解放
		return true;
	}
	return false;
}
