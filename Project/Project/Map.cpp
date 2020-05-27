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

	//-----�t�@�C���̓ǂݍ���
	FILE* fp;
	//�t�@�C�����J��
	fopen_s(&fp, "Data/test.csv", "r");	
	//�t�@�C���̒��g����Ȃ珈���𔲂���
	if (fp == nullptr)
	{
		return;
	}
	//�t�@�C���̓ǂݍ���
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			fscanf_s(fp, "%d", &_mapData[y][x]);
		}
	}
	fclose(fp);	//�t�@�C�������
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
	case 0:		//��(��)
	case 1:
	case 2:
	case 6:
	case 7:
	case 8:
	case 12:
	case 13:
	case 14:
	case 9:		//��(�D)
	case 10:
	case 11:	//��(���A��)
	case 15:
	case 23:
		return true;
		break;
	}
	return false;
}

