#include <DxLib.h>
#include "InputKey.h"

InputKey* InputKey::s_Instance = nullptr;

InputKey::InputKey()
{
	Init();
}

InputKey::~InputKey()
{
}

void InputKey::Init(void)
{
	//�ŏ��͉����Ă��Ȃ���Ԃɂ���
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = false;
		oldKey[i] = false;
		trgKey[i] = false;
		upKey[i] = false;
	}
}
//-----�L�[���̍X�V
bool InputKey::UpDate(void)
{
	//�����Ă��Ȃ����
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = false;
		trgKey[i] = false;
		upKey[i] = false;
	}

	if (CheckHitKey(KEY_INPUT_UP)) newKey[KEY_UP] = true;
	if (CheckHitKey(KEY_INPUT_RIGHT)) newKey[KEY_RIGHT] = true;
	if (CheckHitKey(KEY_INPUT_LEFT)) newKey[KEY_LEFT] = true;
	if (CheckHitKey(KEY_INPUT_DOWN)) newKey[KEY_DOWN] = true;
	if (CheckHitKey(KEY_INPUT_SPACE)) newKey[KEY_SPACE] = true;

	//�g���K�ƃA�b�v
	for (int i = 0; i < KEY_MAX; i++) {
		trgKey[i] = newKey[i] & ~oldKey[i];//�g���K
		upKey[i] = ~newKey[i] & oldKey[i];//�A�b�v

		//���̃L�[����ێ�����
		oldKey[i] = newKey[i];
	}
	return true;
}
