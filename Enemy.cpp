#include "Enemy.h"
#include "Dxlib.h"
#include "Input.h"
#include "string"
#include "Effect.h"

namespace {
	const float ENEMY_INIT_SPEED = 100.0f;//初期速度 秒間の移動ピクセル数
	const int ENEMY_BASE_MARGIN = 32;

	//const float ENEMY_INIT_X = (WIN_WIDTH / 2) - (ENEMY_IMAGE_WIDTH / 2);//初期位置
	//const float ENEMY_INIT_Y = ENEMY_IMAGE_HEIGHT - ENEMY_BASE_MARGIN;
	const float ENEMY_INIT_X = 100;//初期位置
	const float ENEMY_INIT_Y = 100;
	const float BEAM_INETERVAL = 20.0f;
}

Enemy::Enemy()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), ID_(0), type_(LOW),
	imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }), moveTime_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	//idとtypeを指定されなかった時の処理（略）
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),ID_(id),type_(type),
	imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }), moveTime_(0)
{
	/*switch (type)
	{
	case LOW:
		hImage_ = LoadGraph("Assets\\tiny_ship10.png");
		break;
	case MID:
		hImage_ = LoadGraph("Assets\\tiny_ship16.png");
		break;
	case HIGH:
		hImage_ = LoadGraph("Assets\\tiny_ship18.png");
		break;
	case BOSS:
		hImage_ = LoadGraph("Assets\\tiny_ship9.png");
		break;
	default:
		break;
	}*/
	std::string imagePath[MAX_TYPE] = {
		"Assets\\tiny_ship10.png",
		"Assets\\tiny_ship16.png",
		"Assets\\tiny_ship18.png",
		"Assets\\tiny_ship9.png"
	};
	moveTime_ = 0.0f;
	hImage_ = LoadGraph(imagePath[type_].c_str());
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	isAlive_ = true;
	AddGameObject(this);
}

Enemy::~Enemy()
{
	new Effect({x_,y_});
	if (hImage_ == -1) {
		DeleteGraph(hImage_);
	}
}

void Enemy::Update()
{
	static float beamTimer = BEAM_INETERVAL;
	float period = 10.0f;
	float omega = 2.0f * 3.14159265f / period;
	moveTime_ += GetDeltaTime();
	x_ = xorigin_ + xMoveMax_ / 2.0 * sinf(omega * moveTime_);

	if (beamTimer <0)
	{
		EnemyBeam* beam = new EnemyBeam(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_WIDTH);
		Beams_.push_back(beam);
		beamTimer = BEAM_INETERVAL;
	}
	beamTimer -= GetDeltaTime();
}

void Enemy::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
