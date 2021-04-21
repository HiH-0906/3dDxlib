#include <DxLib.h>


namespace {
	constexpr int screenSizeX = 640;
	constexpr int screenSizeY = 480;
	int posx = 100;
	int posy = 200;
	int posz = 0;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrvInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	SetGraphMode(screenSizeX, screenSizeY, 32);
	ChangeWindowMode(true);
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	SetWindowText("‚Ä‚·‚Æ‚¾‚æ");

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetLightDirection(VGet(0, 0, -1.0f));
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();
		int speed = 5;
		if (CheckHitKey(KEY_INPUT_W))
		{
			posz+=speed;
		}
		if (CheckHitKey(KEY_INPUT_S))
		{
			posz-= speed;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			posx+= speed;
		}
		if (CheckHitKey(KEY_INPUT_A))
		{
			posx-= speed;
		}
		if (CheckHitKey(KEY_INPUT_Q))
		{
			posy+= speed;
		}
		if (CheckHitKey(KEY_INPUT_E))
		{
			posy-= speed;
		}
		auto vec1 = VGet(static_cast<float>(posx), static_cast<float>(posy), static_cast<float>(posz));
		auto vec2 = VGet(static_cast<float>(posx), static_cast<float>(posy) - 100.0f, static_cast<float>(posz));
		DrawCapsule3D(vec1, vec2, 50.0f, 8, 0xffffff, 0xffffff, false);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}