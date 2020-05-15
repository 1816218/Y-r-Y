#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Player.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();


	unique_Base UpDate(unique_Base own) override;

	//ƒV[ƒ“ID‚ğæ“¾
	SCN_ID GetSceneID(void) override { return SCN_ID::GAME; }

private:
	bool Init(void);
	void Draw(void);

	Player* player;
};

