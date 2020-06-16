#pragma once
#include <array>
#include "Obj.h"
#include "VECTOR2.h"
#include "InputKey.h"

class Player : public Obj
{
public:
	Player();
	Player(const Vector2F& pos, const Vector2F& size);
	~Player();

	bool Init(void);
	void Update(void) override;

	//描画
	void Draw(void) override;

	//移動処理
	void Move(void);


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
	
	void AddMove(const KEY_CODE& key, const CHARA_DIR& dir, const Vector2F& add);

	int						_animCnt;		//アニメーションカウント
	bool					_moveFlag;		//true:移動、false:停止
	CHARA_DIR				_direction;		//向き
	std::array<Vector2F, 4> _edg;			//衝突判定用
	float					_speed;			//速度
};
