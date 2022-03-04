/********************************************************************************
** Form generated from reading UI file 'pvzproj.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVZPROJ_H
#define UI_PVZPROJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PvZProj
{
public:
    QWidget *centralwidget;
    QPushButton *fight_1_botton;
    QPushButton *pushButton;
    QPushButton *fight_2_botton;
    QPushButton *fight_3_botton;
    QPushButton *fight_4_botton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PvZProj)
    {
        if (PvZProj->objectName().isEmpty())
            PvZProj->setObjectName(QString::fromUtf8("PvZProj"));
        PvZProj->resize(800, 600);
        centralwidget = new QWidget(PvZProj);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        fight_1_botton = new QPushButton(centralwidget);
        fight_1_botton->setObjectName(QString::fromUtf8("fight_1_botton"));
        fight_1_botton->setGeometry(QRect(298, 175, 209, 46));
        fight_1_botton->setFocusPolicy(Qt::NoFocus);
        fight_1_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(231, 437, 340, 100));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        fight_2_botton = new QPushButton(centralwidget);
        fight_2_botton->setObjectName(QString::fromUtf8("fight_2_botton"));
        fight_2_botton->setGeometry(QRect(298, 235, 209, 46));
        fight_2_botton->setFocusPolicy(Qt::NoFocus);
        fight_2_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);\n"
""));
        fight_3_botton = new QPushButton(centralwidget);
        fight_3_botton->setObjectName(QString::fromUtf8("fight_3_botton"));
        fight_3_botton->setGeometry(QRect(298, 295, 209, 46));
        fight_3_botton->setFocusPolicy(Qt::NoFocus);
        fight_3_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);\n"
""));
        fight_4_botton = new QPushButton(centralwidget);
        fight_4_botton->setObjectName(QString::fromUtf8("fight_4_botton"));
        fight_4_botton->setGeometry(QRect(298, 355, 209, 46));
        fight_4_botton->setFocusPolicy(Qt::NoFocus);
        fight_4_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        PvZProj->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PvZProj);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        PvZProj->setMenuBar(menubar);
        statusbar = new QStatusBar(PvZProj);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PvZProj->setStatusBar(statusbar);

        retranslateUi(PvZProj);

        QMetaObject::connectSlotsByName(PvZProj);
    } // setupUi

    void retranslateUi(QMainWindow *PvZProj)
    {
        PvZProj->setWindowTitle(QCoreApplication::translate("PvZProj", "PvZProj", nullptr));
        fight_1_botton->setText(QString());
        pushButton->setText(QString());
        fight_2_botton->setText(QString());
        fight_3_botton->setText(QString());
        fight_4_botton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PvZProj: public Ui_PvZProj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVZPROJ_H
