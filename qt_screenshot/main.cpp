#include <QApplication>
#include <QPushButton>
#include <QSystemTrayIcon>

#include "utils/spdlog_wrapper.h"
#include "fireshot.h"


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    // close all windows not close app
    QGuiApplication::setQuitOnLastWindowClosed(false);
    spdlog::SpdlogInit("FireShot", "logs/log.log", 23, 57, 0, 0);
    SPD_TRACE("start");

    // 查看系统是否支持托盘功能
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        SPD_ERROR("system tray disabled");
        return 1;
    }

    //设置系统默认字体
    QFont defaultFont("微软雅黑",9);
    QApplication::setFont(defaultFont);

    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
