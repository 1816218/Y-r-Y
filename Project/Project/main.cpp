#include <Windows.h>
#include "Scene/SceneMng.h"

//メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!lpSceneMng.SystemInit())
	{
		return -1;
	}
	lpSceneMng.Run();
	lpSceneMng.Terminate();

	return 0;
}
