#include"Plants.h"
#include<iostream>
using namespace std;
plant::plant(int _x,int _y,int _type):x(_x),y(_y),type(_type),img_num(_type){
    state=time_cnt=0;
    switch(type){
    case 0://peashooter
        attack=1;max_CD=150;CD=0;health = max_health = 300;price=100;imgW=imgH=70;break;// 豌豆射手
    case 1://sunflower
        attack=0;max_CD=150;CD=0;health = max_health = 300;price=50;imgW=imgH=70;break;//向日葵
    case 2://cherrybomb
        attack=90;max_CD=1000;CD=0;health = max_health = -1;price=150;imgW=imgH=85;break;//樱桃炸弹
    case 3://wallnut
        attack=0;max_CD=600;CD=0;health = max_health = 4000;price=50;imgW=imgH=85;break;//坚果墙
    case 4://potatomine
        attack=90;max_CD=500;CD=0;health = max_health = 300;price=25;imgW=imgH=70;img_num=50;break;//土豆地雷
    case 5://snowpea
        attack=1;max_CD=150;CD=0;health = max_health = 300;price=175;imgW=imgH=70;break;//寒冰射手
    case 6://chomper
        attack=90;max_CD=150;CD=0;health = max_health = 300;price=150;imgW=imgH=100;break;//大嘴花
    case 7://repeater
        attack=1;max_CD=150;CD=0;health = max_health = 300;price=200;imgW=imgH=70;break;//双发射手
    case 8://tallnut
        attack=0;max_CD=600;CD=0;health = max_health = 8000;price=125;imgW=99;imgH=146;break;//高坚果
    case 9://garlic
        attack=1;max_CD=150;CD=0;health = max_health = 500;price=50;imgW=61;imgH=100;break;//大蒜
    default:
        x=y=type=attack=max_CD=CD=health=max_health=price=imgW=imgH=-1;break;
    }
}
plant::plant(){
    x=y=type=attack=max_CD=CD=health=max_health=price=-1;
}
int plant::getX(){
    return x;
}
int plant::getY(){
    return y;
}
int plant::get_imgH(){
    return imgH;
}
int plant::get_imgW(){
    return imgW;
}
int plant::get_img_num(){
    return img_num;
}
int plant::getType(){
    return type;
}
int plant::getPrice(){
    return price;
}
int plant::getAttck(){
    return attack;
}
int plant::getHealth(){
    return health;
}
int plant::getState(){
    return state;
}
void plant::resetCD(){
    CD=max_CD;
}
void plant::clearCD(){
    CD=0;
}
double plant::getCD_state(){
    return (double)CD/max_CD;
}
void plant::time_CD_action(){
    if(CD>0)
        CD--;
}
void plant::be_hurt(int dam){
    if(health>dam)
        health-=dam;
    else if(health>=0)
        health=0;
}
void plant::update(int func){
    switch(type){
    case 4:
        state=-1;
        img_num=51;imgW=132;imgH=93;
        break;
    case 6:
        img_num=54;
        state=1;
        break;
    default:break;
    }
}
int plant::time_action(){
    time_cnt++;
    switch(type){
    case 0://豌豆射手，每隔1.5s射击一颗豌豆子弹
        if(time_cnt==30){
            time_cnt=0;
            return 0;
        }
        break;
    case 1://向日葵，第一次7.5s产出阳光，之后每24s产出阳光。
        if(!state&&time_cnt==150){
            time_cnt=0;
            state=1;
            return 1;
        }
        else if(state&&time_cnt==480){
            time_cnt=0;
            return 1;
        }
        break;
    case 2://土豆地雷
        if(!state&&time_cnt==20){
            state=-1;
            time_cnt=0;
            img_num=55;imgW=136;imgH=123;
            return 2;
        }
        else if(state<0&&time_cnt==20){
            health=0;
        }
        break;
    case 3:if(health<=2667&&img_num==3)//坚果墙
            img_num=52;
        else if(img_num==52&&health<=1333)
            img_num=53;
        break;
    case 4:if(!state&&time_cnt==280){//樱桃炸弹
            state=1;
            time_cnt=0;
            img_num=4;
            health=-1;
        }
        else if(state==1){
            time_cnt--;
            return 4;
        }
        else if(state<0&&time_cnt>=20){
            health=0;
        }
        break;
    case 5://寒冰射手，每隔1.5s射击一颗寒冰子弹
        if(time_cnt==30){
            time_cnt=0;
            return 5;
        }
        break;
    case 6://大嘴花，吃僵尸,咀嚼42s
        if(state&&time_cnt==840){
            state=0;
            time_cnt=0;
            img_num=6;
        }
        else if(!state){
            time_cnt--;
            return 6;
        }
        break;
    case 7://双发，每隔1.5s射击两颗豌豆子弹
        if((!state&&time_cnt==25)||(state&&time_cnt==5)){
            time_cnt=0;
            state=1-state;
            return 0;
        }
        break;
    case 8:if(health<=5333&&img_num==8)//高坚果
            img_num=56;
        else if(img_num==56&&health<=2666)
            img_num=57;
        break;
    case 9:
        if(health<=334&&img_num==9)//大蒜
                    img_num=58;
                else if(img_num==58&&health<=167)
                    img_num=59;
                break;
    default:break;
    }
    return -1;
}
/*植物state参考列表
 * type[0]peashooter豌豆射手:state无关
 * type[1]sunflower向日葵：state=0,尚未产阳光；state=1，已经产出至少一次阳光。
 */

