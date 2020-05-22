#pragma once
#include "VECTOR2.h"
enum E_DIR
{
	EDIR_DOWN,
	EDIR_LEFT,
	EDIR_RIGHT,
	EDIR_UP,
	EDIR_MAX
};

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

	Vector2F _pos;	//ç¿ïW
	float _speed;	//â¡ë¨ìx
	float _Flag;
	int _animeCnt;
	bool _moveFlag;
	int _dir;
	Vector2F _size;
	Vector2 _playerPos;

};

