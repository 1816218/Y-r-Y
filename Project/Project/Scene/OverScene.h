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

	//���e�̍X�V
	void Update(void) override;
	//�V�[�������擾����
	SCN_ID GetSceneID(void) override;
private:
	//����������
	bool Init(void);
	//�`�揈��
	void Draw(void);

	Vector2F _pos;			//�摜�̍��W
	int		_bright;		//��ʂ̖��邳
	int		_ghOverScreen;	//�`��Ώۂɂ�����̨������ق�ێ�����
};

