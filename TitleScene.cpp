#include "TitleScene.h"
#include "Dxlib.h"
#include "Input.h"

TitleScene::TitleScene()
	:GameObject(),nowTitle(false)
{
	AddGameObject(this);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (nowTitle)
	{
		if (Input::IsKeyDown(KEY_INPUT_SPACE))
		{
			nowTitle = false;
		}
	}
	
}

void TitleScene::Draw()
{
	if (nowTitle)
	{
		DrawFormatString(50, 100, GetColor(0, 0, 0), "SHOOTING GAME");
	}
}

bool TitleScene::GetTitle()
{
	return nowTitle;
}

void TitleScene::SetTitle(bool nowState)
{
	nowTitle = nowState;
}
