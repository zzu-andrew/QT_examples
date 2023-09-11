#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class EventLabel : public QLabel
{
public:
    EventLabel();

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;


};

#endif // EVENTLABEL_H
