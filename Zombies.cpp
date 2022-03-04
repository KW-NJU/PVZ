#include"Zombies.h"
#include<iostream>
using namespace std;
zombie::zombie(){
    x=y=type=attack=health=max_health=img_w=img_h=img_posX=img_posY=-1;
    buff=NULL;
}
zombie::zombie(int _x,int _y,int _type):x(_x),y(_y),type(_type),state(0),time_cnt(0){
    buff=new int[20];
    for(int i=0;i<20;i++)
        buff[i]=0;
    img_num=_type;
    switch(_type){
    case 0://zombie
        attack=25;health = max_health = 10;speed=4;img_w=75;img_h=120;img_posX=7;img_posY=22;break;//普通僵尸
    case 1://flagzombie
        attack=25;health = max_health = 10;speed=4;img_w=92;img_h=135;img_posX=24;img_posY=36;break;//旗帜僵尸
    case 2://coneheadzombie
        attack=25;health = max_health = 24;speed=4;img_w=75;img_h=146;img_posX=7;img_posY=47;break;//路障僵尸
    case 3://Vaultingzombie
        attack=25;health = max_health = 17;speed=6;img_w=155;img_h=120;img_posX=75;img_posY=23;break;//撑杆僵尸
    case 4://Bucketheadzombie
        attack=25;health = max_health = 55;speed=4;img_w=76;img_h=133;img_posX=9;img_posY=36;break;//铁桶僵尸
    case 5://Newspaperzombie
        attack=25;health = max_health = 18;speed=4;img_w=90;img_h=122;img_posX=23;img_posY=22;break;//读报僵尸
    case 6://Screendoorzombie
        attack=25;health = max_health = 55;speed=4;img_w=80;img_h=120;img_posX=12;img_posY=21;break;//铁栅门僵尸
    case 7://Dancingzombie
        attack=25;health = max_health = 17;speed=12;img_w=80;img_h=138;img_posX=12;img_posY=35;break;//舞王僵尸
    case 8://Backupdancerzombie
        attack=25;health = max_health = 10;speed=12;img_w=92;img_h=123;img_posX=25;img_posY=16;break;//伴舞僵尸
    case 9://Footballzombie
        attack=25;health = max_health = 80;speed=6;img_w=107;img_h=130;img_posX=22;img_posY=28;break;//橄榄球僵尸
    default:
        x=y=type=attack=health=max_health=img_w=img_h=img_posX=img_posY=speed=-1;break;
    }
}
/*buff[0]冰冻减速
 *buff[1]吃大蒜了
 *
*/
int zombie::getX(){
    return x;
}
int zombie::getY(){
    return y;
}
int zombie::get_imgW(){
    return img_w;
}
int zombie::get_imgH(){
    return img_h;
}
int zombie::get_imgPosX(){
    return img_posX;
}
int zombie::get_imgPosY(){
    return img_posY;
}
int zombie::getType(){
    return type;
}
int zombie::getAttack(){
    return attack;
}
int zombie::getHealth(){
    return health;
}
int zombie::get_img_num(){
    return img_num;
}
int zombie::getState(){
    return state;
}
void zombie::be_hurt(int dam){
    if(health>dam)
        health-=dam;
    else if(health>=0)
        health=0;
}
void zombie::move(){
    x-=speed;
}
void zombie::special_action(int func){
    switch(func){
    case 0://撑杆跳
        x-=90;
        state=1;
        break;
    case 1://撑杆没跳过
        state=1;break;
    default:break;
    }
}
void zombie::getbuff(int buff_type){
    switch(buff_type){
    case 0:buff[0]=200;break;
    case 1:buff[1]=20;break;
    default:break;
    }
}
void zombie::update(int func){
    switch(type){
    case 2:case 4:case 6://铁桶僵尸、路障僵尸、铁栅门僵尸在保护物被打碎之后变成普通僵尸。
        if(health<=10){
            max_health=10;
            type=0;
            img_num=0;
            img_w=75;img_h=120;img_posX=7;img_posY=22;
        }
        break;
    case 3://撑杆跳僵尸跳跃之后
        if(state&&img_num<=100){
            if(buff[0])
                img_num=150;
            else
                img_num=100;
            img_w=78;img_h=122;img_posX=7;img_posY=23;
            speed=4;
        }break;
    case 5://读报僵尸在报纸碎裂后暴怒
        if(health<=10){
            img_num=101;
            img_w=80;img_h=120;img_posX=14;img_posY=20;
            speed=9;state=1;attack=38;
        }
        break;
    case 7://舞王僵尸在跳舞和进攻之间切换
        if(func==0&&!state){
            state=1;
            time_cnt=0;
        }
        else if(func==1&&state==4){
            state=2;
            time_cnt=0;
        }
        else if(func==0&&(state==2||state==3)){
            state=4;
            time_cnt=0;
        }
        break;
    case 8://伴舞僵尸同舞王僵尸
        if(func==0&&state<2){
            state=2;
            time_cnt=0;
        }
        else if(func&&state==2){
            state=0;
            time_cnt=0;
        }
        break;
    case 9:
        if(!state&&health<=10){
            state=1;
            img_num=104;img_h=125;img_posX=25;img_posY=21;
        }
        break;
    default:break;
    }
if(buff[0]&&(img_num<50||(img_num>=100&&img_num<150)))
    img_num+=50;
else if(!buff[0]&&((img_num>=50&&img_num<100)||img_num>=150))
    img_num-=50;
}


