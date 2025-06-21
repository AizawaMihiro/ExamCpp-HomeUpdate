#pragma once
#include "GameObject.h"
#include "globals.h"
class EnemyBeam :
    public GameObject
{
    int hImage_;
    Point pos_;
    float speed_;
    Point imageSize_;
    //int isize_x, isize_y;//表示サイズ
    bool isFire_;//発射されたかどうか　
public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
    void SetPos(const Point& pos) { pos_ = pos; }
    void SetFire(bool fired) { isFire_ = fired; }
    bool IsFire() { return isFire_; }
    Rect GetRect() const { return { pos_.x,pos_.y,BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT }; }
};

