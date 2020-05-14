#include <DxLib.h>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//²İ½Àİ½‚·‚é

//-----‰æ‘œ‚Ì“o˜^(‰æ‘œˆê–‡)
const int& ImageMng::SetID(std::string fileName)
{
	if (imgMap.find(fileName) == imgMap.end())
	{
		imgMap[fileName] = LoadGraph(fileName.c_str());
	}
	return imgMap[fileName];
}
//-----‰æ‘œ‚Ì“o˜^(ƒAƒjƒ[ƒVƒ‡ƒ“)
const VEC_INT& ImageMng::SetID(const std::string& fileName, const Vector2& divSize, const Vector2& divNum)
{
	if (imgDivMap.find(fileName) == imgDivMap.end())
	{
		//“®“I‚È—v‘f”‚ğİ’è(vectorŒ^”z—ñ)
		imgDivMap[fileName].reserve(divNum.x * divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x* divNum.y, divNum.x, divNum.y, divSize.x,divSize.y, &imgDivMap[fileName][0], true);
	}

	return imgDivMap[fileName];
}
