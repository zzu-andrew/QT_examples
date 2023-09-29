#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_widget.h"


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




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lineEdit = new LineEdit(this);
    lineEdit->move(100, 100);
    // 这样当事件过来时，会调用事件过滤器的eventFilter函数
    lineEdit->installEventFilter(this);   // 在Widget上为lineEdit安装事件过滤器
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("Widget键盘按下事件");
}

bool Widget::eventFilter(QObject *obj, QEvent *event) // 事件过滤器
{
    if(obj == lineEdit){              // 如果是lineEdit部件上的事件
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("Widget的事件过滤器");
    }
    return QWidget::eventFilter(obj, event);
}


