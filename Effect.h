#pragma once
#include "GameObject.h"
#include "globals.h"
#include "vector"
class Effect :
    public GameObject
{
    std::vector<int> hImage_;
    Point pos;//ç¿ïW
    float animeTimer_ =0;
    float frameTimer_ = 0;
    int nowFlame_ = 0;
public:
    Effect(Point pos);
    ~Effect();
    void Update() override;
    void Draw() override;
};

