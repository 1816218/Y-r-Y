#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Map.h"
#include "ImageMng.h"
#include "Scene/SceneMng.h"

Map* Map::s_Instance = nullptr;

//-----描画処理
void Map::Draw(void)
{
	DrawScreen(_mapFront, 100, { _ghFrontScreen, 0, 0 });
	DrawScreen(_mapBack, 0, { _ghBackScreen, 0, 0 });
}
//-----当たり判定
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//座標をマップチップに変換
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//壁に当たっていたら当たったことにする
	if(_mapBack.at(chip.y * MAP_CHIP_X + chip.x).state == CHIP_STATE::HIT)
	{
		return true;	//当たっている
	}
	return false;	//当たっていない
}

Map::Map() : _mapChip(0,0), _mapChipSize(32, 32)
{
	Init();
}

Map::~Map()
{
}
//-----初期化処理
void Map::Init(void)
{
	//ファイルの読み込み
	ReadFile("Data/stage1_front.csv", { 50, 20 }, true);
	ReadFile("Data/stage1_back.csv", { 50, 20 }, false);

	//描画対象にする画面の作成
	_ghFrontScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghBackScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----ファイルの読み込み
//@param fileName ファイル名
//@param chip マップチップ数
//@param flag 描画対象(true：前面、false：後面)
void Map::ReadFile(const std::string fileName, const Vector2& chip, bool flag)
{
	std::ifstream ifs;
	std::string line;
	MapChip data;
	int y = 0;

	//チップの最大数を設定
	_mapChip = chip;

	//ファイルを開く
	ifs.open(fileName);
	//ファイルを開くのに失敗したら処理をしない
	if (ifs.fail())
	{
		return;
	}

	//メモリの確保(マップチップの総数)
	if (flag)
	{
		_mapFront.reserve(_mapChip.x * _mapChip.y);
	}
	else
	{
		_mapBack.reserve(_mapChip.x * _mapChip.y);
	}

	//ファイルの終端まで一行ずつ読み込む
	while (std::getline(ifs, line))
	{
		//カンマ区切りの文字列を格納する
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char→intへ変換した数値を代入
			data.id = atoi(strVec.at(x).c_str());
			data.chipPos = { x, y };

			//当たり判定用のIDの登録
			if (flag)
			{
				data.state = CHIP_STATE::FRONT;
				_mapFront.push_back(data);
			}
			else
			{
				if (data.id >= 0)
				{
					data.state = CHIP_STATE::HIT;	//当たる
				}
				else
				{
					data.state = CHIP_STATE::NOT_HIT;	//当たらない
				}
				_mapBack.push_back(data);
			}
		}
		y++;
	}
	ifs.close();	//ファイルを閉じる
}
//-----文字列を格納
std::vector<std::string> Map::Split(std::string& input, char delimiter)
{
	std::istringstream			stream(input);	//読み込んだ一行分の文字
	std::string					charString;		//文字列
	std::vector<std::string>	result;			//一行分の文字列

	//指定した文字で区切った文字列を格納する
	while (std::getline(stream, charString, delimiter))
	{
		result.push_back(charString);
	}
	return result;	//文字列を返す
}
//----画面に描画
void Map::DrawScreen(std::vector<MapChip>& mapData, int localZorder, DrawQueT que)
{
	//前面に描画
	lpSceneMng.SetScreen(std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que));
	ClearDrawScreen();
	for (auto map : mapData)
	{
		if (map.state == CHIP_STATE::FRONT)
		{
			if (map.id >= 0)
			{
				DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[map.id], true);
			}
		}
		else
		{
			DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[abs(map.id)], true);
		}
	}
	lpSceneMng.AddDrawQue(localZorder, que);
	lpSceneMng.RevScreen();
}
