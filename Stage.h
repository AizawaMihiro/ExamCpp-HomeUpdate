#pragma once
#include "GameObject.h"
#include <vector>

//�O���錾  ���g��ǂݍ��܂Ȃ��̂ŗe�ʂ��y���Ȃ�
class Player;
class Enemy;


class Stage :
    public GameObject
{
    Player* player_;
    std::vector<Enemy*> enemy_;
    int hBackGround_;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

