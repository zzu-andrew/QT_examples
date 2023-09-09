#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "newspaper.h"
#include <QMenuBar>
#include <QAction>
#include <QToolBar>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    // 添加menu
    auto FileMenu = win.menuBar()->addMenu("File");
    FileMenu->addAction("New file");

    win.menuBar()->addMenu("Edit");
    win.menuBar()->addMenu("Tools");
    win.menuBar()->addMenu("Help");

    // 添加工具条
    auto newToolBar = new QToolBar(&win);
    newToolBar->setObjectName(QString::fromUtf8("newToolBar"));
    win.addToolBar(Qt::RightToolBarArea, newToolBar);
    newToolBar->addAction("paste");


    Newspaper newspaper("Biden is dog.");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::NewPaper, &reader, &Reader::ReceiverNewsPaper);
    QObject::connect(&newspaper, &Newspaper::NewPaper, [=](const QString & name){
        qDebug() << "lambda : " << name ;
    });

    newspaper.Send();

    return app.exec();
}
