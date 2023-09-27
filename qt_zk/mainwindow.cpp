#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QMainWindow>
#include <QLibrary>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 创建按钮
       button1 = new QPushButton("切换到界面1", this);
       button2 = new QPushButton("切换到界面2", this);

       // 创建堆叠窗口
       stackedWidget = new QStackedWidget(this);

       // 将堆叠窗口和按钮添加到主窗口的布局中
       QVBoxLayout* layout = new QVBoxLayout();
       layout->addWidget(button1);
       layout->addWidget(button2);
       layout->addWidget(stackedWidget);

       QWidget* centralWidget = new QWidget(this);
       centralWidget->setLayout(layout);
       setCentralWidget(centralWidget);

       // 连接按钮的 clicked 信号到槽函数
       connect(button1, &QPushButton::clicked, this, &MyMainWindow::showPage1);
       connect(button2, &QPushButton::clicked, this, &MyMainWindow::showPage2);


}

MainWindow::~MainWindow()
{
    delete ui;
}
