//
// Created by wangyz38535 on 2023/9/17.
//

#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class FireShot; }
QT_END_NAMESPACE

class FireShot : public QMainWindow {
Q_OBJECT

public:
    explicit FireShot(QWidget *parent = nullptr);

    ~FireShot() override;

private:
    Ui::FireShot *ui;
};


#endif //TEST_MAINWINDOW_H
