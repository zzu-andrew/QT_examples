#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "httpreply.h"
#include "http.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HttpRequest()
{
    QUrl url;
    url.setUrl("http://localhost:8090/ocr_result");
    //    auto reply = Http::instance().get(url);
    std::string resultJsonStr = "data";
    QByteArray body = resultJsonStr.c_str();
    QByteArray type = "content-type: text/plain;charset=utf-8";

    auto reply = Http::instance().post(url, body, type);

    connect(reply, &HttpReply::finished, this, [](auto &reply) {
        if (reply.isSuccessful()) {
            qDebug() << "Feel the bytes!" << reply.body();
        } else {
            qDebug() << "Something's wrong here" << reply.statusCode() << reply.reasonPhrase();
        }
    });
}
