#ifndef PVZPROJ_H
#define PVZPROJ_H

#include <QMainWindow>
#include<QTimer>
#include<iostream>
#include<fstream>
#include"Images_des.h"
#include"game.h"
#include"pausewindow.h"
#include"fightendwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PvZProj; }
QT_END_NAMESPACE

class PvZProj : public QMainWindow
{
    Q_OBJECT

public:
    PvZProj(QWidget *parent = nullptr);
    ~PvZProj();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();
    void on_fight_1_botton_clicked();
    void on_fight_2_botton_clicked();
    void on_fight_3_botton_clicked();

    void on_fight_4_botton_clicked();

private:
    Ui::PvZProj *ui;
    game* game1=new game;
    PauseWindow* tempPauseWindow=new PauseWindow;
    FightEndWindow* tempfightendwindow=new FightEndWindow;
    QPixmap main_menu_img,quit_game_botton_img,fight_1_botton_img,fight_2_botton_img,fight_3_botton_img,fight_4_botton_img,fight_locked_botton_img;
    QTimer *timer = new QTimer(this);

};
#endif // PVZPROJ_H
