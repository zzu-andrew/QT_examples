#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QGraphicsView>
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


    // 新建场景
    QGraphicsScene scene;
    // 创建矩形图形项
    QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, 100, 100);
    // 将图形项添加到场景中
    scene.addItem(item);
    // 输出(50, 50)点处的图形项
    qDebug() << scene.itemAt(50, 50, QTransform());

    // 为场景创建视图
    QGraphicsView view(&scene);
//    // 设置场景的前景色
//    view.setForegroundBrush(QColor(255, 255, 0, 100));
//    // 设置场景的背景图片
//    view.setBackgroundBrush(QPixmap("../myScene/background.png"));

    scene.setForegroundBrush(QColor(220, 210, 0, 100));
    scene.setBackgroundBrush(QPixmap(":/images/achou"));

    view.resize(400, 300);
    view.show();


    return a.exec();
}
