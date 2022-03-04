#include "pvzproj.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PvZProj w;
    w.show();
    return a.exec();
}
