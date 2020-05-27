#include <DxLib.h>
#include <algorithm>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//²Ý½ÀÝ½·é

//-----æÌo^(æê)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//®IÈvfðÝè(vector^zñ)
		_imgMap[keyName].resize(1);

		_imgMap[keyName][0] = LoadGraph(fileName.c_str());
	}
	return _imgMap[keyName];
}
//-----æÌo^(Aj[V)
const Vec_int& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//®IÈvfðÝè(vector^zñ)
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
