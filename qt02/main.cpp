#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    QWidget mainWin;
    window.setCentralWidget(&mainWin);

    window.setWindowTitle("Enter your age");
    QSpinBox *spinBox = new QSpinBox(&mainWin);
    QSlider *slider = new QSlider(Qt::Horizontal, &mainWin);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    spinBox->show();
    slider->show();
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
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
