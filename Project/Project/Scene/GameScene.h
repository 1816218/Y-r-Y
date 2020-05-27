#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();


	unique_Base Update(unique_Base own) override;

	//シーンIDを取得
	SCN_ID GetSceneID(void) override;
	void SetSceneID(SCN_ID sceneID) override;
private:
	bool Init(void);
	void Draw(void);

	Vector2F _gameScreenSize;	//スクリーンサイズ

	std::vector<Obj*> _objects;
	Obj* _player;
};

