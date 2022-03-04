/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralwidget;
    QPushButton *lawn_area;
    QPushButton *shop_list_area;
    QPushButton *shovel_area;
    QPushButton *pause_botton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(800, 600);
        game->setContextMenuPolicy(Qt::PreventContextMenu);
        centralwidget = new QWidget(game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lawn_area = new QPushButton(centralwidget);
        lawn_area->setObjectName(QString::fromUtf8("lawn_area"));
        lawn_area->setGeometry(QRect(34, 88, 720, 568));
        lawn_area->setFocusPolicy(Qt::NoFocus);
        lawn_area->setAutoFillBackground(false);
        lawn_area->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        shop_list_area = new QPushButton(centralwidget);
        shop_list_area->setObjectName(QString::fromUtf8("shop_list_area"));
        shop_list_area->setGeometry(QRect(88, 8, 356, 70));
        shop_list_area->setFocusPolicy(Qt::NoFocus);
        shop_list_area->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        shovel_area = new QPushButton(centralwidget);
        shovel_area->setObjectName(QString::fromUtf8("shovel_area"));
        shovel_area->setGeometry(QRect(456, 10, 70, 72));
        shovel_area->setFocusPolicy(Qt::NoFocus);
        shovel_area->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        pause_botton = new QPushButton(centralwidget);
        pause_botton->setObjectName(QString::fromUtf8("pause_botton"));
        pause_botton->setGeometry(QRect(600, 0, 120, 42));
        pause_botton->setFocusPolicy(Qt::NoFocus);
        pause_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);\n"
""));
        game->setCentralWidget(centralwidget);
        menubar = new QMenuBar(game);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        game->setMenuBar(menubar);
        statusbar = new QStatusBar(game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        game->setStatusBar(statusbar);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "PvZProj", nullptr));
        lawn_area->setText(QString());
        shop_list_area->setText(QString());
        shovel_area->setText(QString());
        pause_botton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
