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
		SetFontSize(TITLE_FONT_SIZE);
		DrawFormatString(TITLE_POS_X + 5, TITLE_POS_Y + 5, GetColor(122, 122, 122), "SHOOTING GAME");
		DrawFormatString(TITLE_POS_X, TITLE_POS_Y, GetColor(255,255,255), "SHOOTING GAME");
		SetFontSize(KEY_FONT_SIZE);
		DrawFormatString(KEY_POS_X + 5, KEY_POS_Y + 5, GetColor(122, 122, 122), "PREES [SPASE]");
		DrawFormatString(KEY_POS_X, KEY_POS_Y, GetColor(255, 255, 255), "PREES [SPASE]");
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
