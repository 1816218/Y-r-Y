#pragma once
#include "BaseScene.h"
#include "../VECTOR2.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

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
	int		_ghTitleScreen;	//�`��Ώۂɂ�����̨������ق�ێ�����
	int		_animFrame;		//�A�j���[�V�����p
	int		_alphaCount;		//�摜�̃u�����h�F�A���t�@�l		
};

