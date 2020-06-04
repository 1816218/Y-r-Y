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
		// 実態を持っていないならｺﾝｽﾄﾗｸﾀｰを呼ぶ
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);	// 実態を返す
	}
	~ImageMng();

	//登録
	//@param keyName 呼び出す名前
	//@param fileName 画像ファイル名
	const VecInt& SetID(const std::string & keyName, const std::string & fileName);

	//登録(アニメーション)
	//@param keyName 呼び出す名前
	//@param fileName 画像ファイル名
	//@param divSize 画像サイズ(float)
	//@param divNum 画像チップ数(int)
	const VecInt& SetID(const std::string& keyName, const std::string & fileName, const Vector2F & divSize, const Vector2 & divNum);

	//画像ハンドル取得
	//@param keyName 呼び出す名前
	const VecInt& GetID(const std::string& keyName);

	//画像の削除
	//@param keyName 呼び出す名前
	bool DeleteImageMap(const std::string& keyName);

	//すべての画像の削除
	bool DeleteAllImageMap(void);

private:
	ImageMng() {}

	//-----画像登録用map
	std::map<std::string, VecInt> _imgMap;		//画像登録(名前、画像)

	static ImageMng* s_Instance;
};

