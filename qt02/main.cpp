#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "eventlabel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    // EventLabel测试
    EventLabel label;
    label.setWindowTitle("MoseEvent Demo");
    label.resize(300, 200);
    label.show();

    // 单独常见一个窗口，因为主窗口中已经绑定过布局了这里就不绑定了
    QWidget mainWin;
    // 将新窗口设置为主窗口的中心窗口
//    window.setCentralWidget(&mainWin);
    // 设置窗口标题
    window.setWindowTitle("Enter your age");
    // QSpinBox 是一个输入框并且可以通过上下按钮修改数值
    QSpinBox *spinBox = new QSpinBox(&mainWin);
    // 滑动句柄
    QSlider *slider = new QSlider(Qt::Horizontal, &mainWin);
    // 数值范围
    spinBox->setRange(0, 130);
    // 滑动句柄代表的数值范围
    slider->setRange(0, 130);
    // 以下是如何通过两个信号将输入窗口和滑动窗口之间实现梦幻联动
    // 一旦滑动窗口值改变，将值通过信号发送给输入窗口
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    // 输入窗口值变动也会通知滑动窗口
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
    spinBox->setValue(35);
    //给控件设置布局
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    mainWin.setLayout(layout);

    window.show();


    return a.exec();
}
