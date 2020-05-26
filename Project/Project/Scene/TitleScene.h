#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	unique_Base Update(unique_Base own) override;

	SCN_ID GetSceneID(void) override;
	void SetSceneID(SCN_ID sceneID) override;
private:
	bool Init(void);
	void Draw(void);

	Vector2F pos;	//タイトルロゴの座標
	float bright;	//明るさ
};

