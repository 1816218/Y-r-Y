#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene() {}
	TitleScene(const Vector2F& pos, const int bright);
	~TitleScene();

	unique_Base Update(unique_Base own) override;

	SCN_ID GetSceneID(void) override;
	void SetSceneID(SCN_ID sceneID) override;
private:
	bool Init(void);
	void Draw(void);

	int _ghTitleScreen;
	Vector2F _pos;	//タイトルロゴの座標
	float _bright;	//明るさ
};

