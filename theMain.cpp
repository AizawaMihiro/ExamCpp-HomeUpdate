#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "OverScene.h"

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
	SetMainWindowText("ShootingGame");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BG_COLOR[0],BG_COLOR[1],BG_COLOR[2]);

	// ‚c‚wƒ‰ƒCƒuƒ‰ƒŠ‰Šú‰»ˆ—
	if (DxLib_Init() == -1)
	{
		DxLib::DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}




int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage stage;
	TitleScene* title = new TitleScene();
	GameScene* game = new GameScene();
	OverScene* over = new OverScene();
	State GameState = TITLE;

	switch (GameState)
	{
	case State::TITLE:
		title->SetTitle(true);
		break;
	case State::GAME:
		game->SetGame(true);
		break;
	case State::OVER:
		over->SetOver(true);
		break;
	case State::MUX_STATE:
	default:
		break;
	}

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();
		crrTime = GetNowCount();
		float deltaTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = deltaTime;


		//‚±‚±‚É‚â‚è‚½‚¢ˆ—‚ð‘‚­
		switch (GameState)
		{
		case State::TITLE:
			if (!title->GetTitle())
			{
				GameState = GAME;
				game->SetGame(true);
			}
			break;
		case State::GAME:
			if (!game->GetGame())
			{
				GameState = OVER;
				over->SetOver(true);
			}
			break;
		case State::OVER:
			if (!over->GetOver())
			{
				GameState = TITLE;
				title->SetTitle(true);
			}
			break;
		case State::MUX_STATE:
		default:
			break;
		}


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

		DrawLine(WIN_WIDTH / 2, 0, WIN_WIDTH / 2, WIN_HEIGHT, GetColor(255, 255, 255));
		

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