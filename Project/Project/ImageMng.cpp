#include <DxLib.h>
#include <algorithm>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//²İ½Àİ½‚·‚é

//-----‰æ‘œ‚Ì“o˜^(‰æ‘œˆê–‡)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//“®“I‚È—v‘f”‚ğİ’è(vectorŒ^”z—ñ)
		_imgMap[keyName].resize(1);

		_imgMap[keyName][0] = LoadGraph(fileName.c_str());
	}
	return _imgMap[keyName];
}
//-----‰æ‘œ‚Ì“o˜^(ƒAƒjƒ[ƒVƒ‡ƒ“)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//“®“I‚È—v‘f”‚ğİ’è(vectorŒ^”z—ñ)
		_imgMap[keyName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y, divNum.x, divNum.y, divSize.x, divSize.y, &_imgMap[keyName][0], true);
	}
	return _imgMap[keyName];
}

const Vec_int& ImageMng::GetID(const std::string& keyName)
{
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		return _imgMap[keyName];
	}
}
