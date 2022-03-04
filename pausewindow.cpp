#include "pausewindow.h"
#include "ui_pausewindow.h"
#include"Images_des.h"

PauseWindow::PauseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PauseWindow)
{
    ui->setupUi(this);
    pausewindow_background_img.load(PauseWindow_background_img_des);
    restart_botton_img.load(Restart_botton_img_des);
    back_to_menu_botton_img.load(Back_to_menu_botton_img_des);
    continue_botton_img.load(Continue_botton_img_des);


    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    //setWindowFlags (Qt::FramelessWindowHint);

    connect(ui->return_to_menu_botton,SIGNAL(clicked()),this,SIGNAL(return_to_menu()));
    connect(ui->continue_botton,SIGNAL(clicked()),this,SIGNAL(game_continue()));
    connect(ui->restart_botton,SIGNAL(clicked()),this,SIGNAL(gameRestart()));


    this->move(240,145);
}

PauseWindow::~PauseWindow()
{
    delete ui;
}
void PauseWindow::showself(){
    this->show();
}
void PauseWindow::hideself(){
    this->hide();
}
void PauseWindow::on_continue_botton_clicked()
{
    this->hide();
}

void PauseWindow::on_restart_botton_clicked()
{
    this->hide();
}

void PauseWindow::on_return_to_menu_botton_clicked()
{
    this->hide();
}
void PauseWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);  
    painter.translate(0, 0);
    painter.drawPixmap(0,0,320,310,pausewindow_background_img);
    painter.drawPixmap(82,90,163,46,restart_botton_img);
    painter.drawPixmap(82,150,163,46,back_to_menu_botton_img);
    painter.drawPixmap(32,220,256,62,continue_botton_img);
}

