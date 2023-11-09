#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "form_plant.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void PushButtonAdd();

    void GenerateJson();

private:
    Ui::MainWindow *ui;

    JsonFormPlant *m_lpJsoFormPlant;
};

#endif // MAINWINDOW_H
