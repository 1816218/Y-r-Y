#pragma once
#include <DxLib.h>
#include <string>
#include "VECTOR2.h"

enum class CHARA_DIR
{
	UP		= 3,
	RIGHT	= 2,
	LEFT	= 1,
	DOWN	= 0,
	MAX
};


class Obj
{
public:
	Obj();
	~Obj();

	bool Init(void);

	virtual void Update(void) = 0;

	//�`��
	virtual void Draw(void) = 0;

	void DrawRotaF(int GHandle, int TransFlag);

	//�I�u�W�F�N�g����������
	bool DeathPro(void);

	//�����m�F
	bool isAlive(void) { return _alive; }

	//���S�m�F
	bool isDeath(void) { return _death; }

	virtual const Vector2F& GetPos(void);
	virtual void SetPos(const Vector2F& pos);

	virtual const Vector2F& GetSize(void);
	virtual void SetSize(const Vector2F& size);

	virtual const double GetAngle(void);
	virtual void SetAngle(const double angle);

	virtual const double GetExRate(void);
	virtual void SetExRate(const double exRate);
protected:
	Vector2F _pos;	//float�^
	Vector2F _size;	//flaot�^
	double _angle;	//�p�x
	double _exRate;	//�g�嗦
	bool _alive;	//true:�����Ă���Afalse:�����Ă��Ȃ�
	bool _death;	//true:����ł���Afalse:����ł��Ȃ�
};

