#pragma once
#include <map>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) ImageMng::GetInstance().GetID(KEY)

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
	const VEC_INT& SetID(const std::string & keyName, const std::string & fileName);

	//�o�^(�A�j���[�V����)
	const VEC_INT& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//�摜�n���h���擾
	const VEC_INT& GetID(const std::string& keyName);
private:
	ImageMng() {}

	//-----�摜�o�^�pmap
	std::map<std::string, VEC_INT> imgMap;	//�摜�o�^(���O�A�摜)

	static ImageMng* s_Instance;
};

