#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent * event); // 拖动进入事件
    void dropEvent(QDropEvent *event); // 放下事件

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
