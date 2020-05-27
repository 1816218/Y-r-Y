#include <DxLib.h>
#include <algorithm>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//ｲﾝｽﾀﾝｽする

//-----画像の登録(画像一枚)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//動的な要素数を設定(vector型配列)
		_imgMap[keyName].resize(1);

		_imgMap[keyName][0] = LoadGraph(fileName.c_str());
	}
	return _imgMap[keyName];
}
//-----画像の登録(アニメーション)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//動的な要素数を設定(vector型配列)
		_imgMap[keyName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y, divNum.x, divNum.y, divSize.x, divSize.y, &_imgMap[keyName][0], true);
	}
	return _imgMap[keyName];
}
//-----画像ハンドルを取得
const Vec_int& ImageMng::GetID(const std::string& keyName)
{
	//要素が見つかったら画像ハンドルを返す
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		return _imgMap[keyName];
	}
}
//-----描画順番を登録
void ImageMng::StackDrawList(int localZorder, Vec_int drawGraph)
{
	_drawList.insert(std::make_pair(localZorder, drawGraph));
}
