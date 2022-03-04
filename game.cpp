#include "game.h"
#include "ui_game.h"
#include"Images_des.h"
#include<string>
#include<QString>
#include<QMouseEvent>

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    cursor_state=-1;
    GameMode=0;
    timestate=new QTimer();
    timestate->setInterval(50);
    connect(timestate,SIGNAL(timeout()),this,SLOT(time_action()));
    timestate->stop();
    time_cnt=0;

    lawn_img.load(lawn_img_des);
    SeedBank_img.load(seed_bank_img_des);
    ShovelBank_img.load(ShovelBank_img_des);
    Shovel_img.load(Shovel_img_des);
    Sunshine_img.load(Sunshine_img_des);
    PauseBotton_img.load(PauseBotton_img_des);
    for(int i=0;i<100;i++)
        plants_img[i].load(plants_img_des[i]);
    for(int i=0;i<200;i++)
        zombies_img[i].load(zombies_img_des[i]);
    for(int i=0;i<10;i++)
        bullet_img[i].load(bullet_img_des[i]);


    connect(ui->pause_botton,SIGNAL(clicked()),this,SIGNAL(ShowPauseWindow()));

    this->move(0,0);

    bgm=new QSound("./bgm/GrassWalk.wav");
    bgm->setLoops(-1);
}

