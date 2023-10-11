#include <QApplication>
#include <QPushButton>

#include "utils/spdlog_wrapper.h"
#include "fireshot.h"


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    // close all windows not close app
    QGuiApplication::setQuitOnLastWindowClosed(false);
    spdlog::SpdlogInit("FireShot", "logs/log.log", 23, 57, 0, 0);
    SPD_TRACE("start");


    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
