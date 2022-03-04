#ifndef ZOMBIES_H
#define ZOMBIES_H
#include<QString>
class zombie{
private:
    int x,y;
    int type;
    int health,max_health;
    int attack;
    int speed;
    int state;
    int time_cnt;
    int* buff;
    int img_w,img_h;
    int img_posX,img_posY;//绘制图片的基准位置，值为僵尸右眼相对图片左上角的坐标
    int img_num;
public:
    zombie();
    zombie(int _x,int _y,int _type);
    int getX();
    int getY();
    int get_imgW();
    int get_imgH();
    int get_imgPosX();
    int get_imgPosY();
    int getType();
    int getAttack();
    int getHealth();
    int get_img_num();
    int getState();
    void be_hurt(int dam);
    void move();
    void special_action(int func);
    void update(int func);
    void getbuff(int buff_type);
    int time_action();//参考列表详见Zombies.cpp
};

#endif // ZOMBIES_H
