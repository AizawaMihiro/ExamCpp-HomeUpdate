#pragma once
#include "GameObject.h"
#include <vector>


class Stage :
    public GameObject
{
    int hBackGround_;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

