#pragma once
#include "BaseScene.h"


class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();


	unique_Base UpDate(unique_Base own) override;

	//シーンIDを取得
	SCN_ID GetSceneID(void) override { return SCN_ID::GAME; }

private:
	bool Init(void);
	void Draw(void);

	int gHandle;
};

