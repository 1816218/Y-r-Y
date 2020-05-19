#pragma once
#include <DxLib.h>
#include"VECTOR2.h"
#include "InputKey.h"

//•ûŠp‚ÌŽí—Þ
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
	void Draw(void);
	
	void SetMove(const KEY_CODE& key, const P_DIR& dir, const Vector2F& speed, bool flg);
	bool IntersectRectRect(int _x1, int _y1, int _w1, int _h1, int _x2, int _y2, int _w2, int _h2);
	Vector2F& GetPos(void);

private:

	Vector2F _pos;
	int _dir;
	int _animeCnt;
	bool _moveFlag;

	Vector2F _speed;
};
