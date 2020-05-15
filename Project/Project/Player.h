#pragma once
#include "MODEL_BASE.h"

class Player :public MODEL_BASE
{
private:
	enum MOV_DIR {						//•ûŠp‚ÌŽí—Þ
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_UP,
		DIR_MAX
	};
	

public:
	Player();
	~Player();
	void Init();
	void Update();
	void Draw();
	
	
};

