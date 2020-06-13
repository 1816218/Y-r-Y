#pragma once
#include <memory>
#include <vector>
#include <tuple>
#include "BaseScene.h"
#include "../VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;	//ｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙ、x、y

//描画データ
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

	//追加した画面をまとめて描画
	void Draw(void);

	//描画画面の設定
	//@param ghScreen 描画する画面
	bool SetScreen(int ghScreen);

	//表示する画面
	bool RevScreen(void);

	//描画する対象を追加
	//@param localZorder 描画順の指定(昇順)
	//@param que 作成した画面データと描画開始位(左上)
	bool AddDrawQue(const int localZorder, DrawQueT que);

	//描画した画面データをすべて消去
	bool DeleteAllDrawList(void);

	//画面サイスを取得する
	const Vector2F& GetScreenSize(void);

	//シーンを設定
	//@param id 設定するシーン
	void SetSceneID(const SCN_ID id);

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
	//シーン切り替え処理
	void SelectScene(void);
	//シーンの解放
	bool ResetActiveScene(void);

	SCN_ID									_sceneID;		//シーンの状態
	unique_Base								_activeScene;	//動作しているシーン
	const Vector2F							_screenSize;	//画面の大きさ
	int										_ghBefor;		//前の画面
	std::vector<std::pair<int, DrawQueT>>	_drawList;		//描画するもの

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

