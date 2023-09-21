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


       QString strLibPath = ":/libs/zookeeper";

       if (!QLibrary::isLibrary(strLibPath))
       {
           qDebug() << strLibPath << "!QLibrary::isLibrary";
       }

       auto m_pLib = new QLibrary(strLibPath);
       bool libload =false;
       if(!m_pLib->load())   //dll加载
       {
           qDebug()<<"load failed";
       }else
       {
           qDebug()<<"load succ";
           libload =true;
       }

//       if(!resolveFunction(m_myadd, "add"))
//       {
//           qDebug()<<"failed";
//       }else
//       {
//           int ret = m_myadd(5,8);
//           qDebug()<<"ret = "<<ret;
//       }


}

MainWindow::~MainWindow()
{
    delete ui;
}
