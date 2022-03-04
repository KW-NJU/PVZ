#ifndef OTHEROBJECTS_H
#define OTHEROBJECTS_H
#include<iostream>
#include<math.h>
using namespace std;
class Sunshine{
private:
    int x,y,target_y;
    int val;
    int state;//0代表正在下落，1代表以下落到指定地点，2代表已被点击
    int time_cnt;
public:
    Sunshine(int _x,int _y,int _target_y,int _val);
    void clicked();
    void time_action();
    int getX();
    int getY();
    bool cursor_on(int _x,int _y);
    bool exist();
    bool add_value();
    int getVal();
};

class bullet{
    int x,y;
    int attack;
    int speed;
    int type;
    int imgW,imgH;
    int img_centerX,img_centerY;//子弹中心相对图片左上角坐标
    bool exist;
public:
    bullet();
    bullet(int _x,int _y,int _type);
    int getX();
    int getY();
    int get_imgW();
    int get_imgH();
    int get_imgCenterX();
    int get_imgCenterY();
    int getType();
    int getAttack();
    int getSpeed();
    void move();
    void destroy();
    bool getExist();
};

#endif // OTHEROBJECTS_H
