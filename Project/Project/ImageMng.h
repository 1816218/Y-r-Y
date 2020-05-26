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
		// 実態を持っていないならｺﾝｽﾄﾗｸﾀｰを呼ぶ
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// 実態を返す
	}
	~ImageMng() {}

	//登録
	const VEC_INT& SetID(const std::string & keyName, const std::string & fileName);

	//登録(アニメーション)
	const VEC_INT& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//画像ハンドル取得
	const VEC_INT& GetID(const std::string& keyName);
private:
	ImageMng() {}

	//-----画像登録用map
	std::map<std::string, VEC_INT> imgMap;	//画像登録(名前、画像)

	static ImageMng* s_Instance;
};

