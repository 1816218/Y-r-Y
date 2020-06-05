#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	//���e�̍X�V
	unique_Base Update(unique_Base own) override;

	//�V�[��ID���擾
	SCN_ID GetSceneID(void) override;
private:
	//����������
	bool Init(void);
	//�`�揈��
	void Draw(void);

	int _ghGameScreen;	//�`��Ώ��ɂ������̨������ق�ێ�

	Obj*				_player;	//�v���C���[
	std::vector<Obj*>	_objects;	//�G
};

