#include "eventlabel.h"
#include <QString>
#include <QDebug>

EventLabel::EventLabel()
{

}

void EventLabel::mousePressEvent(QMouseEvent *ev)
{
    setText(QString("<center><h1>mousePressEvent: (%1, %2)</h1></center>").arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mouseMoveEvent(QMouseEvent *ev)
{
    setText(QString("<center><h1>mouseMoveEvent: (%1, %2)</h1></center>").arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    setText(QString("<center><h1>mouseReleaseEvent: (%1, %2)</h1></center>").arg(QString::number(ev->x()), QString::number(ev->y())));
}

// 事件处理可以在这里添加个过滤函数，那么这样就能将想要处理的函数进行过滤了
// 传入的事件如果被识别
bool EventLabel::event(QEvent *e)
{
    qDebug() << "e->type() " << e->type();

    // 添加自定义实现
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab) {
        qDebug() << "You press tab.";
        return true;
        }
    }


    return QLabel::event(e);
}
