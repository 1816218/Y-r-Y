#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Map.h"
#include "ImageMng.h"

Map* Map::s_Instance = nullptr;

//-----描画処理
void Map::Draw(void)
{
	for (auto map : _mapData)
	{
		if (map.first == DRAW_SCREEN::FRONT)
		{
			DrawScreen(map.second, 100, { _ghFrontScreen, 0, 0 });
		}
		else
		{
			DrawScreen(map.second, 0, { _ghBackScreen, 0, 0 });
		}
	}
}
//-----当たり判定
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//座標をマップチップに変換
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//壁に当たっていたら当たったことにする
	for (auto map : _mapData)
	{
		for (auto data : map.second)
		{
			if (data.chipPos.x == chip.x && data.chipPos.y == chip.y)
			{
				if (data.state == CHIP_STATE::HIT)
				{
					return true;	//当たっている
				}
			}
		}
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
	ReadFile(DRAW_SCREEN::FRONT, "Data/stage1_front.csv");
	ReadFile(DRAW_SCREEN::BACK, "Data/stage1_back.csv");

	//描画対象にする画面の作成
	_ghFrontScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghBackScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----ファイルの読み込み
bool Map::ReadFile(DRAW_SCREEN screen, const std::string& fileName)
{
	std::ifstream ifs;
	std::string line;
	MapChip data;
	VecMap map;

	//ファイルを開く
	ifs.open(fileName);

	//ファイルを開くのに失敗したら処理をしない
	if (ifs.fail())
	{
		return false;
	}

	{//マップチップの最大数を設定
		//カンマ区切りで文字列を格納する
		std::getline(ifs, line);
		std::vector<std::string> strVec = Split(line, ',');
		_mapChip = { atoi(strVec.at(0).c_str()), atoi(strVec.at(1).c_str()) };
	}

	//メモリの確保(マップチップの総数)
	map.reserve(_mapChip.y * _mapChip.x);

	for(int y = 0; y<_mapChip.y; y++)
	{
		//カンマ区切りで文字列を格納する
		std::getline(ifs, line);
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char→intへ変換した数値を代入
			int num = atoi(strVec.at(x).c_str());

			data.id = num / 10;
			data.chipPos = { x, y };

			//チップの状態を登録
			if (num % 10 == 0)
			{
				data.state = CHIP_STATE::HIT;
			}
			else if (num % 10 == 1)
			{
				data.state = CHIP_STATE::NOT_HIT;
			}
			else
			{
				data.state = CHIP_STATE::NOT_DRAW;
			}
			map.push_back(data);
		}
	}
	ifs.close();	//ファイルを閉じる

	_mapData.push_back(std::make_pair(screen, map));

	return true;
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
void Map::DrawScreen(VecMap& mapData, int localZorder, DrawQueT drawQue)
{
	lpSceneMng.SetScreen(std::get<static_cast<int>(DRAW_QUE::IMAGE)>(drawQue));
	ClearDrawScreen();
	for (auto map : mapData)
	{
		if (map.state != CHIP_STATE::NOT_DRAW)
		{
 			DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[map.id], true);
		}
	}
	lpSceneMng.AddDrawQue(localZorder, drawQue);
	lpSceneMng.RevScreen();
}
