#include "main.h"

//メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);//ウィンドウ
	SetWindowText(WINDOW_NAME);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1) return -1;//初期化と裏画面化
	SetDrawScreen(DX_SCREEN_BACK);
	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();
		ScreenFlip();
	}
	DxLib_End();//終了の処理
	return 0;//ソフトの処理

}
