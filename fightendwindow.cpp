#include "fightendwindow.h"
#include "ui_fightendwindow.h"
using namespace std;
int fight_stage=0;
FightEndWindow::FightEndWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FightEndWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    gameover_img.load(gameover_img_des);
    gamewin_img.load(gamewin_img_des);
    back_to_menu_botton_img.load(Back_to_menu_botton_img_des);
    connect(ui->back_to_menu_botton,SIGNAL(clicked()),this,SIGNAL(return_to_menu()));
    this->move(0,0);
}

FightEndWindow::~FightEndWindow()
{
    delete ui;

}
void FightEndWindow::change_showmode(int in){
    showmode=in;
    if(in)emit fight_stage_upgrade();
}
void FightEndWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.translate(0, 0);
    if(showmode)
        painter.drawPixmap(110,200,580,110,gamewin_img);
    else
        painter.drawPixmap(119,50,564,468,gameover_img);
    painter.drawPixmap(320,480,163,46,back_to_menu_botton_img);
}
void FightEndWindow::on_back_to_menu_botton_clicked()
{
    this->hide();
}
