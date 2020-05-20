#include <DxLib.h>
#include "Map.h"
#include "ImageMng.h"

Map* Map::s_Instance = nullptr;

Map::Map()
{
	Init();
}

Map::~Map()
{
}

void Map::Init()
{
	FILE *fp;
	
	//�t�@�C�����J��
	if ((fopen_s(&fp, "Data/mapData.csv", "rb")) != 0)
	{
		for (int y = 0; y < MAP_CHIP_Y; y++)
		{
			for (int x = 0; x < MAP_CHIP_X; x++)
			{
				mapData[y][x] = 0;
			}
		}

		DrawString(0, 0, "�t�@�C���͊J���܂���ł���", 0xffffff);
		return;
	}

	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			fread(&mapData[y][x], 4, 24, fp);
		}
	}
	DrawString(0, 0, "�t�@�C�����J���܂���!", 0xffffff);

	fclose(fp);	//�t�@�C�������
}

void Map::Draw(void)
{
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			DrawFormatString(x*16,y*16, 0xffffff, "%d", mapData[y][x]);
		}
	}
}

