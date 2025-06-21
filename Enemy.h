#pragma once
#include "GameObject.h"
#include "globals.h"
#include "EnemyBeam.h"

enum ETYPE {
    LOW,MID,HIGH,BOSS,MAX_TYPE
};


class Enemy :
    public GameObject
{
    int hImage_;//画像のハンドル
    float x_, y_;//エネミーの座標
    float speed_;//エネミーの移動速度
    Point imageSize_;
    int ID_;    //エネミーのID
    ETYPE type_;
    float xorigin_;
    float xMoveMax_;
    float moveTime_;
    std::vector<EnemyBeam*> Beams_;
public:
    Enemy();
    Enemy(int id, ETYPE type);
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//座標を指定する
    Rect GetRect() const { return { x_,y_,imageSize_.x,imageSize_.y }; }
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    std::vector<EnemyBeam*> GetAllBeams() const { return Beams_; }//全てのBeamの情報を取得
    void AddBeam(EnemyBeam* beam) {
        newObjects.push_back(beam);
    }
};

