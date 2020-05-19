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
	//最初は押していない状態にする
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = false;
		oldKey[i] = false;
		trgKey[i] = false;
		upKey[i] = false;
	}
}
//-----キー情報の更新
bool InputKey::UpDate(void)
{
	//押していない状態
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


	//Xbox360キー入力（XBox360、アナログスティック）
	GetJoypadXInputState(DX_INPUT_PAD1, &xBox360input);//pad1を検出（毎回呼ぶことで途中での抜き差しにも対応）
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_UP])newKey[_1P_UP] = 1;//デジタル方向ボタン上
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_RIGHT])newKey[_1P_RIGHT] = 1;//デジタル方向ボタン右
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_DOWN])newKey[_1P_DOWN] = 1;//デジタル方向ボタン下
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_LEFT])newKey[_1P_LEFT] = 1;//デジタル方向ボタン左
	if (xBox360input.Buttons[XINPUT_BUTTON_START])newKey[_1P_START] = 1;//STARTボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_BACK])newKey[_1P_SELECT] = 1;//BACKボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_THUMB])newKey[_1P_xTHUMB_L] = 1;//左スティック押し込み
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_THUMB])newKey[_1P_xTHUMB_R] = 1;//右スティック
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_SHOULDER])newKey[_1P_LB] = 1;//LBボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_SHOULDER])newKey[_1P_RB] = 1;//RBボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_A])newKey[_1P_A] = 1;//Aボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_B])newKey[_1P_B] = 1;//Bボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_X])newKey[_1P_X] = 1;//Xボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_Y])newKey[_1P_Y] = 1;//Yボタン
	newKey[_1P_xLEFT_TRIGGER] = (int)xBox360input.LeftTrigger;//左トリガー（0～255）
	newKey[_1P_xRIGHT_TRIGGER] = (int)xBox360input.RightTrigger;//右トリガー（0～255）
	newKey[_1P_xThumbLX] = (int)xBox360input.ThumbLX;//左スティックの横軸値（-32768～32767）
	newKey[_1P_xThumbLY] = (int)xBox360input.ThumbLY;//左スティックの横軸値（-32768～32767）
	newKey[_1P_xThumbRX] = (int)xBox360input.ThumbRX;//右スティックの横軸値（-32768～32767）
	newKey[_1P_xThumbRY] = (int)xBox360input.ThumbRY;//右スティックの横軸値（-32768～32767）

	//おまけでゲームパッド入力
	//ゲームパッドの入力チェック（デジタル）
	int padInput1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);//PAD1を検出
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

	//トリガとアップ
	for (int i = 0; i < KEY_MAX; i++) {
		trgKey[i] = newKey[i] & ~oldKey[i];//トリガ
		upKey[i] = ~newKey[i] & oldKey[i];//アップ

		//今のキー情報を保持する
		oldKey[i] = newKey[i];
	}
	return true;
}
