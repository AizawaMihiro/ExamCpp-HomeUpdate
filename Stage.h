#pragma once
#include "GameObject.h"
#include <vector>

//‘O•ûéŒ¾  ’†g‚ğ“Ç‚İ‚Ü‚È‚¢‚Ì‚Å—e—Ê‚ªŒy‚­‚È‚é
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

