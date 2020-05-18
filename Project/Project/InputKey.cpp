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

	//トリガとアップ
	for (int i = 0; i < KEY_MAX; i++) {
		trgKey[i] = newKey[i] & ~oldKey[i];//トリガ
		upKey[i] = ~newKey[i] & oldKey[i];//アップ

		//今のキー情報を保持する
		oldKey[i] = newKey[i];
	}
	return true;
}
