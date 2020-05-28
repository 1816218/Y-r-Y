#pragma once
#include "Obj.h"
#include "VECTOR2.h"

class Item : public Obj
{
public:
	Item() {}
	Item(const Vector2F& pos, const Vector2F& size);
	~Item();

	bool Init(void);
	void Update(void) override;

	//描画
	void Draw(void) override;


	//-----Get・Set
	//座標
	const Vector2F& GetPos(void);
	void SetPos(const Vector2F& pos);
	//サイズ
	const Vector2F& GetSize(void);
	void SetSize(const Vector2F& size);
	//角度
	const double GetAngle(void);
	void SetAngle(const double angle);
	//拡大率
	const double GetExRate(void);
	void SetExRate(const double exRate);
private:
	bool _moveFlag;			//true:移動、false:停止
	CHARA_DIR _direction;	//向き
	int _animCnt;			//アニメーションカウント
};

