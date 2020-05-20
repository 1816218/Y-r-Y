#pragma once
#include "VECTOR2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	bool Init(void);
	void Update(void);
	void Draw(void);

	void SetPos(Vector2& pos);
private:

	Vector2F _pos;	//座標
	float _speed;	//加速度
	float _Flag;
	int _animeCnt;
	bool _moveFlag;
	int _dir;
	Vector2F _size;
	Vector2 _playerPos;

};

