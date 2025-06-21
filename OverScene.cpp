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
