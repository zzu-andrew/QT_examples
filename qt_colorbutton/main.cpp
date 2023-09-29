#include "mainwindow.h"
#include <QApplication>


/*
 *
 * 使用以下方式更改样式表，让你的程序增加那么一点点交互性；


QMainWindow{

    // 设置背景
    background-image: url(:/images/achou);
}

QPushButton {
    // 边框样式
    border-style : outset;
    // 边框宽度
    border-width : 7px;
    // 按钮边框圆角度
    border-radius : 10px;
    // 边框颜色
    border-color: rgb(239, 41, 41);
    // 字体大小
    font:bold 14px;
    // 字体颜色
    color:rgba(0,0,0,100);
    // 填衬
    padding:6px;
}

// 当鼠标悬停时
QPushButton:hover {
    background-color: rgb(252, 175, 62);
    border-color: rgba(255, 255, 255,200);
    color:rgba(0,0,0,200);
}
// 当鼠标按下时
QPushButton:pressed {
    background-color: rgba(100, 255, 100, 200);
    border-color: rgba(255, 255, 255,30);
    border-style:inset;
    color:rgba(0,0,0,100);
}

*/






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
