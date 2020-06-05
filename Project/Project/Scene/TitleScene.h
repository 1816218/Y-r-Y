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

	//���e�̍X�V
	unique_Base Update(unique_Base own) override;
	//�V�[�������擾����
	SCN_ID GetSceneID(void) override;
private:
	//����������
	bool Init(void);
	//�`�揈��
	void Draw(void);

	Vector2F _pos;			//�摜�̍��W
	float	_bright;		//��ʂ̖��邳
	int		_ghTitleScreen;	//�`��Ώۂɂ�����̨������ق�ێ�����
};

