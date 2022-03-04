/********************************************************************************
** Form generated from reading UI file 'fightendwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHTENDWINDOW_H
#define UI_FIGHTENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FightEndWindow
{
public:
    QPushButton *back_to_menu_botton;

    void setupUi(QDialog *FightEndWindow)
    {
        if (FightEndWindow->objectName().isEmpty())
            FightEndWindow->setObjectName(QString::fromUtf8("FightEndWindow"));
        FightEndWindow->resize(800, 600);
        back_to_menu_botton = new QPushButton(FightEndWindow);
        back_to_menu_botton->setObjectName(QString::fromUtf8("back_to_menu_botton"));
        back_to_menu_botton->setGeometry(QRect(320, 480, 163, 46));
        back_to_menu_botton->setFocusPolicy(Qt::NoFocus);
        back_to_menu_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));

        retranslateUi(FightEndWindow);

        QMetaObject::connectSlotsByName(FightEndWindow);
    } // setupUi

    void retranslateUi(QDialog *FightEndWindow)
    {
        FightEndWindow->setWindowTitle(QCoreApplication::translate("FightEndWindow", "Dialog", nullptr));
        back_to_menu_botton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FightEndWindow: public Ui_FightEndWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHTENDWINDOW_H
