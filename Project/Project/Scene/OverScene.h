#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class OverScene :
	public BaseScene
{
public:
	OverScene();
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

	float	_bright;		//��ʂ̖��邳
	int		_ghOverScreen;	//�`��Ώۂɂ�����̨������ق�ێ�����
	int		_OanimFrame;		//�A�j���[�V�����p
	int		_OalphaCount;		//�摜�̃u�����h�F�A���t�@�l		
};

