#include <DxLib.h>
#include <algorithm>
#include "ImageMng.h"

ImageMng* ImageMng::s_Instance = nullptr;	//�ݽ�ݽ����

//-----�摜�̓o�^(�摜�ꖇ)
const VecInt& ImageMng::SetID(const std::string& keyName, const std::string& fileName)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//���I�ȗv�f����ݒ�(vector�^�z��)
		_imgMap[keyName].resize(1);

		_imgMap[keyName][0] = LoadGraph(fileName.c_str());
	}
	return _imgMap[keyName];
}
//-----�摜�̓o�^(�A�j���[�V����)
const VecInt& ImageMng::SetID(const std::string& keyName, const std::string& fileName, const Vector2F& divSize, const Vector2& divNum)
{
	if (_imgMap.find(keyName) == _imgMap.end())
	{
		//���I�ȗv�f����ݒ�(vector�^�z��)
		_imgMap[keyName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y, divNum.x, divNum.y, (int)divSize.x, (int)divSize.y, &_imgMap[keyName][0], true);
	}
	return _imgMap[keyName];
}
//-----�摜�n���h�����擾
const VecInt& ImageMng::GetID(const std::string& keyName)
{
	//�v�f������������摜�n���h����Ԃ�
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		return _imgMap[keyName];
	}
}
//-----�摜�̍폜
bool ImageMng::DeleteImageMap(const std::string& keyName)
{
	// ������v�����v�f���폜����
	if (_imgMap.find(keyName) != _imgMap.end())
	{
		DeleteGraph(_imgMap[keyName][0]);
		_imgMap.erase(keyName);
		return true;
	}
	return false;
}
//-----�S�Ẳ摜�̍폜
bool ImageMng::DeleteAllImageMap(void)
{
	//�R���e�i����łȂ����
	//�v�f�����ׂč폜
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
