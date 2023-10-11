//
// Created by wangyz38535 on 2023/9/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "fireshot.h"
#include "ui_mainwindow.h"
#include "utils/spdlog_wrapper.h"

FireShot::FireShot(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::FireShot) {
    ui->setupUi(this);
#ifdef Q_OS_UNIX
    gdk_init(NULL, NULL);
#endif // Q_OS_LINUX
}

FireShot::~FireShot() {
    delete ui;
    SPD_FLUSH();
}

