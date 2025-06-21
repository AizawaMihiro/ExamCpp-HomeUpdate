#pragma once
#include "GameObject.h"
#include "globals.h"


class Bullet :
    public GameObject
{
    int hImage_;
    float x_, y_;
    float speed_;
    Point imageSize_;
    //int isize_x, isize_y;//表示サイズ
    bool isFire_;//発射されたかどうか　
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
    void SetFire(bool fired) { isFire_ = fired; }
    bool IsFire() { return isFire_; }
    Rect GetRect() const { return { x_,y_,BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT }; }
};

