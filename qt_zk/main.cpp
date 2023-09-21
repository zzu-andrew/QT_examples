#include "mainwindow.h"
#include <QApplication>

#include <zookeeper.h>
#include <proto.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
