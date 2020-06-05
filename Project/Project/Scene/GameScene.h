#pragma once
#include <vector>
#include "BaseScene.h"

class Obj;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	//���e�̍X�V
	void Update(void) override;

	//�V�[��ID���擾
	SCN_ID GetSceneID(void) override;
private:
	//����������
	bool Init(void);
	//�`�揈��
	void Draw(void);

	int					_ghGameScreen;	//�`��Ώ��ɂ������̨������ق�ێ�
	Obj*				_player;		//�v���C���[
	std::vector<Obj*>	_objects;		//�G
};

