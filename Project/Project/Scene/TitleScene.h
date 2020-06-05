#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene() : _pos({ 0,0 }), _bright(0), _ghTitleScreen(0) {}
	TitleScene(const Vector2F& pos, const int bright);
	~TitleScene();

	//内容の更新
	unique_Base Update(unique_Base own) override;
	//シーン情報を取得する
	SCN_ID GetSceneID(void) override;
private:
	//初期化処理
	bool Init(void);
	//描画処理
	void Draw(void);

	Vector2F _pos;			//画像の座標
	float	_bright;		//画面の明るさ
	int		_ghTitleScreen;	//描画対象にするｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙを保持する
};

