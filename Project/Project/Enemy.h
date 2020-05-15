#pragma once
#include "VECTOR2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	bool Init(void);
	void UpDate(void);
	void Draw(void);

	void SetPos(Vector2& pos);
private:

	Vector2F _pos;	//ç¿ïW
	float _speed;	//â¡ë¨ìx

	Vector2 _playerPos;

};

