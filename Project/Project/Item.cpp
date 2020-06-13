#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"
#include "Item.h"
Item::Item()
{
	Init();
}

Item::~Item()
{
}

bool Item::Init(void)
{

	_pos = { 0,0 };
	_size = { 32,32 };



	return true;
}

void Item::mapItem(void)
{
	while (Init()==true) {
		_pos = { GetRand(50 - 1) * _size.x + 8, GetRand(32 - 1) * _size.y + 8 };

	}

}
//-----•`‰æ
void Item::Draw(void)
{
	DrawRotaGraph(_pos.x, _pos.y, 1.0f, 0, IMAGE_ID("corone")[0], true);
	DrawRotaGraph(_pos.x, _pos.y, 1.0f, 0, IMAGE_ID("Elixir")[0], true);

}
