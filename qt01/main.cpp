#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "newspaper.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();

    Newspaper newspaper("Biden is dog!");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::NewPaper, &reader, &Reader::ReceiverNewsPaper);


    QObject::connect(&newspaper, &Newspaper::NewPaper, [=](const QString & name){
        qDebug() << "lambda : " << name ;
    });

    newspaper.Send();

    return app.exec();
}
