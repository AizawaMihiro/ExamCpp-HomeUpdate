#pragma once
#include "GameObject.h"
#include "globals.h"

//�O���錾  ���g��ǂݍ��܂Ȃ��̂ŗe�ʂ��y���Ȃ�
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

