#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"
#include "Item.h"
int ItemFlag;
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

	ItemCount = 0;
	ItemFlag = FALSE;
	return true;
}
void Item::Update(void)
{
	
	/*if (CheckHitKey(KEY_INPUT_A))
	{
		ItemFlag = TRUE;
		ItemCount = 3;
	}*/
}

void Item::mapItem(void)
{
	while (Init()==true) {
		_pos = { GetRand(50 - 1) * _size.x + 8, GetRand(32 - 1) * _size.y + 8 };

	}

}
//-----描画
void Item::Draw(void)
{
	if (ItemFlag == FALSE) {
		DrawRotaGraph(_pos.x - lpMap.GetScrooll().x, _pos.y - lpMap.GetScrooll().y, 1.0f, 0, IMAGE_ID("Elixir")[0], true);
	}
}
//-----Get・Set
//座標
const Vector2F& Item::GetPos(void)
{
	return _pos;
}

void Item::SetPos(const Vector2F& pos)
{
	_pos = pos;
}
//サイズ
const Vector2F& Item::GetSize(void)
{
	return _size;
}

void Item::SetSize(const Vector2F& size)
{
	_size = size;
}