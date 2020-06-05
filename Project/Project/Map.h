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

	//描画処理
	void Draw(void);

	//衝突判定
	//@param pos 座標
	//@param size サイズ
	bool Collision(Vector2F pos, Vector2F size);
private:
	Map();
	//初期化処理
	void Init(void);

	//ファイルの読み込み
	//@param fileName ファイル名
	void ReadFile(const std::string fileName);

	//特定の文字で区切った文字列を返す
	//@param input 読み込んだ一行分の文字列
	//@param delimiter 区切る文字
	std::vector<std::string> Split(std::string& input, char delimiter);

	MapChip _mapData[MAP_CHIP_Y][MAP_CHIP_X];

	Vector2 _mapChipSize;	//マップチップのサイス
	
	int _ghMapScreen;
	int _ghFrool;

	static Map* s_Instance;
};

