#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *actionPrinter = new QAction(tr("打印"), this);
    QAction *actionPrintPreview = new QAction(tr("打印预览"), this);
    QAction *actionPdf = new QAction(tr("生成pdf"), this);

    connect(actionPrinter, SIGNAL(triggered()), this, SLOT(doPrint));
    connect(actionPrintPreview, SIGNAL(triggered()), this, SLOT(doPrintPreview));
    connect(actionPdf, SIGNAL(triggered()), this, SLOT(createPdf));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doPrint()
{

}

void MainWindow::doPrintPreview()
{

}

void MainWindow::printPreview(QPrinter *printer)
{

}

void MainWindow::createPdf()
{

}
