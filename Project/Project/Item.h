#pragma once
#include "VECTOR2.h"

class Item
{
public:
	Item();
	~Item();

	bool Init(void);
	void mapItem(void);

	//�`��
	void Draw(void) ;


private:
	Vector2F _pos;
	Vector2F _size;
};

