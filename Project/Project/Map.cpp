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
	
	//ファイルを開く
	if ((fopen_s(&fp, "Data/map.csv", "rb")) != 0)
	{
		for (int y = 0; y < MAP_CHIP_Y; y++)
		{
			for (int x = 0; x < MAP_CHIP_X; x++)
			{
				mapData[y][x] = 0;
			}
		}

		DrawString(0, 0, "ファイルは開けませんでした", 0xffffff);
		return;
	}
	DrawString(0, 0, "ファイルが開けました!", 0xffffff);

	fclose(fp);	//ファイルを閉じる
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

