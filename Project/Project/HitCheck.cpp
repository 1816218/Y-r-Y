#include "HitCheck.h"


bool HitCheck::IsHitAABB(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh)
{
	if (
		(ax <= bx + bw)  //・・・①
		&& (ax + aw >= bx)  //・・・② 
		&& (bx <= by + bh)  //・・・③ 
		&& (bx + ah >= by)  //・・・④
		)
	{
		return true;
	}
	return false;
}