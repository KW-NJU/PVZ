#include"OtherObjects.h"
#include<iostream>
using namespace std;
Sunshine::Sunshine(int _x,int _y,int _target_y,int _val):x(_x),y(_y),target_y(_target_y),val(_val),state(0),time_cnt(-1){}
void Sunshine::time_action(){
    int _x=-10,_y=-25;
    switch(state){
    case 0:
        if(y<target_y)y+=5;
        else state=1;
        break;
    case 1:
        if(time_cnt<200)time_cnt+=1;
        break;
    case 2:
        if(sqrt((double)pow(x-_x,2)+pow(y-_y,2))<=100){
            x=_x;
            y=_y;
            state=3;
        }
         else{
            x-=75*cos((double)atan((double)(_y-y)/(_x-x)));
            y-=75*sin((double)atan((double)(_y-y)/(_x-x)));
        }
        break;
    default:break;
    }
}
void Sunshine::clicked(){
    this->state=2;
    time_cnt=-1;
}
bool Sunshine::exist(){
      return state<3&&time_cnt<200;
}
bool Sunshine::add_value(){
    return state==3;
}
bool Sunshine::cursor_on(int _x, int _y){
    return state<2&&_x>=x&&_x<=x+117&&_y>=y&&_y<=y+116;
}
int Sunshine::getX(){
    return x;
}
int Sunshine::getY(){
    return y;
}
int Sunshine::getVal(){
    return val;
}
bullet::bullet(){
    x=y=attack=speed=type=img_centerX=img_centerY=-1;
    exist=0;
}
bullet::bullet(int _x,int _y,int _type):x(_x),y(_y),type(_type),exist(1){
    switch(type){
    case 0://pea
        attack=1;speed=12;imgW=imgH=28;img_centerX=img_centerY=14;break;//豌豆子弹
    case 1://snowpea
        attack=1;speed=12;imgW=imgH=28;img_centerX=img_centerY=14;break; //寒冰豌豆
    default:exist=0;break;
    }
}
int bullet::getX(){
    return x;
}
int bullet::getY(){
    return y;
}
int bullet::get_imgH(){
    return imgH;
}
int bullet::get_imgW(){
    return imgW;
}
int bullet::get_imgCenterX(){
    return img_centerX;
}
int bullet::get_imgCenterY(){
    return img_centerY;
}
int bullet::getType(){
    return type;
}
int bullet::getSpeed(){
    return speed;
}
bool bullet::getExist(){
    return exist;
}
int bullet::getAttack(){
    return attack;
}
void bullet::destroy(){
    exist=0;
}
void bullet::move(){
    x+=speed;
}
