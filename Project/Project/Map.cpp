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
			fscanf_s(fp, "%d", &mapData[y][x]);
		}
	}
	fclose(fp);	//�t�@�C�������
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
					// �u���b�N�ɓ�������
					DrawString(0, 0, "��������!", 0xffffff);
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
