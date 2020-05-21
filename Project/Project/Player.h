#pragma once
#include <DxLib.h>
#include"VECTOR2.h"
#include "InputKey.h"

//方角の種類
enum P_DIR 
{
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_MAX
};

class Player
{
public:
	Player();
	~Player();
	void Init(void);
	void Update(void);

	//描画
	void Draw(void);

	//移動処理
	void SetMove(const KEY_CODE& key, const P_DIR& dir, const Vector2F& speed, bool flg);

	//現在の座標を取得する
	Vector2F& GetPos(void);
private:
	//移動可能範囲(範囲：マップ内)
	bool CheckRangeMove(const Vector2F& startPos, const Vector2F& endPos);


	Vector2F _pos;
	int _dir;
	int _animeCnt;
	bool _moveFlag;
	Vector2F _size;
	Vector2F _speed;
};
