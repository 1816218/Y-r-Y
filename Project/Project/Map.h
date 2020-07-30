#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Scene/SceneMng.h"
#include "VECTOR2.h"

#define lpMap Map::GetInstance()
//アイテムカウント
extern int ItemCount;

//マップチップの状態
enum class CHIP_STATE
{
	HIT,		//当たる
	NOT_HIT,	//当たらない
	NOT_DRAW,	//描画しない
	GOAL,
	MAX
};
//描画対象にする画面
enum class DRAW_SCREEN
{
	FRONT,	//前画面
	BACK,	//後ろ画面
	MAX
};
//チップのデータ
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
	bool Collision(const Vector2F& pos, const Vector2F& size = {});

	//スクロール値取得
	const Vector2F& GetScrooll(void) const;
	//スクロール値の加算
	void AddScroll(const Vector2F& move = {});
	//マップチップの総数取得
	const Vector2& GetMapChipMax(void) const;
	//マップチップサイス取得
	const Vector2& GetMapChipSize(void) const;
private:
	Map();

	//初期化処理
	void Init(void);

	//ファイルの読み込み
	//@param screen 描画対象にする画面のID
	//@param fileName ファイル名
	bool ReadFile(DRAW_SCREEN screen, const std::string& fileName);

	//特定の文字で区切った文字列を返す
	//@param input 読み込んだ一行分の文字列
	//@param delimiter 区切る文字
	std::vector<std::string> Split(std::string& input, char delimiter);

	//画面に描画
	//@param mapData マップデータ
	//@param localZorder 描画順(昇順)
	//@param drawQue 描画する画面(ｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙ、ｘ、ｙ)
	void DrawScreen(const VecMap& mapData, int localZorder, DrawQueT drawQue);

	int						_ghFrontScreen;	//前画面
	int						_ghBackScreen;	//後画面
	std::vector<PairMap>	_mapData;		//マップデータ(描画する画面のID、マップデータ)
	Vector2					_mapChip;		//マップチップの最大数
	Vector2					_mapChipSize;	//マップチップのサイズ
	Vector2F				_scroll;		//スクロールさせる移動量
	static Map*				s_Instance;
};

