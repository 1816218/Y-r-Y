#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class ClearScene :
	public BaseScene
{
public:
	ClearScene();
	~ClearScene();

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
	int		_ghClearScreen;	//�`��Ώۂɂ�����̨������ق�ێ�����
	int		_CanimFrame;		//�A�j���[�V�����p
	int		_CalphaCount;		//�摜�̃u�����h�F�A���t�@�l		
};

