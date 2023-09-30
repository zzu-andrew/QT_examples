#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMouseTracking(true);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    angle = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    angle += 10;
    if(angle == 360)
        angle = 0;
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    transform.translate(width()/2, height()/2);
    transform.scale(side/300.0, side/300.0);
    transform.rotate(angle);
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}

