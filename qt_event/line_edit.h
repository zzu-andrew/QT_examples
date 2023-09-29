#ifndef LIEN_EDIT_H
#define LIEN_EDIT_H
#include <QKeyEvent>
#include <QDebug>
#include <QLineEdit>

#include "ui_widget.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = 0);

    bool event(QEvent *event);
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // LIEN_EDIT_H
