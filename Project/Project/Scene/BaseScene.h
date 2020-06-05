#pragma once
#include <memory>

//シーン情報
enum class SCN_ID
{
	TITLE,	//ゲームタイトル
	MAIN,	//ゲームメイン
	OVER,	//ゲームオーバー
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() : _sceneID(SCN_ID::MAX) {}
	virtual ~BaseScene() {}
	virtual unique_Base Update(unique_Base own) = 0;
	virtual SCN_ID GetSceneID(void) = 0;
protected:
	SCN_ID _sceneID;	//シーンID
};