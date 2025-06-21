#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"

namespace {
	const int BG_COLOR[3] = { 0,0,0};
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects;
std::vector<GameObject*> newObjects;

float gDeltaTime = 0.0f;

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BG_COLOR[0],BG_COLOR[1],BG_COLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib::DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	/*DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);*/
	//中央縦線（テスト用）
	//DrawLine(WIN_WIDTH / 2, 0, WIN_WIDTH/2, WIN_HEIGHT, GetColor(0, 0, 0), 1);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();
		crrTime = GetNowCount();
		float deltaTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = deltaTime;


		//ここにやりたい処理を書く

		if (newObjects.size() > 0) {
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);
			}
			newObjects.clear();
		}
		

		for (auto& obj:gameObjects) {
			obj->Update();
		}
		for (auto& obj : gameObjects) {
			obj->Draw();
		}
		for (auto it = gameObjects.begin(); it != gameObjects.end();) {
			if (!(*it)->IsAlive())
			{
				delete* it;
				it = gameObjects.erase(it);
			}
			else {
				it++;
			}
		}
		

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime;

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib::DxLib_End();
	return 0;
}