#include "pvzproj.h"
#include "ui_pvzproj.h"
#include<windows.h>

PvZProj::PvZProj(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PvZProj)
{
    ui->setupUi(this);
    tempPauseWindow->hide();
    tempfightendwindow->hide();
    connect(timer, SIGNAL(timeout()), game1, SLOT(update()));
    timer->start(25);
    DEVMODE DevMode;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &DevMode);
    DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    DevMode.dmPelsWidth = 800;
    DevMode.dmPelsHeight = 600;
    ChangeDisplaySettings(&DevMode, CDS_FULLSCREEN);
    this->move(0,0);
    //showFullScreen();
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    connect(game1,SIGNAL(ShowPauseWindow()),tempPauseWindow,SLOT(show()));
    connect(game1,SIGNAL(gameend(int)),tempfightendwindow,SLOT(change_showmode(int)));
    connect(game1,SIGNAL(gameend(int)),tempfightendwindow,SLOT(show()));
    connect(tempPauseWindow,SIGNAL(game_continue()),game1,SLOT(gameContinue()));
    connect(tempPauseWindow,SIGNAL(gameRestart()),game1,SLOT(restart()));
    connect(tempPauseWindow,SIGNAL(return_to_menu()),game1,SLOT(reset()));
    connect(tempPauseWindow,SIGNAL(return_to_menu()),this,SLOT(show()));
    connect(tempPauseWindow,SIGNAL(return_to_menu()),tempfightendwindow,SLOT(hide()));
    connect(tempfightendwindow,SIGNAL(return_to_menu()),game1,SLOT(reset()));
    connect(tempfightendwindow,SIGNAL(return_to_menu()),this,SLOT(show()));
    connect(tempfightendwindow,SIGNAL(return_to_menu()),tempPauseWindow,SLOT(hide()));
    connect(tempfightendwindow,SIGNAL(fight_stage_upgrade()),game1,SLOT(fight_stage_upgrade()));


    main_menu_img.load(main_menu_img_des);
    quit_game_botton_img.load(quit_game_botton_img_des);
    fight_1_botton_img.load(fight_1_botton_img_des);
    fight_2_botton_img.load(fight_2_botton_img_des);
    fight_3_botton_img.load(fight_3_botton_img_des);
    fight_4_botton_img.load(fight_4_botton_img_des);
    fight_locked_botton_img.load(fight_locked_botton_img_des);

    ifstream temp;
    temp.open("./save/fight_stage.dat",ios::in|ios::binary);
    temp>>fight_stage;
    temp.close();
}

PvZProj::~PvZProj()
{
    delete ui;
}

void PvZProj::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.translate(0, 0);
    painter.drawPixmap(192, 55, 416, 490, main_menu_img);//菜单
    painter.drawPixmap(221, 437, 360, 100, quit_game_botton_img);//退出游戏
    painter.drawPixmap(298, 175, 209, 46, fight_1_botton_img);//第一关按钮
    if(fight_stage>0)
        painter.drawPixmap(298, 235, 209, 46, fight_2_botton_img);//第二关按钮
    else
        painter.drawPixmap(298, 235, 209, 46, fight_locked_botton_img);
    if(fight_stage>1)
        painter.drawPixmap(298, 295, 209, 46, fight_3_botton_img);//第三关按钮
    else
        painter.drawPixmap(298, 295, 209, 46, fight_locked_botton_img);
    if(fight_stage>2)
        painter.drawPixmap(298, 355, 209, 46, fight_4_botton_img);//第四关按钮
    else
        painter.drawPixmap(298, 355, 209, 46, fight_locked_botton_img);
}

void PvZProj::on_fight_1_botton_clicked()
{
    game1->ChangeGameMode(0);
    this->hide();
    game1->restart();
    game1->show();
}
void PvZProj::on_fight_2_botton_clicked()
{
    if(fight_stage>0){
    game1->ChangeGameMode(1);
    this->hide();
    game1->restart();
    game1->show();
    }
}

void PvZProj::on_fight_3_botton_clicked()
{
    if(fight_stage>1){
    game1->ChangeGameMode(2);
    this->hide();
    game1->restart();
    game1->show();
    }
}

void PvZProj::on_fight_4_botton_clicked()
{
    if(fight_stage>2){
    game1->ChangeGameMode(3);
    this->hide();
    game1->restart();
    game1->show();
    }
}

void PvZProj::on_pushButton_clicked()
{
    game1->close();
    tempPauseWindow->close();
    tempfightendwindow->close();
    this->close();
}
