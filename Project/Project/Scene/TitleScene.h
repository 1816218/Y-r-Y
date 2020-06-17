#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	//内容の更新
	void Update(void) override;
	//シーン情報を取得する
	SCN_ID GetSceneID(void) override;
private:
	//初期化処理
	bool Init(void);
	//描画処理
	void Draw(void);

	float	_bright;		//画面の明るさ
	int		_ghTitleScreen;	//描画対象にするｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙを保持する
	int		_animFrame;		//アニメーション用
	int		_alphaCount;		//画像のブレンド：アルファ値		
};

