#pragma once
#include <memory>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpMap Map::GetInstance()

#define MAP_CHIP_X 25
#define MAP_CHIP_Y 20

class Map
{
public:
	static Map& GetInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new Map();
		}
		return *s_Instance;
	}
	~Map();

	void Init(void);
	void Draw(void);

private:
	Map();

	int _image[24];							//画像のハンドル
	int _mapData[MAP_CHIP_Y][MAP_CHIP_X];	//マップデータを格納

	Vector2 _mapChipSize;	//マップチップのサイス

	static Map* s_Instance;
};

