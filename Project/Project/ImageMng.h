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
		// 実態を持っていないならｺﾝｽﾄﾗｸﾀｰを呼ぶ
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// 実態を返す
	}
	~ImageMng() {}

	//登録
	const int& SetID(std::string fileName);

	//登録(アニメーション)
	const VEC_INT& SetID(const std::string & fileName, const Vector2 & divSize, const Vector2 & divNum);
private:
	ImageMng();

	//-----画像登録用map
	std::map<std::string, int> imgMap;	//画像一枚用
	std::map<std::string, VEC_INT>imgDivMap;	//アニメーション用

	static ImageMng* s_Instance;
};

