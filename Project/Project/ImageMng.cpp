#include <DxLib.h>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//²Ý½ÀÝ½·é

//-----æÌo^(æê)
const int& ImageMng::SetID(std::string fileName)
{
	if (imgMap.find(fileName) == imgMap.end())
	{
		imgMap[fileName] = LoadGraph(fileName.c_str());
	}
	return imgMap[fileName];
}
//-----æÌo^(Aj[V)
const VEC_INT& ImageMng::SetID(const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (imgDivMap.find(fileName) == imgDivMap.end())
	{
		//®IÈvfðÝè(vector^zñ)
		imgDivMap[fileName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y,divNum.x, divNum.y,divSize.x, divSize.y,&imgDivMap[fileName][0], true);
	}
	return imgDivMap[fileName];
}
