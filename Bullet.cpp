#include "Bullet.h"
#include "DxLib.h"
#include <string>

namespace {
	const float BULLET_INIT_SPEED = 200.0f;
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue01.png";
}

Bullet::Bullet()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isFire_(false), imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());
	speed_ = BULLET_INIT_SPEED;
	isAlive_ = true;
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1), x_(x), y_(y), speed_(0), isFire_(false), imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());
	speed_ = BULLET_INIT_SPEED;
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt;
	if (y_ < 0) {
		isFire_ = false;//‰æ–ÊŠO‚Éo‚½‚çÁ‹Ž
	}
}

void Bullet::Draw()
{
	if (isFire_) {
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hImage_, TRUE);
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
