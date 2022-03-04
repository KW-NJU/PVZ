#ifndef PLANTS_H
#define PLANTS_H
#include<iostream>
using namespace std;
class plant{
private:
    int x,y;
    int type;
    int health,max_health;
    int CD,max_CD;
    int attack;
    int price;
    int img_num;
    int imgW,imgH;
    int state;
    int time_cnt;
public:
    plant();
    plant(int _x,int _y,int _type);
    int getX();
    int getY();
    int get_imgW();
    int get_imgH();
    int get_img_num();
    int getType();
    int getPrice();
    int getAttck();
    int getHealth();
    int getState();
    void resetCD();
    void clearCD();
    double getCD_state();
    void time_CD_action();
    void be_hurt(int dam);
    void update(int func);
    int time_action();//参考列表详见Plants.cpp
};

#endif // PLANTS_H
