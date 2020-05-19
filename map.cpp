#include"map.h"
//実体のマップチップはｃｐｐ側に定義する

int bgImage[64];//マップチップの画像用

Map::Map:MODEL_BASE()
{
//画像の読み込み
	LoadDivGraph("image/bgImage.png", 256, 16, 4, 16, 16, bgImage);
	Init();
}
Map::~Map()
{

}

void Map::Init()
{
	//mapData.csvを開く
	FILE *fp;
	//ファイルオープン
	fopen_s(&fp, "mapData.csv", "r");
	//ファイルからデータを読み込む
	//例外（ファイルがなかったらそのまま終了）
	if (fp == NULL)
	{
		return;
	}


	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			fscanf_s(fp, "%d,", &mapData[y][x]);

		}
	}
	//ファイルクローズ
	fclose(fp);
	return;
	
}

void Map::Draw()
{
	//マップチップ描画
	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		//DrawLine(0, y * 16,  512, y * 16, 0xffff00);
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			//DrawLine(x * 16,0 , x*16, 768, 0xff00ff);
			int no = mapData[y][x];
			if (no < 0)no = 0;
			if (no > 63)no = 0;
			DrawGraph(MAP_CHIP_SIZE*x, y *MAP_CHIP_SIZE, bgImage[no], TRUE);
		}
	}
	
}
