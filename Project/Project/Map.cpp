#include <DxLib.h>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "ImageMng.h"
#include "Scene/SceneMng.h"

Map* Map::s_Instance = nullptr;

//-----描画処理
void Map::Draw(void)
{
	lpSceneMng.SetScreen(_ghMapScreen);
	ClearDrawScreen();

	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			if ((_mapData[y][x].id != 3) && (_mapData[y][x].id != 4))
			{
				DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x].id], true);
			}
		}
	}

	lpSceneMng.AddDrawQue(0, { _ghMapScreen, 0, 0 });
	lpSceneMng.RevScreen();

	lpSceneMng.SetScreen(_ghFrool);
	ClearDrawScreen();

	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			if ((_mapData[y][x].id == 3) || (_mapData[y][x].id == 4))
			{
				DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x].id], true);
			}
		}
	}

	lpSceneMng.AddDrawQue(10, { _ghFrool, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----当たり判定
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//座標をマップチップに変換
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//壁に当たっていたら当たったことにする
	if (_mapData[chip.y][chip.x].type == CHIP_TYPE::WALL)
	{
		return true;	//当たっている
	}
	return false;	//当たっていない
}

Map::Map() : _mapChipSize(32, 32)
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
	ReadFile("Data/stage1map.csv");

	//描画対象にする画面の作成
	_ghMapScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghFrool = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----ファイルの読み込み
void Map::ReadFile(const std::string fileName)
{
	std::ifstream ifs;
	std::string line;
	int y = 0;

	//ファイルを開く
	ifs.open(fileName);
	//ファイルを開くのに失敗したら処理をしない
	if (ifs.fail())
	{
		return;
	}
	//ファイルの終端まで一行ずつ読み込む
	while (std::getline(ifs, line))
	{
		//カンマ区切りの文字列を格納する
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char→intへ変換した数値を代入
			_mapData[y][x].id = atoi(strVec.at(x).c_str());

			//壁として登録
			if ((_mapData[y][x].id != 17) && (_mapData[y][x].id != 3) && (_mapData[y][x].id != 4))
			{
				_mapData[y][x].type = CHIP_TYPE::WALL;
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
