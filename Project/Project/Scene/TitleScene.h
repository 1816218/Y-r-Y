#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	unique_Base UpDate(unique_Base own) override;

	SCN_ID GetSceneID(void);
private:
	bool Init(void);
	void Draw(void);

	Vector2F pos;	//�^�C�g�����S�̍��W
	float bright;	//���邳
};
