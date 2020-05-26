#pragma once
#include <memory>

//シーンのID
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
	BaseScene() {}
	virtual ~BaseScene() {}
	virtual unique_Base Update(unique_Base own) = 0;
	virtual SCN_ID GetSceneID(void) = 0;
	virtual void SetSceneID(SCN_ID sceneID) = 0;
protected:
	SCN_ID _sceneID;	//シーンID
};