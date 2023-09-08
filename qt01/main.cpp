#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "newspaper.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Newspaper newspaper("Biden is dog!");
    Reader reader;


    QObject::connect(&newspaper, &Newspaper::NewPaper, &reader, &Reader::ReceiverNewsPaper);

    newspaper.Send();

    return app.exec();
}
