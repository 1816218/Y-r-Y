#pragma once
#include <memory>
#include <vector>

#define lpMap Map::GetInstance()
#define MAP_CHIP_X 8
#define MAP_CHIP_Y 3
#define MAP_CHIP_SIZE 32

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

	void Init();
	void Draw(void);

private:
	Map();

	int mapData[MAP_CHIP_Y][MAP_CHIP_X];

	static Map* s_Instance;
};

