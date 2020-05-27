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
		// À‘Ô‚ğ‚Á‚Ä‚¢‚È‚¢‚È‚çºİ½Ä×¸À°‚ğŒÄ‚Ô
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// À‘Ô‚ğ•Ô‚·
	}
	~ImageMng() {}

	//“o˜^
	const Vec_int& SetID(const std::string & keyName, const std::string & fileName);

	//“o˜^(ƒAƒjƒ[ƒVƒ‡ƒ“)
	const Vec_int& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//‰æ‘œƒnƒ“ƒhƒ‹æ“¾
	const Vec_int& GetID(const std::string& keyName);

	//•`‰æ‡‚Ì“o˜^
	void StackDrawList(int localZorder, Vec_int drawGraph);

private:
	ImageMng() {}

	//-----‰æ‘œ“o˜^—pmap
	std::map<std::string, Vec_int> _imgMap;		//‰æ‘œ“o˜^(–¼‘OA‰æ‘œ)

	std::map<int, std::vector<int>> _drawList;	//•`‰æ‡‚Ì“o˜^

	static ImageMng* s_Instance;
};

