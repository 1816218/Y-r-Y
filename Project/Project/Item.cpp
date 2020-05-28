#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"
#include "Item.h"
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

	_angle = 0.0;
	_exRate = 1.0;



	return true;
}

void Item::mapItem(void)
{
	while (Init()==true) {
		_pos = { GetRand(MAP_CHIP_X - 1) * _size.x + 8, GetRand(32 - 1) * _size.y + 8 };
	}

}
//-----描画
void Item::Draw(void)
{
	DrawRotaGraph(_pos.x, _pos.y, _exRate, _angle, IMAGE_ID("enemy")[0], true);
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
//角度
const double Item::GetAngle(void)
{
	return _angle;
}

void Item::SetAngle(const double angle)
{
	_angle = angle;
}
//拡大率
const double Item::GetExRate(void)
{
	return _exRate;
}

void Item::SetExRate(const double exRate)
{
	_exRate = exRate;
}
