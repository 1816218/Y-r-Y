#pragma once

enum KEY_CODE
{
	KEY_UP,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_DOWN,

	KEY_SPACE,
//XBox360入力キー
	_1P_A,
	_1P_B,
	_1P_X,
	_1P_Y,
	_1P_LB,
	_1P_RB,
	_1P_SELECT,
	_1P_START,
	_1P_xTHUMB_L,
	_1P_xTHUMB_R,
	_1P_xLEFT_TRIGGER,
	_1P_xRIGHT_TRIGGER,
	_1P_xThumbLX,
	_1P_xThumbLY,
	_1P_xThumbRX,
	_1P_xThumbRY,
	KEY_MAX
};

#define lpInputKey InputKey::GetInstance()

class InputKey
{
public:
	static InputKey& GetInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new InputKey();
		}
		return *s_Instance;
	}
	~InputKey();

	void Init(void);
	bool Update(void);

	int newKey[KEY_MAX];
	int oldKey[KEY_MAX];
	int trgKey[KEY_MAX];
	int upKey[KEY_MAX];
private:
	InputKey();

	static InputKey* s_Instance;
};