game::~game()
{
    delete ui;
}
void game::ChangeGameMode(int _mode){
    GameMode=_mode;
}
void game::reset(){
    cursor_state=-1;
    timestate->stop();
    time_cnt=0;
    delete temp_gamestate;
    temp_gamestate=NULL;
    this->hide();
    bgm->stop();
}
void game::restart(){
    reset();
    temp_gamestate=new gamestate(GameMode);
    timestate->start();
    this->show();
    bgm->play();
    Paused=0;
    showFullScreen();
    if(GameMode==3)
        timestate->setInterval(25);
    else
        timestate->setInterval(50);
}
void game::time_start()
{
    temp_gamestate=new gamestate(GameMode);
    timestate->start();
    Paused=0;
    showFullScreen();
    if(GameMode==3)
        timestate->setInterval(25);
    else
        timestate->setInterval(50);
}
void game::gamePause(){
    timestate->stop();
    Paused=1;
}
void game::gameContinue(){
    timestate->start();
    Paused=0;
}
void game::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.translate(0, 0);
    painter.drawPixmap(0, 0, 800, 600, lawn_img);//绘制草坪
    painter.drawPixmap(10, 0, 446, 87, SeedBank_img);//绘制植物商店框
    painter.drawPixmap(456, 0, 70, 72, ShovelBank_img);//绘制铲子框
    QFont temp_font1("微软雅黑",8);
    painter.setFont(temp_font1);
    plant** shoplist=temp_gamestate->getShopList();//绘制植物卡片部分
    for(int i=0;i<7;i++){
        painter.drawPixmap(112-shoplist[i]->get_imgW()*35/max(shoplist[i]->get_imgW(),shoplist[i]->get_imgH())/2+51*i, 22, shoplist[i]->get_imgW()*35/max(shoplist[i]->get_imgW(),shoplist[i]->get_imgH()), shoplist[i]->get_imgH()*35/max(shoplist[i]->get_imgW(),shoplist[i]->get_imgH()), plants_img[shoplist[i]->getType()]);//绘制卡片上的植物
        string temp=to_string(shoplist[i]->getPrice());
        QString price=QString::fromStdString(temp);
        if(temp_gamestate->getSunShine()<shoplist[i]->getPrice())
            painter.setPen(QColor(255,0,0,255));
        else
            painter.setPen(QColor(0,0,0,255));
        painter.drawText(118+51*i-temp.length()*6,73,price);//绘制植物价格，如果阳光不足则显示为红色
        if(shoplist[i]->getCD_state()>0){
            painter.setOpacity(0.5);
            painter.setBrush(QBrush(QColor(0,0,0)));
            painter.setPen(QColor(0,0,0,0));
            painter.drawRect(88+51*i,77-(int)(shoplist[i]->getCD_state()*69),49,(int)(shoplist[i]->getCD_state()*69));//正在冷却的植物绘制灰色CD阴影
            painter.setOpacity(1);
        }
        else if(temp_gamestate->getSunShine()<shoplist[i]->getPrice()){
            painter.setOpacity(0.3);
            painter.setBrush(QBrush(QColor(0,0,0)));
            painter.setPen(QColor(0,0,0,0));
            painter.drawRect(88+51*i,8,49,69);//阳光不足够买的植物绘制灰色阴影
            painter.setOpacity(1);
        }
    }
    if(cursor_state>=0&&cursor_state<10){//被选中的植物商店栏变成灰色
        painter.setOpacity(0.7);
        painter.setBrush(QBrush(QColor(0,0,0)));
        painter.drawRect(88+51*cursor_state,8,49,69);
        painter.setOpacity(1);
    }
    QFont temp_font2("微软雅黑",12);
    temp_font2.setBold(1);
    painter.setFont(temp_font2);
    string temp=to_string(temp_gamestate->getSunShine());
    QString sunshine=QString::fromStdString(temp);
    painter.setPen(QColor(0,0,0));
    painter.drawText(47-temp.length()*4.5,78,sunshine);//绘制阳光数量
    if(cursor_state!=10)
        painter.drawPixmap(451,5,Shovel_img);//绘制铲子图标

    vector<plant> lawn_plants=temp_gamestate->get_lawn_plants();//绘制草坪上的植物
    vector<bullet> lawn_bullets=temp_gamestate->get_lawn_bullets();//绘制植物子弹 
    vector<zombie> lawn_zombies=temp_gamestate->get_lawn_zombies();//绘制草坪上的僵尸
    for(int line=0;line<5;line++){
    for(unsigned i=0;i<lawn_plants.size();i++)
        if(lawn_plants[i].getY()==line)
            painter.drawPixmap(71+lawn_plants[i].getX()*80-lawn_plants[i].get_imgW()/2, 170+100*lawn_plants[i].getY()-lawn_plants[i].get_imgH(), lawn_plants[i].get_imgW(), lawn_plants[i].get_imgH(), plants_img[lawn_plants[i].get_img_num()]);
    for(unsigned i=0;i<lawn_zombies.size();i++)
        if(lawn_zombies[i].getY()==line)
        painter.drawPixmap(lawn_zombies[i].getX()-lawn_zombies[i].get_imgPosX(), 70+100*lawn_zombies[i].getY()-lawn_zombies[i].get_imgPosY(), lawn_zombies[i].get_imgW(), lawn_zombies[i].get_imgH(), zombies_img[lawn_zombies[i].get_img_num()]);
    for(unsigned i=0;i<lawn_bullets.size();i++)
        if(lawn_bullets[i].getY()==line)
        painter.drawPixmap(lawn_bullets[i].getX()-lawn_bullets[i].get_imgCenterX(), 115+100*lawn_bullets[i].getY()-lawn_bullets[i].get_imgCenterY(), lawn_bullets[i].get_imgW(), lawn_bullets[i].get_imgH(), bullet_img[lawn_bullets[i].getType()]);
    }

    vector<Sunshine> lawn_sunshine=temp_gamestate->get_lawn_sunshine();//绘制阳光
    for(unsigned i=0;i<lawn_sunshine.size();i++)
        painter.drawPixmap(lawn_sunshine[i].getX(),lawn_sunshine[i].getY(),117,116,Sunshine_img);


    if(cursor_state>=0){//绘制选中的植物或铲子的虚影
        painter.setOpacity(0.5);
        int _x=mapFromGlobal(QCursor().pos()).x();
        int _y=mapFromGlobal(QCursor().pos()).y();
        if(_x>=34&&_x<=756&&_y>=88&&_y<=568){
        _x=(_x-43)/80;
        _y=(_y>168)?(_y-68)/100:0;
        if(cursor_state==10)
            painter.drawPixmap(36+_x*80,100+_y*100,Shovel_img);
        else{
            plant** temp_shoplist=temp_gamestate->getShopList();
            painter.drawPixmap(71+_x*80-temp_shoplist[cursor_state]->get_imgW()/2,170+_y*100-temp_shoplist[cursor_state]->get_imgH(),temp_shoplist[cursor_state]->get_imgW(),temp_shoplist[cursor_state]->get_imgH(),plants_img[temp_shoplist[cursor_state]->getType()]);
        }
        }
        painter.setOpacity(1);        
    }
    painter.drawPixmap(600,0,120,46,PauseBotton_img);
}


void game::on_lawn_area_clicked()
{
    if(!Paused){
    int _x=mapFromGlobal(QCursor().pos()).x();
    int _y=mapFromGlobal(QCursor().pos()).y();
    bool click_sunshine=0;
    vector<Sunshine> temp_sunshine=temp_gamestate->get_lawn_sunshine();
    for(unsigned i=0;i<temp_sunshine.size();i++)
        if(temp_sunshine[i].cursor_on(_x,_y)){
            temp_gamestate->click_sunshine(i);
            click_sunshine=1;
        }
    if(!click_sunshine){
    _x=(_x-43)/80;
    _y=(_y>168)?(_y-68)/100:0;  
    if(cursor_state>=0&&cursor_state<10){
        if(temp_gamestate->pos_empty(_x,_y)){
            plant* temp_plant=temp_gamestate->getShopList()[cursor_state];
            temp_gamestate->add_plant(_x,_y,temp_plant->getType());
            temp_gamestate->add_sunshine(-temp_plant->getPrice());
            temp_plant->resetCD();
            cursor_state=-1;
        }
    }
    else if(cursor_state==10){
        if(temp_gamestate->pos_empty(_x,_y)==0)
            temp_gamestate->remove_plant(_x,_y);
        cursor_state=-1;
    }
    }
    }
}

