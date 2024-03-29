#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QMimeData>
#include <QDrag>

#include <QDebug>

#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置窗口部件可以接收拖入
    setAcceptDrops(true);
    // 创建一个用来拖动的标签
    QLabel *label = new QLabel(this);
    // 添加资源
    QPixmap pix(":/images/achou");
//    QPixmap pix("../qt_imagedragdrop/logo.png");
    label->setPixmap(pix);
    // 将标签的大小调整成图片的大小
    label->resize(pix.size());
    label->move(100, 100);
    // 当窗口关闭的时候销毁资源
    label->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{

    // 首先进行图片的获取
    // 将鼠标指针所在的位置强制转换为QLabel类型
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child->inherits("QLabel")) return; // 类型检测如果不是QLabel类型就直接返回
    // 获取QLabel中的图片
    QPixmap pixmap = *child->pixmap();
    // 自定义元数据类型
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);  // 创建字节流数据
    // 将图片以及位置信息输入到字节数组中
    dataStream << pixmap << QPoint(event->pos() - child->pos());
    // 将以上数据放入搭配QMimeData中
    QMimeData * mimeData = new QMimeData;
    // 将字节数组放入到QMimeData中，这里的元数据是我们自定义的数据类型
    mimeData->setData("myimage/png", itemData);
    // 将mime数据放入到drag中
    QDrag *drag = new QDrag(this); // 创建drag用它来实现移动数据
    drag->setMimeData(mimeData);
    // 移动过程中显示图片，若是不进行设置则会显示一个小矩形框
    drag->setPixmap(pixmap);
    // 移动过程中鼠标的位置在图片的位置上保持不变，通过设置鼠标抓手实现鼠标在drag移动过程中相对位置一直不改变
    // 如果不设置，拖动过程鼠标将位于左上角位置
    drag->setHotSpot(event->pos() - child->pos());
    // 给原始图片添加阴影
    QPixmap tempPixmap = pixmap; // 使用原始图片
    QPainter painter; // 创建画板
    painter.begin(&tempPixmap);
    // 给图片蒙上一层透明但是淡淡的黑色效果
    painter.fillRect(pixmap.rect(), QColor(121, 127, 127, 127));
    painter.end();
    child->setPixmap(tempPixmap);// 在移动过程中让图片添加一层黑色的阴影
    // 执行拖拽操作
    // 设置拖拽支持复制和移动操作，默认是复制操作，如果是移动操作，那么在拖拽完成之后关闭原有的标签
    // 需要注意的是，drag在点击之后，执行exec会一直卡在这里，直到鼠标松开之后exec会返回一个执行的事件
    // 这里的返回值只受到 dropEvent接口的影响
    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
qDebug() << "1=========";
        child->close();
    } else {
qDebug() << "2=========";
        // 如果是复制那么拖拽完成之后显示标签
        child->show();
        // 现实原来的图片而不是阴影
        child->setPixmap(pixmap);
    }
}

// window drag event
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    // 判断是否是我们自定义的mime类型数据，如果是就进行移动操作
    if (event->mimeData()->hasFormat("myimage/png")) {
        // 这里设置不设置不影响最终结果，但是会影响点击是鼠标的默认小标签，
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }

}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("myimage/png")) {
        // 这里设置不设置不影响最终结果，但是会影响点击是鼠标的默认小标签，
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    // 获取mimedata
    if (event->mimeData()->hasFormat("myimage/png")) {
        QByteArray itemData = event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        // accord the in stream order
        dataStream >> pixmap >> offset;
        // create new label add pixpng
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        newLabel->move(event->pos() - offset);
        newLabel->show();
        // win close clear the pixmap
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
//         event->setDropAction(Qt::CopyAction);
        event->accept();
    } else {
        event->ignore();
    }
}
