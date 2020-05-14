#include <DxLib.h>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//�ݽ�ݽ����

//-----�摜�̓o�^(�摜�ꖇ)
const int& ImageMng::SetID(std::string fileName)
{
	if (imgMap.find(fileName) == imgMap.end())
	{
		imgMap[fileName] = LoadGraph(fileName.c_str());
	}
	return imgMap[fileName];
}
//-----�摜�̓o�^(�A�j���[�V����)
const VEC_INT& ImageMng::SetID(const std::string& fileName, const Vector2& divSize, const Vector2& divNum)
{
	if (imgDivMap.find(fileName) == imgDivMap.end())
	{
		//���I�ȗv�f����ݒ�(vector�^�z��)
		imgDivMap[fileName].reserve(divNum.x * divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x* divNum.y, divNum.x, divNum.y, divSize.x,divSize.y, &imgDivMap[fileName][0], true);
	}

	return imgDivMap[fileName];
}
