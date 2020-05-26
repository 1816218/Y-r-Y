#include <DxLib.h>
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
	LoadDivGraph("image/map.png", 24, 6, 4, 32, 32, _image);
	/*
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
			fscanf_s(fp, "%d", &mapData[y][x]);
		}
	}
	fclose(fp);	//ファイルを閉じる
	*/
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
			DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, _image[mapData[y][x]], true);
		}
	}
}
