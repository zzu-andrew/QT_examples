#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrayIcon tray(&a);
    tray.show();

    return a.exec();
}
