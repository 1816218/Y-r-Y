#pragma once
#include "Map.h"

class HitCheck
{
public:
	bool operator()(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);
};

