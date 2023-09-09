#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("test");
}


MainWindow::~MainWindow()
{
    delete ui;
}

int32_t MainWindow::GetUi()
{


    return 0;
}

