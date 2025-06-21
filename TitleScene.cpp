#include "TitleScene.h"
#include "Dxlib.h"

TitleScene::TitleScene()
	:GameObject()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{

}

void TitleScene::Draw()
{
	
}

bool TitleScene::GetTitle()
{
	return nowTitle;
}

void TitleScene::SetTitle(bool nowState)
{
	nowTitle = nowState;
}
