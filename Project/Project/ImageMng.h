#pragma once
#include <map>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) ImageMng::GetInstance().GetID(KEY)

using Vec_int = std::vector<int>;
using Pair_int = std::pair<int, int>;

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
	const Vec_int& SetID(const std::string & keyName, const std::string & fileName);

	//�o�^(�A�j���[�V����)
	const Vec_int& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//�摜�n���h���擾
	const Vec_int& GetID(const std::string& keyName);

	//�`�揇�̓o�^
	void StackDrawList(int localZorder, Vec_int drawGraph);

private:
	ImageMng() {}

	//-----�摜�o�^�pmap
	std::map<std::string, Vec_int> _imgMap;		//�摜�o�^(���O�A�摜)

	std::map<int, std::vector<int>> _drawList;	//�`�揇�̓o�^

	static ImageMng* s_Instance;
};

