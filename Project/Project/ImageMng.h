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
		// À‘Ô‚ğ‚Á‚Ä‚¢‚È‚¢‚È‚çºİ½Ä×¸À°‚ğŒÄ‚Ô
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// À‘Ô‚ğ•Ô‚·
	}
	~ImageMng() {}

	//“o˜^
	const VEC_INT& SetID(const std::string & keyName, const std::string & fileName);

	//“o˜^(ƒAƒjƒ[ƒVƒ‡ƒ“)
	const VEC_INT& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//‰æ‘œƒnƒ“ƒhƒ‹æ“¾
	const VEC_INT& GetID(const std::string& keyName);
private:
	ImageMng() {}

	//-----‰æ‘œ“o˜^—pmap
	std::map<std::string, VEC_INT> imgMap;	//‰æ‘œ“o˜^(–¼‘OA‰æ‘œ)

	static ImageMng* s_Instance;
};

