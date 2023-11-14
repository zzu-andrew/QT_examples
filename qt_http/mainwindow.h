#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <httprequest.h>
#include "http_server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void HttpRequest();

private:
    Ui::MainWindow *ui;
    HttpServer m_httpServer;  // 定义一个http服务端
};

#endif // MAINWINDOW_H
