#pragma once

#include"main.h"
#include"VECTOR2.h"
class MODEL_BASE
{
protected:
	int model;		//モデルデータ用
	//VECTOR target;//向いている方向
	Vector2 pos;	//XYZ軸方向
public:
	
	MODEL_BASE() {};
	~MODEL_BASE() {};
	//必ず継承したクラスで実装する必要がある
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

//	VECTOR GetPosition() { return pos; }
	/*VECTOR GetRotation() { return rol; }
	VECTOR GetTarget() { return target; }
	*/
};
