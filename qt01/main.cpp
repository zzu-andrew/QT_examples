#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "newspaper.h"
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDialog>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    // 添加menu

    win.FileOperator();



    win.menuBar()->addMenu("Edit");
    win.menuBar()->addMenu("Tools");
    win.menuBar()->addMenu("Help");

    // 添加工具条
    auto newToolBar = new QToolBar(&win);
    newToolBar->setObjectName(QString::fromUtf8("newToolBar"));
    win.addToolBar(Qt::RightToolBarArea, newToolBar);
    newToolBar->addAction("paste");

    // 打开一个默认情况下的模态对话框
    // 该对话框不关闭不能对主窗口进行任何操作
    QDialog dialog(&win);
    dialog.setWindowTitle("Hello, dialog!");
    dialog.show();

    // 弹窗消息
//    QMessageBox::about(&win, "MessageBox", "Test for message box!");
//    QMessageBox::aboutQt(&win, "MessageBox");

//    if (QMessageBox::Yes == QMessageBox::question(&win, ("Question"),
//                                                  ("Are you OK?"), QMessageBox::Save | QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
//    {
//        QMessageBox::information(&win, ("Hmmm..."),("I'm glad to hear that!"));
//    } else {
//        QMessageBox::information(&win, ("Hmmm..."), ("I'm sorry!"));
//    }





    Newspaper newspaper("Biden is dog.");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::NewPaper, &reader, &Reader::ReceiverNewsPaper);
    QObject::connect(&newspaper, &Newspaper::NewPaper, [=](const QString & name){
        qDebug() << "lambda : " << name ;
    });

    newspaper.Send();

    return app.exec();
}
