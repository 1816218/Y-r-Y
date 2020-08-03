#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"
#include "Item.h"
Item::Item()
{
	Init();
}
Item::Item(const Vector2F& pos, const Vector2F& size)
{
	_pos = pos;
	_size = size;
	Init();
}

Item::~Item()
{
}

bool Item::Init(void)
{

	
	//mapItem();


	return true;
}
void Item::Update(void)
{
	/*if (_pos.x - 16 < _playerPos.x && _playerPos.x < _pos.x + 16 && _pos.y - 16 < _playerPos.y && _playerPos.y < _pos.y + 16)
	{
		lpSceneMng.SetSceneID(SCN_ID::OVER);
	}*/
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
	
	DrawRotaGraph(_pos.x- lpMap.GetScrooll().x, _pos.y- lpMap.GetScrooll().y, 1.0f, 0, IMAGE_ID("Elixir")[0], true);

}
