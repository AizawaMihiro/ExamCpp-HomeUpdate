#include "OverScene.h"
#include "Dxlib.h"
#include "Input.h"

OverScene::OverScene()
	:GameObject(),nowOver(false)
{
	AddGameObject(this);
}

OverScene::~OverScene()
{
}

void OverScene::Update()
{
	if (nowOver)
	{
		if (Input::IsKeyDown(KEY_INPUT_SPACE))
		{
			nowOver = false;
		}
	}
	
}

void OverScene::Draw()
{
	if (nowOver)
	{
		SetFontSize(64);
		DrawFormatString(OVER_POS_X + 5, OVER_POS_Y + 5, GetColor(122, 122, 122), "GAMEOVER");
		DrawFormatString(OVER_POS_X, OVER_POS_Y, GetColor(255, 255, 255), "GAMEOVER");
		SetFontSize(KEY_FONT_SIZE);
		DrawFormatString(KEY_POS_X + 5, KEY_POS_Y + 5, GetColor(122, 122, 122), "PREES [SPASE]");
		DrawFormatString(KEY_POS_X, KEY_POS_Y, GetColor(255, 255, 255), "PREES [SPASE]");
	}
}

bool OverScene::GetOver()
{
	return nowOver;
}

void OverScene::SetOver(bool nowState)
{
	nowOver = nowState;
}
