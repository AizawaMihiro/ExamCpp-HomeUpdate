#include "DxLib.h"
#include "Stage.h"
#include "globals.h"
//#include "Effect.h"


Stage::Stage()
	:GameObject(),hBackGround_(-1)
{
	AddGameObject(this);
	hBackGround_ = LoadGraph("Assets\\bg.png");
	if (hBackGround_ == -1) {

	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawExtendGraphF(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackGround_, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}
