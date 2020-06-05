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

	//内容の更新
	unique_Base Update(unique_Base own) override;

	//シーンIDを取得
	SCN_ID GetSceneID(void) override;
private:
	//初期化処理
	bool Init(void);
	//描画処理
	void Draw(void);

	int _ghGameScreen;	//描画対処にしたｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙを保持

	Obj*				_player;	//プレイヤー
	std::vector<Obj*>	_objects;	//敵
};

