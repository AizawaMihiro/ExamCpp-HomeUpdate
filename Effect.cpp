#include "Effect.h"
#include "DxLib.h"

namespace {
	const float ANIME_TIME = 0.5f;
	const int EFFECT_IMAGE_SIZE = 48;
	const int EFFECT_ANIM = 9;
	const int EFFECT_DIV_WID = 3;
	const int EFFECT_DIV_HEI = 3;

	const float ANIME_FRAME_TIME = ANIME_TIME / (EFFECT_ANIM-1);
}

Effect::Effect(Point pos)
	:GameObject(), hImage_(std::vector<int>(EFFECT_ANIM, -1)), pos{pos.x, pos.y}
{
	LoadDivGraph("Assets\\explosion.png", EFFECT_ANIM, EFFECT_DIV_WID, EFFECT_DIV_HEI, EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data(), 0, 0, 0);
	if (hImage_[0] == -1) {

	}
	AddGameObject(this);
}

Effect::~Effect()
{
	for (int i = 0; i < EFFECT_ANIM; i++)
	{
		if (hImage_[i] == -1) {
			DeleteGraph(hImage_[i]);
		}
	}
	hImage_.clear();
	
}

void Effect::Update()
{
	float dt = GetDeltaTime();
	animeTimer_ += dt;
	frameTimer_ += dt;
	if (animeTimer_ > ANIME_TIME) {
		this->isAlive_ = false;
	}
	if (frameTimer_ >ANIME_FRAME_TIME)
	{
		nowFlame_++;
		if (nowFlame_> EFFECT_ANIM-1)
		{
			nowFlame_ -= EFFECT_ANIM-1;
		}
		frameTimer_ -= ANIME_FRAME_TIME;
	}
}

void Effect::Draw()
{
	DrawExtendGraphF(pos.x, pos.y, pos.x + EFFECT_IMAGE_SIZE, pos.y + EFFECT_IMAGE_SIZE, hImage_[nowFlame_], TRUE);
}
