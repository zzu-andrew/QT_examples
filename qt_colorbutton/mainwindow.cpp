#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    // 当然除了手动去ui中进行设置，也可以直接加载qss文件来实现设置
//    auto qssFile = new QFile(":/css/my.qss", this);
//    qssFile->open(QFile::ReadOnly);

//    QString styleSheet = tr(qssFile->readAll());
//    qApp->setStyleSheet(styleSheet);
//    qssFile->close();

    //    // 设置窗口的不透明度为0.5
//        setWindowOpacity(0.7);
        // FramelessWindowHint 实现窗体透明效果
//        setWindowFlags(Qt::FramelessWindowHint);
        // 使窗体透明但是其他部件不受影响
        setAttribute(Qt::WA_TranslucentBackground);

    //    // 创建阴影效果
    //    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    //    // 设置阴影颜色
    //    effect->setColor(QColor(100, 100, 100, 100));
    //    // 设置阴影模糊半径
    //    effect->setBlurRadius(2);
    //    // 设置阴影偏移值
    //    effect->setOffset(10);
    //    // 标签部件使用阴影效果
    //    ui->label->setGraphicsEffect(effect);



}

MainWindow::~MainWindow()
{
    delete ui;
}
