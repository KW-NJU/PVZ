#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QDialog>
#include<QBitmap>

namespace Ui {
class PauseWindow;
}

class PauseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PauseWindow(QWidget *parent = nullptr);
    ~PauseWindow();
public slots:
    void showself();
    void hideself();
protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::PauseWindow *ui;
    QPixmap pausewindow_background_img,restart_botton_img,back_to_menu_botton_img,continue_botton_img;
private slots:

    void on_continue_botton_clicked();
    void on_restart_botton_clicked();
    void on_return_to_menu_botton_clicked();
signals:
    void return_to_menu();
    void game_continue();
    void gameRestart();
};

#endif // PAUSEWINDOW_H
