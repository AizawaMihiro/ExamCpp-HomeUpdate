#include "Player.h"
#include "Bullet.h"
#include "Dxlib.h"
#include "Input.h"
#include "Effect.h"

namespace {
	const float PLAYER_INIT_SPEED = 200.0f;//初期速度 秒間の移動ピクセル数
	const int ENEMY_BASE_MARGIN = 32;

	const float PLAYER_INIT_X = (WIN_WIDTH / 2) - (PLAYER_IMAGE_WIDTH / 2);//初期位置
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - ENEMY_BASE_MARGIN;

	const int BULLET_IMAGE_MARGIN = PLAYER_IMAGE_WIDTH/2- BULLET_IMAGE_WIDTH/2;
	const float BULLET_INETERVAL = 0.5f;

	const int PLAYER_BULLET_NUM = 5;
}

Bullet* Player::GetActiveBullet()
{
	for (auto itr : bullets_) {
		if (!itr->IsFire()) {
			return itr;
		}
	}
	return nullptr;
}


Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0),imageSize_({PLAYER_IMAGE_WIDTH,PLAYER_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");
	if (hImage_ == -1) {

	}
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0;i < PLAYER_BULLET_NUM;i++) {
		bullets_.push_back(new Bullet());
	}
	AddGameObject(this);
}

Player::~Player()
{
	new Effect({ x_,y_ });
}

void Player::Update()
{
	float dt = GetDeltaTime();//フレーム間の時間差を取得
	float pastX = x_;
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)|| Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		x_ -= speed_ * dt;
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)|| Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		x_ += speed_ * dt;
	}
	if (x_ < 0|| x_ > WIN_WIDTH - PLAYER_IMAGE_WIDTH) {
		x_ = pastX;
	}

	static float bulletTimer = 0.0f;
	if (bulletTimer>0.0f)
	{
		bulletTimer -= dt;
	}
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f) {
			Shoot();
			bulletTimer = BULLET_INETERVAL;
		}
	}
}

void Player::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

//Bulletを発射する関数
void Player::Shoot()
{
	Bullet* bit = GetActiveBullet();
	if (bit != nullptr)
	{
		bit->SetPos(x_ + BULLET_IMAGE_MARGIN, y_);
		bit->SetFire(true);
	}
}
