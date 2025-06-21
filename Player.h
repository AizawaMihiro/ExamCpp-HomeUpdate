#pragma once
#include "GameObject.h"
#include "globals.h"
class Bullet;

class Player :
    public GameObject
{
    int hImage_;//画像のハンドル
    float x_, y_;//プレイヤーの座標
    float speed_;//プレイヤーの移動速度
    Point imageSize_;
    std::vector<Bullet*> bullets_;
    Bullet* GetActiveBullet();
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot();
    Rect GetRect() const { return { x_,y_,imageSize_.x,imageSize_.y }; }
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }//全てのBulletの情報を取得
};

