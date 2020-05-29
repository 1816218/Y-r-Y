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
	ReadFile("Data/map.csv");
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
//-----ファイルの読み込み
void Map::ReadFile(const std::string fileName)
{
	std::ifstream ifs;
	std::string line;

	ifs.open(fileName);
	if (ifs.fail())
	{
		return;
	}
	int y = 0;
	while (std::getline(ifs, line))
	{
		std::vector<std::string> strVec = Split(line, ',');
		for (int i = 0; i < strVec.size(); i++)
		{
			_mapData[y][i].id = atoi(strVec.at(i).c_str());
		}
		y++;
	}
	ifs.close();
}
//-----文字列を格納
std::vector<std::string> Map::Split(std::string& input, char delimiter)
{
	std::istringstream stream(input);
	std::string filed;
	std::vector<std::string> result;

	while (std::getline(stream, filed, delimiter))
	{
		result.push_back(filed);
	}
	return result;
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

