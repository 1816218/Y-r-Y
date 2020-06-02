#pragma once
#include <memory>
#include <vector>
#include <tuple>
#include "BaseScene.h"
#include "../VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;	//ｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙ、x、y

enum class DRAW_QUE
{
	IMAGE,	//ｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙ
	X,		//X座標
	Y,		//Y座標
	MAX
};

class SceneMng
{
public:
	static SceneMng& GetInstance()
	{
		return (*s_Instance);
	}

	//メインループ処理
	void Run(void);

	bool SetScreen(int ghScreen);
	bool RevScreen(void);

	void Draw(void);

	bool AddDrawQue(const int localZorder, DrawQueT que);
	bool DeleteDrawQue(void);

	const Vector2Dbl screenSize;		// 画面の大きさ
private:
	struct SceneMngDeleter
	{
		void operator()(SceneMng* sceneMng) const
		{
			delete sceneMng;
		}
	};
	SceneMng();
	~SceneMng();

	//システム初期化処理
	bool SysInit(void);

	unique_Base SelectScene(void);

	unique_Base _activeScene;	//動作しているシーン
	SCN_ID _sceneID;

	int _ghBefor;	//前の画面
	std::vector<std::pair<int, DrawQueT>> _drawList;	//描画するもの

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

