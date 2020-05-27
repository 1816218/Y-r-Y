#include <DxLib.h>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "ImageMng.h"


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
	lpImageMng.SetID("map", "image/map.png", { 32,32 }, { 6,4 });

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
			fscanf_s(fp, "%d", &_mapData[y][x].id);
			if (_mapData[y][x].id == 3 || _mapData[y][x].id == 4 || _mapData[y][x].id == 5 || _mapData[y][x].id == 16 || _mapData[y][x].id == 17 
				|| _mapData[y][x].id == 18 || _mapData[y][x].id == 19 || _mapData[y][x].id == 20 || _mapData[y][x].id == 21 || _mapData[y][x].id == 22)
			{
				continue;
			}
			_mapData[y][x].type = CHIP_TYPE::WALL;
		}
	}
	fclose(fp);	//ファイルを閉じる
}

void Map::Draw(void)
{
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x].id], true);
		}
	}
}

bool Map::Collision(Vector2F pos, Vector2F size)
{
	Vector2 chip = { (int)(pos.x + size.x) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	if (_mapData[chip.y][chip.x].type == CHIP_TYPE::WALL)
	{
		return true;
	}
	return false;
}

