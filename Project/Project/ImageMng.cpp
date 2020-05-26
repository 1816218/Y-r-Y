#include <DxLib.h>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//²Ý½ÀÝ½·é

//-----æÌo^(æê)
const VEC_INT& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
{
	if (imgMap.find(keyName) == imgMap.end())
	{
		//®IÈvfðÝè(vector^zñ)
		imgMap[keyName].resize(1);

		imgMap[keyName][0] = LoadGraph(fileName.c_str());
	}
	return imgMap[keyName];
}
//-----æÌo^(Aj[V)
const VEC_INT& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (imgMap.find(keyName) == imgMap.end())
	{
		//®IÈvfðÝè(vector^zñ)
		imgMap[keyName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y, divNum.x, divNum.y, divSize.x, divSize.y, &imgMap[keyName][0], true);
	}
	return imgMap[keyName];
}

const VEC_INT& ImageMng::GetID(const std::string& keyName)
{
	if (imgMap.find(keyName) != imgMap.end())
	{
		return imgMap[keyName];
	}
}
