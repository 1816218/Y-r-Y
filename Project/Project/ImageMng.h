#pragma once
#include <map>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define  IMAGE_ID(N) ImageMng::GetInstance(N)
using VEC_INT = std::vector<int>;

class ImageMng
{
public:
	static ImageMng& GetInstance()
	{
		// ���Ԃ������Ă��Ȃ��Ȃ�ݽ�׸�����Ă�
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// ���Ԃ�Ԃ�
	}
	~ImageMng() {}

	//�o�^
	const int& SetID(std::string fileName);

	//�o�^(�A�j���[�V����)
	const VEC_INT& SetID(const std::string & fileName, const Vector2 & divSize, const Vector2 & divNum);
private:
	ImageMng();

	//-----�摜�o�^�pmap
	std::map<std::string, int> imgMap;	//�摜�ꖇ�p
	std::map<std::string, VEC_INT>imgDivMap;	//�A�j���[�V�����p

	static ImageMng* s_Instance;
};

