#include "Map.h"

std::unique_ptr<Map, Map::MapDeleter> Map::s_Instance(new Map);

bool Map::Init()
{
	FILE* fp;
	
	//ファイルを開けなかった場合 false を返す
	if ((fopen_s(&fp, "date.csv", "r")) != 0)
	{
		return false;
	}

	fread(_mapData.data(), _mapData.size(), 1, fp);


	return true;
}

void Map::Draw(void)
{
}

Map::Map()
{
}

Map::~Map()
{
}
