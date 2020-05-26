#pragma once
#include <DxLib.h>
#include <string>
#include "VECTOR2.h"

enum class CHARA_DIR
{
	UP		= 3,
	RIGHT	= 2,
	LEFT	= 1,
	DOWN	= 0,
	MAX
};


class Obj
{
public:
	Obj();
	~Obj();

	bool Init(void);

	virtual void Update(void) = 0;

	//描画
	virtual void Draw(void) = 0;

	void DrawRotaF(int GHandle, int TransFlag);

	//オブジェクトを消す判定
	bool DeathPro(void);

	//生存確認
	bool isAlive(void) { return _alive; }

	//死亡確認
	bool isDeath(void) { return _death; }

	virtual const Vector2F& GetPos(void);
	virtual void SetPos(const Vector2F& pos);

	virtual const Vector2F& GetSize(void);
	virtual void SetSize(const Vector2F& size);

	virtual const double GetAngle(void);
	virtual void SetAngle(const double angle);

	virtual const double GetExRate(void);
	virtual void SetExRate(const double exRate);
protected:
	Vector2F _pos;	//float型
	Vector2F _size;	//flaot型
	double _angle;	//角度
	double _exRate;	//拡大率
	bool _alive;	//true:生きている、false:生きていない
	bool _death;	//true:死んでいる、false:死んでいない
};

