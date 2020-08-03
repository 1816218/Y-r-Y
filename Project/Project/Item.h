#pragma once
#include <array>
#include "Obj.h"
#include "VECTOR2.h"
#include "InputKey.h"

extern int ItemCount;
extern int ItemFlag;
class Item : public Obj
{
public:
	  Item();
	Item(const Vector2F& pos, const Vector2F& size);
	~Item();
	
	bool Init(void);
	void mapItem(void);
	//-----Get�ESet
	//���W
	const Vector2F& GetPos(void);
	void SetPos(const Vector2F& pos);
	//�T�C�Y
	const Vector2F& GetSize(void);
	void SetSize(const Vector2F& size);
	//�`��
	void Draw(void) ;
	void Update(void);

private:
	Vector2F _pos;
	Vector2F _size;
	
};

