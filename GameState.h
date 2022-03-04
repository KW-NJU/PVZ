#ifndef GAMESTATE_H
#define GAMESTATE_H
#include<iostream>
#include<vector>
#include"Plants.h"
#include"Zombies.h"
#include"OtherObjects.h"
using namespace std;
class gamestate{
private:
    vector<plant>plants_on_lawn;
    vector<zombie>zombies_on_lawn;
    vector<zombie>temp_zombie;
    vector<bullet>bullets_on_lawn;
    vector<Sunshine>sunshine_on_lawn;
    plant** shoplist;
    int sunshine;
    int alive=-1;
public:
    gamestate(int GameMode);
    const vector<plant> get_lawn_plants();
    const vector<zombie> get_lawn_zombies();
    const vector<bullet> get_lawn_bullets();
    const vector<Sunshine> get_lawn_sunshine();
    plant** getShopList();
    int getSunShine();
    bool pos_empty(int _x,int _y);
    void add_sunshine(int in);
    void add_plant(int _x,int _y,int _type);
    void add_zombie(int _x,int _y,int _type);
    void add_bullet(int _x,int _y,int _type);
    void add_sunshine_on_lawn(int _x,int _y,int _target_y,int _val);
    bool shoplist_state(int in);//判断商店能否够买
    void remove_plant(int _x,int _y);
    int find_zombie(int _x,int _y,int func);
    int find_plant(int _x,int _y,int func);
    static bool sort_zombie(zombie& a,zombie& b);//按照坐标来排序，显示时便于遍历
    void damage_zombie_area(int line,int leftX,int rightX,int dam);//范围伤害僵尸
    void bullet_time_action();
    void plants_time_action(int _x,int _y,int func);
    void zombies_time_action();
    void time_action();
    void clear_objs();
    void click_sunshine(int num);
    int is_alive();
};

#endif // GAMESTATE_H
