#include"GameState.h"
#include<iostream>
#include<vector>
using namespace std;
gamestate::gamestate(int GameMode){
    shoplist=new plant*[7];
    switch(GameMode){
    case 0:
        shoplist[0]=new plant(-1,-1,1);
        shoplist[1]=new plant(-1,-1,0);
        shoplist[2]=new plant(-1,-1,2);
        shoplist[3]=new plant(-1,-1,3);
        shoplist[4]=new plant(-1,-1,4);
        shoplist[5]=new plant(-1,-1,5);
        shoplist[6]=new plant(-1,-1,9);
        sunshine=100;
        break;
    case 1:
        shoplist[0]=new plant(-1,-1,0);
        shoplist[1]=new plant(-1,-1,5);
        shoplist[2]=new plant(-1,-1,7);
        shoplist[3]=new plant(-1,-1,3);
        shoplist[4]=new plant(-1,-1,8);
        shoplist[5]=new plant(-1,-1,6);
        shoplist[6]=new plant(-1,-1,2);
        sunshine=3000;
        break;
    case 2:
        shoplist[0]=new plant(-1,-1,1);
        shoplist[1]=new plant(-1,-1,0);
        shoplist[2]=new plant(-1,-1,6);
        shoplist[3]=new plant(-1,-1,3);
        shoplist[4]=new plant(-1,-1,9);
        shoplist[5]=new plant(-1,-1,4);
        shoplist[6]=new plant(-1,-1,2);
        sunshine=100;
        break;
    case 3:
        shoplist[0]=new plant(-1,-1,1);
        shoplist[1]=new plant(-1,-1,0);
        shoplist[2]=new plant(-1,-1,2);
        shoplist[3]=new plant(-1,-1,8);
        shoplist[4]=new plant(-1,-1,4);
        shoplist[5]=new plant(-1,-1,5);
        shoplist[6]=new plant(-1,-1,7);
        sunshine=100;
        break;
    }
}
const vector<plant> gamestate::get_lawn_plants(){
    return plants_on_lawn;
}
const vector<zombie> gamestate::get_lawn_zombies(){
    return zombies_on_lawn;
}
const vector<bullet> gamestate::get_lawn_bullets(){
    return bullets_on_lawn;
}
const vector<Sunshine> gamestate::get_lawn_sunshine(){
    return sunshine_on_lawn;
}
plant** gamestate::getShopList(){
    return shoplist;
}
int gamestate::getSunShine(){
    return sunshine;
}
void gamestate::add_plant(int _x,int _y,int _type){
    plants_on_lawn.push_back(plant(_x,_y,_type));
    for(int i=0;i<7;i++)
        if(shoplist[i]->getType()==_type)
            shoplist[i]->resetCD();
}
void gamestate::add_zombie(int _x, int _y, int _type){
    zombies_on_lawn.push_back(zombie(_x,_y,_type));
}
void gamestate::add_bullet(int _x, int _y, int _type){
    bullets_on_lawn.push_back(bullet(_x,_y,_type));
}
bool gamestate::pos_empty(int _x,int _y){
    for(unsigned i=0;i<plants_on_lawn.size();i++)
        if(_x==plants_on_lawn[i].getX()&&_y==plants_on_lawn[i].getY())
            return false;
    return true;
}
void gamestate::add_sunshine(int in){
    sunshine+=in;
}
void gamestate::add_sunshine_on_lawn(int _x, int _y,int _target_y,int _val){
    sunshine_on_lawn.push_back(Sunshine(29+80*_x+rand()%10,63+100*_y+rand()%10,_target_y,_val));
}
bool gamestate::shoplist_state(int in){
    return shoplist[in]->getCD_state();
}
void gamestate::remove_plant(int _x, int _y){
    vector<plant>::iterator it;
    for(it=plants_on_lawn.begin();it!=plants_on_lawn.end();it++)
        if(it->getX()==_x&&it->getY()==_y){
            plants_on_lawn.erase(it);
            break;
        }
}
int gamestate::find_zombie(int _x, int _y, int func){
    int res=-1;
    int temp_pos=0;
    switch(func){
    case  0://寻找某位置左侧最近的僵尸
        temp_pos=-1;
        for(unsigned i=0;i<zombies_on_lawn.size();i++)
            if(zombies_on_lawn[i].getY()==_y&&zombies_on_lawn[i].getX()>=temp_pos&&zombies_on_lawn[i].getX()<=_x+10){
                res=i;
                temp_pos=zombies_on_lawn[i].getX();
            }break;
    case 1://寻找某位置右侧最近的僵尸
        temp_pos=1000;
        for(unsigned i=0;i<zombies_on_lawn.size();i++)
            if(zombies_on_lawn[i].getY()==_y&&zombies_on_lawn[i].getX()<=temp_pos&&zombies_on_lawn[i].getX()>_x-10){
                res=i;
                temp_pos=zombies_on_lawn[i].getX();
            }break;
    case 2://寻找窝瓜（xy坐标为格子坐标）能发现的最靠左的僵尸
        temp_pos=1000;
        for(unsigned i=0;i<zombies_on_lawn.size();i++)
            if(zombies_on_lawn[i].getY()==_y&&zombies_on_lawn[i].getX()<=temp_pos&&zombies_on_lawn[i].getX()>=_x*80-46&&zombies_on_lawn[i].getX()<=_x*80+194){
                res=i;
                temp_pos=zombies_on_lawn[i].getX();
            }break;
    default:break;
    }
    return res;
}
int gamestate::find_plant(int _x, int _y, int func){
    int res=-1;
    int temp_pos=9;
    switch(func){
    case 0://大多数僵尸的搜索算法：寻找攻击范围内最靠左的植物
        for(unsigned i=0;i<plants_on_lawn.size();i++){
            if(plants_on_lawn[i].getState()>=0&&plants_on_lawn[i].getY()==_y&&plants_on_lawn[i].getX()<temp_pos&&plants_on_lawn[i].getX()*80+34<=_x&&plants_on_lawn[i].getX()*80+114>=_x){
                res=i;
                temp_pos=plants_on_lawn[i].getX();
            }
        }break;
    default:break;
    }
    return res;
}
bool gamestate::sort_zombie(zombie &a, zombie &b){
    if(a.getY()<b.getY())
        return true;
    else if(a.getX()>b.getX())
        return true;
    return false;

}
void gamestate::damage_zombie_area(int line, int leftX, int rightX, int dam){
    for(unsigned i=0;i<zombies_on_lawn.size();i++){
        if(zombies_on_lawn[i].getY()==line&&zombies_on_lawn[i].getX()>=leftX&&zombies_on_lawn[i].getX()<=rightX)
            zombies_on_lawn[i].be_hurt(dam);
    }
}
void gamestate::bullet_time_action(){
    for(unsigned i=0;i<bullets_on_lawn.size();i++){
        bool move=1;
        int first_zombie=find_zombie(bullets_on_lawn[i].getX(),bullets_on_lawn[i].getY(),1);
        if(first_zombie>=0){
            int _x=zombies_on_lawn[first_zombie].getX();
            if((_x+75>=bullets_on_lawn[i].getX()&&_x<=bullets_on_lawn[i].getX()+bullets_on_lawn[i].getSpeed())||(_x<=bullets_on_lawn[i].getX()&&_x+75>=bullets_on_lawn[i].getX()+bullets_on_lawn[i].getSpeed())){
                move=0;
                bullets_on_lawn[i].destroy();
                zombies_on_lawn[first_zombie].be_hurt(bullets_on_lawn[i].getAttack());
                switch(bullets_on_lawn[i].getType()){//不同子弹的特殊效果
                case 1://冰豌豆减速
                    if(zombies_on_lawn[first_zombie].getType()!=6&&(zombies_on_lawn[first_zombie].getType()!=5||zombies_on_lawn[first_zombie].getState()))
                    zombies_on_lawn[first_zombie].getbuff(0);
                    break;
                default:break;
                }
            }
        }
        if(move)
            bullets_on_lawn[i].move();
    }
}
void gamestate::plants_time_action(int _x,int _y,int func){
    int target_zombie=-1;
   switch(func){
   case 0://peashooter
       if(find_zombie(34+_x*80,_y,1)>=0){//豌豆射手，射击豌豆子弹（所有普通豌豆子弹都调用这个）
           add_bullet(_x*80+100,_y,0);
       }
   break;
   case 1://sunflower
       add_sunshine_on_lawn(_x,_y,73+100*_y,25);break;//向日葵，生产阳光
   case 2://cherrybomb
       damage_zombie_area(_y-1,_x*80-56,_x*80+194,90);//樱桃炸弹，摧毁3x3的僵尸
       damage_zombie_area(_y,_x*80-56,_x*80+194,90);
       damage_zombie_area(_y+1,_x*80-56,_x*80+194,90);
       break;
   case 4://potatomine
       target_zombie=find_zombie(34+_x*80,_y,1);//土豆地雷，种下后过一段时间可以爆炸
       if(target_zombie>=0&&zombies_on_lawn[target_zombie].getX()<=_x*80+120){
           damage_zombie_area(_y,_x*80+34,_x*80+154,90);
           for(unsigned i=0;i<plants_on_lawn.size();i++)
               if(plants_on_lawn[i].getType()==4&&plants_on_lawn[i].getX()==_x&&plants_on_lawn[i].getY()==_y){
                   plants_on_lawn[i].update(0);
                   break;
               }
       }
       break;
   case 5://snowpea
       if(find_zombie(34+_x*80,_y,1)>=0){//寒冰射手，射击寒冰子弹
           add_bullet(_x*80+100,_y,1);
       }
       break;
   case 6://chomper
       target_zombie=find_zombie(34+_x*80,_y,1);//大嘴花，吃僵尸
       if(target_zombie>=0&&zombies_on_lawn[target_zombie].getX()<=_x*80+200){
           zombies_on_lawn[target_zombie].be_hurt(90);
           for(unsigned i=0;i<plants_on_lawn.size();i++)
               if(plants_on_lawn[i].getType()==6&&plants_on_lawn[i].getX()==_x&&plants_on_lawn[i].getY()==_y){
                   plants_on_lawn[i].update(0);
                   break;
               }
       }
   break;
   default:break;
   }
}
void gamestate::zombies_time_action(){
    int _x,_y;
    for(vector<zombie>::iterator i=zombies_on_lawn.begin();i!=zombies_on_lawn.end();i++){
        int nearest_plant=-1;
        nearest_plant=find_plant(i->getX(),i->getY(),0);
            switch(i->time_action()){
            case 1://正常僵尸面前有植物的话选择啃咬攻击
                if(nearest_plant>=0){
                    plants_on_lawn[nearest_plant].be_hurt(i->getAttack());
                    if(plants_on_lawn[nearest_plant].getType()==9)
                        i->getbuff(1);
                }
                else
                    i->move();
                break;
            case 2://撑杆僵尸如果有杆子则跳过植物，否则啃咬;如果遇到高坚果则无法跳过
                if(i->getState()){
                    if(nearest_plant>=0){
                        plants_on_lawn[nearest_plant].be_hurt(i->getAttack());
                        if(plants_on_lawn[nearest_plant].getType()==9)
                            i->getbuff(1);
                    }
                    else
                        i->move();
                }
                    else if(nearest_plant>=0&&plants_on_lawn[nearest_plant].getType()!=8)
                    i->special_action(0);
                else if(nearest_plant>=0&&plants_on_lawn[nearest_plant].getType()==8)
                    i->special_action(1);
                else
                    i->move();
                break;
            case 3:
                if(nearest_plant>=0)
                    i->update(0);
                else
                    i->move();
                break;
            case 4:
                _x=i->getX();
                _y=i->getY();
                temp_zombie.push_back(zombie(_x-80,_y,8));
                temp_zombie.push_back(zombie(_x+80,_y,8));
                if(i->getY())temp_zombie.push_back(zombie(_x,_y-1,8));
                if(i->getY()<4)temp_zombie.push_back(zombie(_x,_y+1,8));
                break;
            case 5:
                if(nearest_plant>=0){
                    i->update(0);
                    plants_on_lawn[nearest_plant].be_hurt(i->getAttack());
                    if(plants_on_lawn[nearest_plant].getType()==9)
                        i->getbuff(1);
                }
                else{
                    i->move();
                    i->update(1);
                }
                break;
            case 6:
                if(nearest_plant>=0){
                    i->update(0);
                    plants_on_lawn[nearest_plant].be_hurt(i->getAttack());
                    if(plants_on_lawn[nearest_plant].getType()==9)
                        i->getbuff(1);
                }
                else
                    i->update(1);
            default:break;
            }
            i->update(-1);
            if(i->getX()<=30)
                alive=0;
    }
    while(temp_zombie.begin()!=temp_zombie.end()){
        zombies_on_lawn.push_back(*temp_zombie.begin());
        temp_zombie.erase(temp_zombie.begin());
    }
}
void gamestate::time_action(){
    clear_objs();
    vector<Sunshine>::iterator it1;
    for(it1=sunshine_on_lawn.begin();it1!=sunshine_on_lawn.end();it1++)
        it1->time_action();
    for(int i=0;i<7;i++)
        shoplist[i]->time_CD_action();
    bullet_time_action();
    for(unsigned i=0;i<plants_on_lawn.size();i++)
        plants_time_action(plants_on_lawn[i].getX(),plants_on_lawn[i].getY(),plants_on_lawn[i].time_action());
    zombies_time_action();
    sort(zombies_on_lawn.begin(),zombies_on_lawn.end(),sort_zombie);
}
void gamestate::clear_objs(){
    vector<Sunshine>::iterator it1=sunshine_on_lawn.begin();
    for(;it1!=sunshine_on_lawn.end();){
        if(!it1->exist()){
            if(it1->add_value())
                add_sunshine(it1->getVal());
            sunshine_on_lawn.erase(it1);
            continue;
        }
        else
            it1++;
    }
    vector<zombie>::iterator it2=zombies_on_lawn.begin();
    for(;it2!=zombies_on_lawn.end();){
        if(!it2->getHealth()){
            zombies_on_lawn.erase(it2);
            continue;
        }
        else
            it2++;
    }
    vector<bullet>::iterator it3=bullets_on_lawn.begin();
    for(;it3!=bullets_on_lawn.end();){
        if(!it3->getExist()){
            bullets_on_lawn.erase(it3);
            continue;
        }
        else
            it3++;
    }
    vector<plant>::iterator it4=plants_on_lawn.begin();
    for(;it4!=plants_on_lawn.end();){
        if(!it4->getHealth()){
            plants_on_lawn.erase(it4);
            continue;
        }
        else
            it4++;
    }
}
void gamestate::click_sunshine(int num){
    if((unsigned)num<sunshine_on_lawn.size())
        sunshine_on_lawn[num].clicked();
}
int gamestate::is_alive(){
    return alive;
}
