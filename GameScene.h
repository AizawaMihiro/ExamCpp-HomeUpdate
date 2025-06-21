#pragma once
#include "GameObject.h"
#include "globals.h"

//‘O•ûéŒ¾  ’†g‚ğ“Ç‚İ‚Ü‚È‚¢‚Ì‚Å—e—Ê‚ªŒy‚­‚È‚é
class Player;
class Enemy;

class GameScene :
	public GameObject
{
public:
	GameScene();
	~GameScene();
	void Update();
	void Draw();
	bool GetGame();
	void SetGame(bool nowState);
private:
	bool nowGame;
	Player* player_;
	std::vector<Enemy*> enemy_;
};

