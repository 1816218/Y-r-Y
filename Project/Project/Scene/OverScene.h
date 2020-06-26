#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class OverScene :
	public BaseScene
{
public:
	OverScene() : _pos({ 0,0 }), _bright(0), _ghOverScreen(0) {}
	OverScene(const Vector2F& pos, const int bright);
	~OverScene();

	//内容の更新
	void Update(void) override;
	//シーン情報を取得する
	SCN_ID GetSceneID(void) override;
private:
	//初期化処理
	bool Init(void);
	//描画処理
	void Draw(void);

	Vector2F _pos;			//画像の座標
	int		_bright;		//画面の明るさ
	int		_ghOverScreen;	//描画対象にするｸﾞﾗﾌｨｯｸﾊﾝﾄﾞﾙを保持する
};

