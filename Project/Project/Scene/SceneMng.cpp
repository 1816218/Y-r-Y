#include <DxLib.h>
#include <algorithm>
#include "SceneMng.h"
#include "TitleScene.h"
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
		lpInputKey.Update();
		DeleteAllDrawList();
		//動作させるシーン処理
		if (_activeScene != nullptr)
		{
			_sceneID = _activeScene->GetSceneID();
			_activeScene = _activeScene->Update(std::move(_activeScene));
		}
		_activeScene = SelectScene();

		Draw();
	}
}
//-----描画処理
void SceneMng::Draw(void)
{
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
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que) == -1)
	{
		return false;
	}
	_drawList.push_back(std::make_pair(localZorder, que));
	std::sort(_drawList.begin(), _drawList.end());
	return true;
}
//-----描画対象をすべて消去
bool SceneMng::DeleteAllDrawList(void)
{
	if (!_drawList.empty())
	{
		_drawList.clear();
		return true;
	}
	return false;
}

const Vector2F& SceneMng::GetScreenSize(void)
{
	return _screenSize;
}

SceneMng::SceneMng() : _screenSize(800, 600), _ghBefor(0)
{
}

SceneMng::~SceneMng()
{
}

//-----システム初期化処理
bool SceneMng::SysInit(void)
{
	ChangeWindowMode(true);				//true:window false:フルスクリーン
	SetWindowText("Coronet Pandemic");	//window名
	SetGraphMode((int)_screenSize.x, (int)_screenSize.y, 32);	//１６６７万色モードにする

	//DXﾗｲﾌﾞﾗﾘ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	_sceneID = SCN_ID::TITLE;
	_activeScene = nullptr;

	return true;
}
//-----シーン切り替え
unique_Base SceneMng::SelectScene(void)
{
	switch (_sceneID)
	{
	case SCN_ID::TITLE:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new TitleScene({ _screenSize.x / 4, _screenSize.y / 3 }, 0));
		}

		if (CheckHitKey(KEY_INPUT_A))
		{
			_sceneID = SCN_ID::MAIN;
			_activeScene.reset();
		}

		break;
	case SCN_ID::MAIN:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new GameScene());
		}
		break;
	case SCN_ID::OVER:
		break;
	default:
		_sceneID = SCN_ID::TITLE;
		break;
	}
	return std::move(_activeScene);
}
