#pragma once

#include"main.h"
class MODEL_BASE
{
protected:
	int model;		//モデルデータ用
	int modelID;
	VECTOR target;//向いている方向
	VECTOR pos;//XYZ軸方向
	VECTOR rol;//回転
	VECTOR scl;
	VECTOR scale;
	VECTOR hitpos;//判定球の中心
	float hitR;//判定球の半径
	float dir;
	//アニメーション
	int attachiIndex;//アニメ番号登録
	float totalTime;//再生総時間
	float playTime;//再生箇所
public:
	
	MODEL_BASE() {};
	~MODEL_BASE() {};
	//必ず継承したクラスで実装する必要がある
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;

	VECTOR GetPosition() { return pos; }
	VECTOR GetRotation() { return rol; }
	VECTOR GetTarget() { return target; }
	
	
	
};
