#pragma once
#include <memory>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpMap Map::GetInstance()
#define MAP_CHIP_X 25
#define MAP_CHIP_Y 20

enum class CHIP_TYPE
{
	WALL,	//壁
	FLOOR	//床
};

struct MapChip
{
	CHIP_TYPE type;	//チップ種類
	int id;			//チップ番号
};

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

	//衝突判定
	bool Collision(Vector2F pos, Vector2F size);
private:
	Map();

	MapChip _mapData[MAP_CHIP_Y][MAP_CHIP_X];

	Vector2 _mapChipSize;	//マップチップのサイス

	static Map* s_Instance;
};

