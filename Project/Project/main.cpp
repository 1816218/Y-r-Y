#include <DxLib.h>
#include "Scene/SceneMng.h"

#include"Player.h"
//メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	ChangeWindowMode(TRUE);//ウィンドウ
	SetWindowText(WINDOW_NAME);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1) return -1;//初期化と裏画面化
	SetDrawScreen(DX_SCREEN_BACK);
	//Player player;
	Player* player;
	player = new Player();

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{

		ClsDrawScreen();
		
		if (player != nullptr) { player->Draw(); }
		ScreenFlip();
	}

	lpSceneMng.Run();
//>>>>>>> c4441f4c38d706ba02ed91a2b40cedefd83f3423

	DxLib_End();//終了の処理
	return 0;//ソフトの処理
}
