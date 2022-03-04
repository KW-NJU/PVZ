#ifndef FIGHTENDWINDOW_H
#define FIGHTENDWINDOW_H

#include <QDialog>
#include<QPainter>
#include"Images_des.h"

extern int fight_stage;

namespace Ui {
class FightEndWindow;
}

class FightEndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FightEndWindow(QWidget *parent = nullptr);
    ~FightEndWindow();


protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_back_to_menu_botton_clicked();
    void change_showmode(int in);
private:
    Ui::FightEndWindow *ui;
    int showmode=0;
    QPixmap gameover_img,gamewin_img,back_to_menu_botton_img;

signals:
    void return_to_menu();
    void fight_stage_upgrade();
};

#endif // FIGHTENDWINDOW_H
#pragma once
