#include "HitCheck.h"


bool HitCheck::IsHitAABB(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh)
{
	if (
		(ax <= bx + bw)  //�E�E�E�@
		&& (ax + aw >= bx)  //�E�E�E�A 
		&& (bx <= by + bh)  //�E�E�E�B 
		&& (bx + ah >= by)  //�E�E�E�C
		)
	{
		return true;
	}
	return false;
}