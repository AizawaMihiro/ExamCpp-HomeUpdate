#pragma once
#include "GameObject.h"
#include "globals.h"
class Bullet;

class Player :
    public GameObject
{
    int hImage_;//�摜�̃n���h��
    float x_, y_;//�v���C���[�̍��W
    float speed_;//�v���C���[�̈ړ����x
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
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }//�S�Ă�Bullet�̏����擾
};

