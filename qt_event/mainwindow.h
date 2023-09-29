#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "line_edit.h"


namespace Ui {
class Widget;
}


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::Widget *ui;
    LineEdit *lineEdit;

protected:
    void keyPressEvent(QKeyEvent *event);

};


#endif // MAINWINDOW_H
