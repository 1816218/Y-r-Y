#include <DxLib.h>
#include <algorithm>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng.h"
#include "../InputKey.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

//---------------------------------
//メイン処理
void SceneMng::Run(void)
{
	SysInit();

	//画像の読み込み
	lpImageMng.SetID("player", "image/player.png", { 32.0f, 32.0f }, { 4, 4 });
	lpImageMng.SetID("enemy" , "image/enemy1.png", { 32.0f, 32.0f }, { 4, 4 });

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		lpInputKey.Update();

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

bool SceneMng::SetScreen(int ghScreen)
{
	_ghBefor = GetDrawScreen();
	SetDrawScreen(ghScreen);
	return true;
}

bool SceneMng::RevScreen(void)
{
	SetDrawScreen(_ghBefor);
	return true;
}

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

	_drawList.clear();
}

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

bool SceneMng::DeleteDrawQue(void)
{
	_drawList.clear();
	return true;
}

SceneMng::SceneMng() : screenSize(800, 640)
{
}

SceneMng::~SceneMng()
{
}

//--------------------------------
//システム初期化処理
bool SceneMng::SysInit(void)
{
	ChangeWindowMode(true);				//true:window false:フルスクリーン
	SetWindowText("Coronet Pandemic");	//window名
	SetGraphMode(800, 640, 16);			//65536色モードにする

	//DXﾗｲﾌﾞﾗﾘ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	_activeScene = std::make_unique<TitleScene>();

	return true;
}

unique_Base SceneMng::SelectScene(void)
{
	switch (_sceneID)
	{
	case SCN_ID::TITLE:
		if (_activeScene == nullptr)
		{
			_activeScene.reset(new TitleScene());
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
