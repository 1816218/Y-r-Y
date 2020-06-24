#pragma once
#include <memory>

//シーン情報
enum class SCN_ID
{
	TITLE,	//ゲームタイトル
	MAIN,	//ゲームメイン
	OVER,	//ゲームオーバー
	CLEAR,
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() : _sceneID(SCN_ID::MAX) {}
	virtual ~BaseScene() {}
	virtual void Update(void) = 0;
	virtual SCN_ID GetSceneID(void) = 0;
protected:
	SCN_ID _sceneID;	//シーンID
};