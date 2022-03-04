/********************************************************************************
** Form generated from reading UI file 'pausewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEWINDOW_H
#define UI_PAUSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PauseWindow
{
public:
    QPushButton *restart_botton;
    QPushButton *return_to_menu_botton;
    QPushButton *continue_botton;

    void setupUi(QDialog *PauseWindow)
    {
        if (PauseWindow->objectName().isEmpty())
            PauseWindow->setObjectName(QString::fromUtf8("PauseWindow"));
        PauseWindow->resize(320, 310);
        PauseWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        restart_botton = new QPushButton(PauseWindow);
        restart_botton->setObjectName(QString::fromUtf8("restart_botton"));
        restart_botton->setGeometry(QRect(82, 90, 163, 46));
        restart_botton->setFocusPolicy(Qt::NoFocus);
        restart_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        return_to_menu_botton = new QPushButton(PauseWindow);
        return_to_menu_botton->setObjectName(QString::fromUtf8("return_to_menu_botton"));
        return_to_menu_botton->setGeometry(QRect(82, 150, 163, 46));
        return_to_menu_botton->setFocusPolicy(Qt::NoFocus);
        return_to_menu_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);"));
        continue_botton = new QPushButton(PauseWindow);
        continue_botton->setObjectName(QString::fromUtf8("continue_botton"));
        continue_botton->setGeometry(QRect(32, 220, 256, 62));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(20, 65, 227, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(160, 160, 160, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush3(QColor(105, 105, 105, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        QBrush brush4(QColor(0, 0, 255, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush4);
        QBrush brush5(QColor(255, 0, 255, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush5);
        QBrush brush6(QColor(246, 246, 246, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        QBrush brush7(QColor(0, 0, 0, 0));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        QBrush brush8(QColor(170, 255, 255, 0));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        continue_botton->setPalette(palette);
        continue_botton->setFocusPolicy(Qt::NoFocus);
        continue_botton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"gridline-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 0);\n"
""));

        retranslateUi(PauseWindow);

        QMetaObject::connectSlotsByName(PauseWindow);
    } // setupUi

    void retranslateUi(QDialog *PauseWindow)
    {
        PauseWindow->setWindowTitle(QCoreApplication::translate("PauseWindow", "Pause", nullptr));
        restart_botton->setText(QString());
        return_to_menu_botton->setText(QString());
        continue_botton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseWindow: public Ui_PauseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWINDOW_H
