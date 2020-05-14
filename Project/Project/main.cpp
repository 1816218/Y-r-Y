#include <DxLib.h>
#include "Scene/SceneMng.h"

//メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	lpSceneMng.Run();

	DxLib_End();//終了の処理
	return 0;//ソフトの処理
}
