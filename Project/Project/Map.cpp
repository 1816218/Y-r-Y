#include <DxLib.h>
#include "Map.h"
#include "ImageMng.h"

Map* Map::s_Instance = nullptr;

Map::Map()
{
	LoadDivGraph("image/map.png", 24, 6, 4, 32, 32, _image);
	Init();
}

Map::~Map()
{
}

void Map::Init()
{
	//FILE *fp;
	//
	////ファイルを開く
	//fopen_s(&fp, "Data/map.csv", "r");

	////ファイルの中身が空なら処理を抜ける
	//if (fp == nullptr)
	//{
	//	return;
	//}

	////ファイルの読み込み
	//for (int y = 0; y < MAP_CHIP_Y; y++)
	//{
	//	for (int x = 0; x < MAP_CHIP_X; x++)
	//	{
	//		fscanf_s(fp, "%d", &mapData[y][x]);
	//	}
	//}

	//fclose(fp);	//ファイルを閉じる
}

void Map::Draw(void)
{
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			DrawGraph(x * 32, y * 32, _image[_mapData[y][x]], true);
		}
	}
}

