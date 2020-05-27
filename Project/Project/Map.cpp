#include <DxLib.h>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "ImageMng.h"
#include"HitCheck.h"

Map* Map::s_Instance = nullptr;

Map::Map() : _mapChipSize(32,32)
{
	Init();
}

Map::~Map()
{
}

void Map::Init(void)
{
<<<<<<< HEAD
	LoadDivGraph("image/map.png", 24, 6, 4, 32, 32, _image);
=======
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,4 });
>>>>>>> f0df67c88ec50f8131b76a2f235cd37b7219d606

	//-----ファイルの読み込み
	FILE* fp;
	//ファイルを開く
	fopen_s(&fp, "Data/test.csv", "r");	
	//ファイルの中身が空なら処理を抜ける
	if (fp == nullptr)
	{
		return;
	}
	//ファイルの読み込み
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			fscanf_s(fp, "%d", &_mapData[y][x]);
		}
	}
	fclose(fp);	//ファイルを閉じる
}

void Map::Hit(void)
{
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			int no = _mapData[MAP_CHIP_Y][MAP_CHIP_X];
			if (no >= 10 && no < 20)
			{
				if (HitCheck()(x * MAP_CHIP_X, y * MAP_CHIP_Y, 32, 32,
					x, y, 32, 32))
				{
					// ブロックに当たった
					DrawString(0, 0, "当たった!", 0xffffff);
				}
			}
		}
	}
}
void Map::Draw(void)
{
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x]], true);
		}
	}
}

bool Map::Collision(Vector2F pos, Vector2F size)
{
	Vector2 chip = { (int)(pos.x + size.x) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	int num = _mapData[chip.y][chip.x];

	switch (num)
	{
	case 9:
	case 10:
		return true;
		break;
	}
	return false;
}

