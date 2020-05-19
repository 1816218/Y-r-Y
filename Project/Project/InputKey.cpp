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


	//Xbox360�L�[���́iXBox360�A�A�i���O�X�e�B�b�N�j
	GetJoypadXInputState(DX_INPUT_PAD1, &xBox360input);//pad1�����o�i����ĂԂ��Ƃœr���ł̔��������ɂ��Ή��j
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_UP])newKey[_1P_UP] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_RIGHT])newKey[_1P_RIGHT] = 1;//�f�W�^�������{�^���E
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_DOWN])newKey[_1P_DOWN] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_LEFT])newKey[_1P_LEFT] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_START])newKey[_1P_START] = 1;//START�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_BACK])newKey[_1P_SELECT] = 1;//BACK�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_THUMB])newKey[_1P_xTHUMB_L] = 1;//���X�e�B�b�N��������
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_THUMB])newKey[_1P_xTHUMB_R] = 1;//�E�X�e�B�b�N
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_SHOULDER])newKey[_1P_LB] = 1;//LB�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_SHOULDER])newKey[_1P_RB] = 1;//RB�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_A])newKey[_1P_A] = 1;//A�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_B])newKey[_1P_B] = 1;//B�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_X])newKey[_1P_X] = 1;//X�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_Y])newKey[_1P_Y] = 1;//Y�{�^��
	newKey[_1P_xLEFT_TRIGGER] = (int)xBox360input.LeftTrigger;//���g���K�[�i0�`255�j
	newKey[_1P_xRIGHT_TRIGGER] = (int)xBox360input.RightTrigger;//�E�g���K�[�i0�`255�j
	newKey[_1P_xThumbLX] = (int)xBox360input.ThumbLX;//���X�e�B�b�N�̉����l�i-32768�`32767�j
	newKey[_1P_xThumbLY] = (int)xBox360input.ThumbLY;//���X�e�B�b�N�̉����l�i-32768�`32767�j
	newKey[_1P_xThumbRX] = (int)xBox360input.ThumbRX;//�E�X�e�B�b�N�̉����l�i-32768�`32767�j
	newKey[_1P_xThumbRY] = (int)xBox360input.ThumbRY;//�E�X�e�B�b�N�̉����l�i-32768�`32767�j

	//���܂��ŃQ�[���p�b�h����
	//�Q�[���p�b�h�̓��̓`�F�b�N�i�f�W�^���j
	int padInput1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);//PAD1�����o
	if (padInput1&PAD_INPUT_UP)newKey[_1P_UP] = 1;
	if (padInput1&PAD_INPUT_RIGHT)newKey[_1P_RIGHT] = 1;
	if (padInput1&PAD_INPUT_DOWN)newKey[_1P_DOWN] = 1;
	if (padInput1&PAD_INPUT_LEFT)newKey[_1P_LEFT] = 1;

	if (padInput1&PAD_INPUT_1)newKey[_1P_A] = 1;
	if (padInput1&PAD_INPUT_2)newKey[_1P_B] = 1;
	if (padInput1&PAD_INPUT_3)newKey[_1P_X] = 1;
	if (padInput1&PAD_INPUT_4)newKey[_1P_Y] = 1;
	if (padInput1&PAD_INPUT_5)newKey[_1P_LB] = 1;
	if (padInput1&PAD_INPUT_6)newKey[_1P_RB] = 1;
	if (padInput1&PAD_INPUT_7)newKey[_1P_SELECT] = 1;
	if (padInput1&PAD_INPUT_8)newKey[_1P_START] = 1;

	//�g���K�ƃA�b�v
	for (int i = 0; i < KEY_MAX; i++) {
		trgKey[i] = newKey[i] & ~oldKey[i];//�g���K
		upKey[i] = ~newKey[i] & oldKey[i];//�A�b�v

		//���̃L�[����ێ�����
		oldKey[i] = newKey[i];
	}
	return true;
}
