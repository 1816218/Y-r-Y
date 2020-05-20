#include "HitCheck.h"


bool HitCheck::IsHitAABB(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh)
{
	if (
		(ax <= bx + bw)  //・・・�@
		&& (ax + aw >= bx)  //・・・�A 
		&& (bx <= by + bh)  //・・・�B 
		&& (bx + ah >= by)  //・・・�C
		)
	{
		return true;
	}
	return false;
}