void game::on_shop_list_area_clicked()
{
    if(!Paused){
    bool click_sunshine=0;
    int _x=mapFromGlobal(QCursor().pos()).x();
    int _y=mapFromGlobal(QCursor().pos()).y();
    vector<Sunshine> temp_sunshine=temp_gamestate->get_lawn_sunshine();
    for(unsigned i=0;i<temp_sunshine.size();i++)
        if(temp_sunshine[i].cursor_on(_x,_y)){
            temp_gamestate->click_sunshine(i);
            click_sunshine=1;
        }
    if(!click_sunshine){
    int choose_plant=(_x-88)/51;
    if((cursor_state<0||cursor_state==10)&&temp_gamestate->getSunShine()>=temp_gamestate->getShopList()[choose_plant]->getPrice()&&temp_gamestate->getShopList()[choose_plant]->getCD_state()==0){
        cursor_state=choose_plant;
    }
    else cursor_state=-1;
    }
    }
}

void game::on_shovel_area_clicked()
{
    if(!Paused){
    bool click_sunshine=0;
    int _x=mapFromGlobal(QCursor().pos()).x();
    int _y=mapFromGlobal(QCursor().pos()).y();
    vector<Sunshine> temp_sunshine=temp_gamestate->get_lawn_sunshine();
    for(unsigned i=0;i<temp_sunshine.size();i++)
        if(temp_sunshine[i].cursor_on(_x,_y)){
            temp_gamestate->click_sunshine(i);
            click_sunshine=1;
        }
    if(!click_sunshine){
    if(cursor_state==10)
        cursor_state=-1;
    else
        cursor_state=10;
    }
    }
}
void game::time_action(){
    time_cnt++;
    temp_gamestate->time_action();
    switch(GameMode){
    case 0:
    if(time_cnt==400||time_cnt==800||time_cnt==1200||time_cnt==1400||time_cnt==1600||time_cnt==1800)
        temp_gamestate->add_zombie(800,(time_cnt/200)%5,0);
    if(time_cnt==2100)
        temp_gamestate->add_zombie(800,1,1);
    if(time_cnt==2200||time_cnt==2400||time_cnt==2600)
        temp_gamestate->add_zombie(800,((time_cnt+200)/200)%5,2);
    if(time_cnt==3000||time_cnt==3200||time_cnt==3300)
        temp_gamestate->add_zombie(800,(time_cnt-3000)/100,3);
    if(time_cnt==3500||time_cnt==3700||time_cnt==3900)
        temp_gamestate->add_zombie(800,(time_cnt-3500)/100,4);
    if(time_cnt==4200||time_cnt==4300||time_cnt==4400||time_cnt==4500)
        temp_gamestate->add_zombie(800,(4500-time_cnt)/100,5);
    if(time_cnt==4700||time_cnt==4800)
        temp_gamestate->add_zombie(800,time_cnt>4700,6);
    if(time_cnt==5100||time_cnt==5200)
        temp_gamestate->add_zombie(800,1+2*(time_cnt>5100),7);
    if(time_cnt==5150||time_cnt==5250||time_cnt==5300)
        temp_gamestate->add_zombie(800,((5300-time_cnt)/50)%5,4);
    break;
    case 1:
    if(time_cnt<=3000){
    if(time_cnt==100)
        temp_gamestate->add_zombie(800,2,1);
    if(time_cnt%200==0)
        temp_gamestate->add_zombie(800,time_cnt%400?rand()%2:2+rand()%3,0);
    if(time_cnt%600==0)
        temp_gamestate->add_zombie(800,time_cnt%1200?rand()%2:2+rand()%3,2);
    if(time_cnt%800==0)
        temp_gamestate->add_zombie(1600,time_cnt%1600?rand()%2:2+rand()%3,3);
    if((time_cnt-200)%800==0&&time_cnt>800)
        temp_gamestate->add_zombie(800,(time_cnt-200)%1600?rand()%2:2+rand()%3,4);
    if((time_cnt-150)%600==0&&time_cnt>1500)
        temp_gamestate->add_zombie(800,(time_cnt-150)%1200?rand()%2:2+rand()%3,5);
    if(time_cnt==2000||time_cnt==2800||time_cnt==3000)
        temp_gamestate->add_zombie(800,((3600-time_cnt)/200)%5,6);
    if(time_cnt==2200||time_cnt==2400||time_cnt==2600)
        temp_gamestate->add_zombie(800,1+(2600-time_cnt)/200,7);
    if(time_cnt==2100||time_cnt==2300||time_cnt==2500||time_cnt==2700||time_cnt==2900)
        temp_gamestate->add_zombie(800,((2900-time_cnt)/200+3)%5,9);
        }
    break;
    case 2:
    if(time_cnt==400||time_cnt==800||time_cnt==1200||time_cnt==1400||time_cnt==1600||time_cnt==1800)
        temp_gamestate->add_zombie(800,(time_cnt/200)%5,2);
    if(time_cnt==2100)
        temp_gamestate->add_zombie(800,1,1);
    if(time_cnt==2200||time_cnt==2400||time_cnt==2600)
        temp_gamestate->add_zombie(800,((time_cnt+200)/200+1)%5,4);
    if(time_cnt==3000||time_cnt==3200||time_cnt==3300)
        temp_gamestate->add_zombie(800,(time_cnt-3000)/100,6);
    if(time_cnt>2100&&time_cnt<4450&&time_cnt%300==0)
        temp_gamestate->add_zombie(800,rand()%5,2*(rand()%2)+4);
    if(time_cnt==3500||time_cnt==3700||time_cnt==3900)
        temp_gamestate->add_zombie(800,(time_cnt-3500)/100,3);
    if(time_cnt==4200||time_cnt==4300||time_cnt==4400||time_cnt==4500||time_cnt==4600)
        temp_gamestate->add_zombie(800,(4600-time_cnt)/100,9);
    if(time_cnt==4350||time_cnt==4450)
        temp_gamestate->add_zombie(800,time_cnt>4400,7);
    break;
    case 3:
    if(time_cnt==400||time_cnt==800||time_cnt==1200||time_cnt==1400||time_cnt==1600||time_cnt==1800)
        temp_gamestate->add_zombie(800,time_cnt%800?rand()%2:2+rand()%3,0);
    if(time_cnt==2100)
        temp_gamestate->add_zombie(800,1,1);
    if(time_cnt==2200||time_cnt==2400||time_cnt==2600||time_cnt==2800)
        temp_gamestate->add_zombie(800,((time_cnt+200)/200)%5,2);
    if(time_cnt==2900||time_cnt==3100)
        temp_gamestate->add_zombie(800,(time_cnt-2900)/100,3);
    if(time_cnt==3300||time_cnt==3600||time_cnt==3900)
        temp_gamestate->add_zombie(800,time_cnt%600?rand()%2:2+rand()%3,4);
    if(time_cnt==4100||time_cnt==4250||time_cnt==4400||time_cnt==4550)
        temp_gamestate->add_zombie(800,(time_cnt+100)%300?rand()%2:2+rand()%3,5);
    if(time_cnt==4700||time_cnt==4800)
        temp_gamestate->add_zombie(800,time_cnt<4800,6);
    if(time_cnt==5100||time_cnt==5200)
        temp_gamestate->add_zombie(800,1+2*(time_cnt<5200),7);
    if(time_cnt==5150||time_cnt==5250||time_cnt==5300)
        temp_gamestate->add_zombie(800,((5300-time_cnt)/50)%5,9);
    break;
    default:break;
    }
    if(GameMode!=1&&(time_cnt-100)%200==0)//定时掉落阳光
        temp_gamestate->add_sunshine_on_lawn(rand()%6+1,-1,300+rand()%200,25);
    if(!temp_gamestate->is_alive()){
        gamePause();
        emit gameend(0);
    }
    else if((!GameMode&&time_cnt>5300)||(GameMode==1&&time_cnt>3000)||(GameMode==2&&time_cnt>4450)||(GameMode==3&&time_cnt>500)){
        vector<zombie> temp_zombies=temp_gamestate->get_lawn_zombies();
        if(temp_zombies.begin()==temp_zombies.end()){
        gamePause();
        emit gameend(1);
        }
    }
}

void game::fight_stage_upgrade(){
    if(GameMode>=fight_stage)
        fight_stage=GameMode+1;
    ofstream temp;
    temp.open("./save/fight_stage.dat",ios::out|ios::binary);
    temp<<fight_stage;
    temp.close();
}

void game::on_pause_botton_clicked()
{
    gamePause();
}

