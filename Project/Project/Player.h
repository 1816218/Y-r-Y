#pragma once
#include "MODEL_BASE.h"

class Player :public MODEL_BASE
{
private:
	

public:
	Player();
	~Player();
	void Init(void);
	void Update(void);
	void Draw(void);
	
	Vector2& GetPos(void);
};

