#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include<iostream>
#include<fstream>
#include <QPainter>
#include <QtMultimedia/QSound>
#include"GameState.h"
#include"fightendwindow.h"
#include<QTimer>

namespace Ui {
class game; 

}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void ChangeGameMode(int _mode);
public slots:
    void time_start();
    void reset();
    void restart();
    void gamePause();
    void gameContinue();
private:
    Ui::game *ui;
    gamestate* temp_gamestate=NULL;
    int cursor_state;
    int time_cnt;
    int GameMode;
    bool Paused=0;
    QSound* bgm;
    QTimer* timestate;
    QPixmap lawn_img,SeedBank_img,ShovelBank_img,Shovel_img,Sunshine_img,PauseBotton_img,plants_img[100],zombies_img[200],bullet_img[10];
protected:
    void paintEvent(QPaintEvent *);
private slots:

    void on_lawn_area_clicked();
    void on_shop_list_area_clicked();
    void on_shovel_area_clicked();
    void time_action();
    void on_pause_botton_clicked();
    void fight_stage_upgrade();

signals:
    void ShowPauseWindow();
    void gameend(int);
};

#endif // GAME_H
