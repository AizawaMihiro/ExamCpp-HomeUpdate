#include "GameScene.h"
#include "Dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBeam.h"

namespace {
	const int ENEMY_COL_SIZE = 10;
	const int ENEMY_ROW_SIZE = 7;
	const int ENEMY_NUM = ENEMY_COL_SIZE * ENEMY_ROW_SIZE;
	const float ENEMY_ALINE_X = 55.0f;
	const float ENEMY_ALINE_Y = 50.0f;
	const int ENEMY_LEFT_MARGIN = (WIN_WIDTH - (ENEMY_ALINE_X * ENEMY_COL_SIZE)) / 2;
	const int ENEMY_TOP_MARGIN = 90;

	bool IntersectRect(const Rect& a, const Rect& b) {
		if (abs(a.GetCenter().x - b.GetCenter().x) < a.w / 2 + b.w / 2 && abs(a.GetCenter().y - b.GetCenter().y) < a.h / 2 + b.h / 2) {
			return true;
		}
		return false;
	}
}

GameScene::GameScene()
{
	player_ = new Player();
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++) {
		int x = i % ENEMY_COL_SIZE;
		int y = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,HIGH,MID,LOW,LOW,LOW,LOW };
		enemy_[i] = new Enemy(i, enemyType[y]);//列ごとに敵のタイプを変更
		enemy_[i]->SetMaxMoveX(ENEMY_LEFT_MARGIN);
		enemy_[i]->SetPos(ENEMY_LEFT_MARGIN + (float)x * ENEMY_ALINE_X, ENEMY_TOP_MARGIN + (float)y * ENEMY_ALINE_Y);
		enemy_[i]->SetXorigin(x * ENEMY_ALINE_X + ENEMY_LEFT_MARGIN);
	}
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	std::vector<EnemyBeam*> beams;
	for (auto& e : enemy_)
	{
		beams = e->GetAllBeams();
	}
	for (auto& e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFire() && e->IsAlive())
			{
				if (IntersectRect(e->GetRect(), b->GetRect())) {
					b->SetFire(false);
					e->SetAlive(false);
					//new Effect(e->GetPos());
				}
			}
		}
	}
	for (auto& b : beams)
	{
		if (b->IsFire() && player_->IsAlive())
		{
			if (IntersectRect(player_->GetRect(), b->GetRect())) {
				b->SetFire(false);
				player_->SetAlive(false);
				//new Effect(e->GetPos());
			}
		}
	}
}

void GameScene::Draw()
{

}

bool GameScene::GetGame()
{
	return nowGame;
}

void GameScene::SetGame(bool nowState)
{
	nowGame = nowState;
}
