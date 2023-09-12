#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "newspaper.h"
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QStringList>
#include <QCompleter>
#include <QLineEdit>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    // 添加menu

//    win.FileOperator();

//    win.menuBar()->addMenu("Edit");
//    win.menuBar()->addMenu("Tools");
//    win.menuBar()->addMenu("Help");

//    // 添加工具条
//    auto newToolBar = new QToolBar(&win);
//    newToolBar->setObjectName(QString::fromUtf8("newToolBar"));
//    win.addToolBar(Qt::RightToolBarArea, newToolBar);
//    newToolBar->addAction("paste");

//    QStringList tiplist;
//    tiplist << "Hello" << "How are you!" << "Haha" << "Oh no!";\
//    // 输入辅助
//    QCompleter *completer = new QCompleter(tiplist, &win);
//    // 设置大小写不敏感
//    completer->setCaseSensitivity(Qt::CaseInsensitive);
//    // 输入内容包含就会提示
//    completer->setFilterMode(Qt::MatchContains);
//    QLineEdit *edit = new QLineEdit(&win);
//    edit->setCompleter(completer);
//    edit->show();


//    QLabel *label = new QLabel(&win);
//    label->setText("Hello world!");
//    label->show();

//    QLabel * label = new QLabel(&win);
//    label ->setText("Hello, World");
//    label ->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
//    label ->setOpenExternalLinks(true);
//    label->show();

//    QPixmap pim(":/images/achou");
//    QLabel *label = new QLabel;
//    label->setPixmap(pim);
//    label->show();

    // 打开一个默认情况下的模态对话框
    // 该对话框不关闭不能对主窗口进行任何操作
//    QDialog dialog(&win);
//    dialog.setWindowTitle("Hello, dialog!");
//    dialog.show();

//    auto movie = new QMovie(":/images/cheer.gif");
//    movie->start();
//    QLabel *label = new QLabel(&win);
//    label->setMovie(movie);
//    label->show();


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





//    Newspaper newspaper("Biden is dog.");
//    Reader reader;
//    QObject::connect(&newspaper, &Newspaper::NewPaper, &reader, &Reader::ReceiverNewsPaper);
//    QObject::connect(&newspaper, &Newspaper::NewPaper, [=](const QString & name){
//        qDebug() << "lambda : " << name ;
//    });

//    newspaper.Send();

    return app.exec();
}
