#include "EnemyBeam.h"
#include "DxLib.h"

namespace {
	const float BEAM_INIT_SPEED = 250.0f;
}

EnemyBeam::EnemyBeam()
	:GameObject(),hImage_(-1),pos_({-10,-10}),speed_(BEAM_INIT_SPEED),isFire_(true),
	imageSize_({ BEAM_IMAGE_WIDTH,BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets/EnemyBeam.png");
	AddGameObject(this);
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), x_(x), y_(y), pos_({ x,y }), speed_(BEAM_INIT_SPEED), isFire_(true),
	imageSize_({ BEAM_IMAGE_WIDTH,BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets/EnemyBeam.png");
	AddGameObject(this);
}

EnemyBeam::EnemyBeam(Point pos)
	:GameObject(), hImage_(-1), x_(pos.x), y_(pos.y), pos_(pos), speed_(BEAM_INIT_SPEED), isFire_(true),
	imageSize_({ BEAM_IMAGE_WIDTH,BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets/EnemyBeam.png");
	AddGameObject(this);
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;
}

void EnemyBeam::Update()
{
	float dt = GetDeltaTime();
	pos_.y =pos_.y + speed_ * dt;
	if (pos_.y > WIN_HEIGHT)
	{
		isFire_ = false;
		SetAlive(false);
	}
}

void EnemyBeam::Draw()
{
	if (isFire_) {
		DrawExtendGraphF(pos_.x, pos_.y, pos_.x + imageSize_.x, pos_.y + imageSize_.y, hImage_, TRUE);
	}
}
