#include "mainwindow.h"
#include <QApplication>

/*
 * 绘图主要依赖QPainter QPaintDevice QPaintEngine三个类
 * QPainter :用来执行绘图操作
 * QPaintDevice 提供绘图设备，是一个二维空间的抽象
 * QPaintEngine 提供在不同设备上绘图能力，处理创建自定义绘图类型一般用不到该类
 *
 * 这里主要说2D绘图的相关的知识
 *
 *
 *
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
