#pragma once
#include <map>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) ImageMng::GetInstance().GetID(KEY)

using VecInt = std::vector<int>;

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
	~ImageMng();

	//�o�^
	//@param keyName �Ăяo�����O
	//@param fileName �摜�t�@�C����
	const VecInt& SetID(const std::string & keyName, const std::string & fileName);

	//�o�^(�A�j���[�V����)
	//@param keyName �Ăяo�����O
	//@param fileName �摜�t�@�C����
	//@param divSize �摜�T�C�Y(float)
	//@param divNum �摜�`�b�v��(int)
	const VecInt& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//�摜�n���h���擾
	//@param keyName �Ăяo�����O
	const VecInt& GetID(const std::string& keyName);

	//�摜�̍폜
	//@param keyName �Ăяo�����O
	bool DeleteImageMap(const std::string& keyName);

	//���ׂẲ摜�̍폜
	bool DeleteAllImageMap(void);

private:
	ImageMng() {}

	//-----�摜�o�^�pmap
	std::map<std::string, VecInt> _imgMap;		//�摜�o�^(���O�A�摜)

	static ImageMng* s_Instance;
};

