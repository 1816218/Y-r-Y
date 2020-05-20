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
	////�t�@�C�����J��
	//fopen_s(&fp, "Data/map.csv", "r");

	////�t�@�C���̒��g����Ȃ珈���𔲂���
	//if (fp == nullptr)
	//{
	//	return;
	//}

	////�t�@�C���̓ǂݍ���
	//for (int y = 0; y < MAP_CHIP_Y; y++)
	//{
	//	for (int x = 0; x < MAP_CHIP_X; x++)
	//	{
	//		fscanf_s(fp, "%d", &mapData[y][x]);
	//	}
	//}

	//fclose(fp);	//�t�@�C�������
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