int zombie::time_action(){//返回值为0：不做行动；返回值为1：进行移动或攻击;返回值为2：可以进行撑杆跳;返回值为3，可以召唤伴舞僵尸;返回值为4，召唤伴舞僵尸
    time_cnt++;
    if(buff[0]>0)buff[0]--;
    if(buff[1]>0)buff[1]--;
    if(!buff[1]){
    switch(type){
    case 0:case 1:case 2:case 4:case 5:case 6:case 9:
        if(time_cnt>=5*(1+(buff[0]>0))){//被冰冻则移速减半
            time_cnt=0;
            return 1;
        }break;
    case 3:
        if(time_cnt>=5*(1+(buff[0]>0))){//被冰冻则移速减半
            time_cnt=0;
            return 2;
        }break;
    case 7://舞王僵尸
        if(!state||state==3)
            img_num=7+50*(buff[0]>0);
        else
            img_num=102+50*(buff[0]>0);

        if(!state&&time_cnt>=5*(1+(buff[0]>0))){
            time_cnt=0;
            return 3;//可进行召唤
        }
        else if(state==1&&time_cnt>=10){
            state=2;
            time_cnt=29;
            return 4;//召唤伴舞僵尸
        }
        else if(state==2||state==3){
            if(time_cnt>=60*(1+(buff[0]>0)))
            time_cnt=0;
            if(time_cnt%(5+5*(buff[0]>0))==0){
                if(time_cnt<20)
                    return 5;//移动或进攻
                else if(time_cnt%(10+10*(buff[0]>0))==0){
                    state=5-state;
                    return 6;//跳舞或进攻，不可移动
                }
            }
        }
        else if(state==4&&time_cnt>=5*(1+(buff[0]>0))){
            time_cnt=0;
            return 5;//移动或进攻
        }

        break;
    case 8:
        if(state==1)
            img_num=103+50*(buff[0]>0);
        else
            img_num=8+50*(buff[0]>0);
        if(state==0||state==1){
                    if(time_cnt>=60*(1+(buff[0]>0)))
                    time_cnt=0;
                    if(time_cnt%(5+5*(buff[0]>0))==0){
                        if(time_cnt<20)
                            return 5;//移动或进攻
                        else if(time_cnt%(10+10*(buff[0]>0))==0){
                            state=1-state;
                            return 6;//跳舞或进攻，不可移动
                        }
                    }
                }
        else if(state==2)
               return 5;
        break;
    default:break;
    }
    }
    else if(buff[1]==1){
        x-=5;
        if(y==0)y=1;
        else if(y==4)y=3;
        else y=y+1-2*(rand()%2);
    }
    return 0;
}


