#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Scene/SceneMng.h"
#include "VECTOR2.h"

#define lpMap Map::GetInstance()
#define MAP_CHIP_X 50
#define MAP_CHIP_Y 20

//マップチップの状態
enum class CHIP_STATE
{
	HIT,		//当たる
	NOT_HIT,	//当たらない
	FRONT,		//前面
	MAX
};

//描画対象にする画面
enum class DRAW_SCREEN
{
	FRONT,	//前画面
	BACK,	//後ろ画面
	MAX
};

struct MapChip
{
	int			id;			//画像番号
	Vector2		chipPos;	//マップチップ座標
	CHIP_STATE	state;		//マップチップの状態
};

using VecMap = std::vector<MapChip>;
using PairMap = std::pair<DRAW_SCREEN, VecMap>;

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
	//@param chip マップチップ数
	//@param flag 描画対象(true：前面、false：後面)
	bool ReadFile(DRAW_SCREEN screen, const std::string& fileName);

	//特定の文字で区切った文字列を返す
	//@param input 読み込んだ一行分の文字列
	//@param delimiter 区切る文字
	std::vector<std::string> Split(std::string& input, char delimiter);

	//画面に描画
	void DrawScreen(VecMap& mapData, int localZorder, DrawQueT que);

	int		_ghFrontScreen;	//前画面
	int		_ghBackScreen;	//後画面
	std::vector<MapChip>	_mapFront;		//マップデータを保持(前面)
	std::vector<MapChip>	_mapBack;		//マップデータを保持(後面)

	std::vector<std::pair<DRAW_SCREEN, VecMap>> _mapData;

	Vector2					_mapChip;		//マップチップの最大数
	Vector2					_mapChipSize;	//マップチップのサイズ

	static Map* s_Instance;
};

