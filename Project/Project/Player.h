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

	Vector2F& GetPos(void);

private:

	Vector2F _pos;
	int _dir;
	int _animeCnt;
	bool _moveFlag;
	Vector2F _speed;
};
