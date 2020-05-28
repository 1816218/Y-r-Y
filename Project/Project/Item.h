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

	//�`��
	void Draw(void) override;


	//-----Get�ESet
	//���W
	const Vector2F& GetPos(void);
	void SetPos(const Vector2F& pos);
	//�T�C�Y
	const Vector2F& GetSize(void);
	void SetSize(const Vector2F& size);
	//�p�x
	const double GetAngle(void);
	void SetAngle(const double angle);
	//�g�嗦
	const double GetExRate(void);
	void SetExRate(const double exRate);
private:
	bool _moveFlag;			//true:�ړ��Afalse:��~
	CHARA_DIR _direction;	//����
	int _animCnt;			//�A�j���[�V�����J�E���g
};

