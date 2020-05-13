#pragma once
#include "MODEL_BASE.h"
class Enemy :public MODEL_BASE
{
private:
public:
	Enemy();
	~Enemy();
	void Init();
	void Update();
	void Draw();

};

