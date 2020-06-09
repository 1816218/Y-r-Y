#include <DxLib.h>
#include <algorithm>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//ｲﾝｽﾀﾝｽする

//-----画像の登録(画像一枚)
const VecInt& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
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
const VecInt& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//動的な要素数を設定(vector型配列)
		_imgMap[keyName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y, divNum.x, divNum.y, (int)divSize.x, (int)divSize.y, &_imgMap[keyName][0], true);
	}
	return _imgMap[keyName];
}
//-----画像ハンドルを取得
const VecInt& ImageMng::GetID(const std::string& keyName)
{
	//要素が見つかったら画像ハンドルを返す
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		return _imgMap[keyName];
	}
}
//-----画像の削除
bool ImageMng::DeleteImageMap(const std::string& keyName)
{
	// 条件一致した要素を削除する
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		DeleteGraph(_imgMap[keyName][0]);
		_imgMap.erase(keyName);
		return true;
	}
	return false;
}
//-----全ての画像の削除
bool ImageMng::DeleteAllImageMap(void)
{
	//コンテナが空でなければ
	//要素をすべて削除
	if (!_imgMap.empty())
	{
		InitGraph();
		_imgMap.clear();
		return true;
	}
	return false;
}

ImageMng::~ImageMng()
{
}
