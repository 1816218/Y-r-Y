#pragma once

enum KEY_CODE
{
	KEY_UP,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_DOWN,

	KEY_SPACE,

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
	bool UpDate(void);

	int newKey[KEY_MAX];
	int oldKey[KEY_MAX];
	int trgKey[KEY_MAX];
	int upKey[KEY_MAX];
private:
	InputKey();

	static InputKey* s_Instance;
};

