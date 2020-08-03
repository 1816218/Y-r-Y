#pragma once
#include <array>
#include "Obj.h"
#include "VECTOR2.h"
#include "InputKey.h"
class Item : public Obj
{
public:
	  Item();
	Item(const Vector2F& pos, const Vector2F& size);
	~Item();

	bool Init(void);
	void mapItem(void);

	//•`‰æ
	void Draw(void) ;
	void Update(void);

private:
	Vector2F _pos;
	Vector2F _size;
};

