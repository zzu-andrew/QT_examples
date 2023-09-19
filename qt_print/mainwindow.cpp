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

    connect(actionPrinter, &QAction::triggered, this, &MainWindow::doPrint);
    connect(actionPrintPreview, &QAction::triggered, this, &MainWindow::doPrintPreview);
    connect(actionPdf, &QAction::triggered, this, &MainWindow::createPdf);
    ui->mainToolBar->addAction(actionPrinter);
    ui->mainToolBar->addAction(actionPrintPreview);
    ui->mainToolBar->addAction(actionPdf);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doPrint()
{
    // 定义一个打印机对象
    QPrinter printer;
    // 创建打印机对话框
    QPrintDialog dlg(&printer, this);
    // 如果文本编辑器中有选中文本区域，则打印选中的区域
    if (ui->textEdit->textCursor().hasSelection()) {
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }

    // 如果按下了打印按钮
    if (dlg.exec() == QDialog::Accepted) {
        ui->textEdit->print(&printer);
    }

}

void MainWindow::doPrintPreview()
{
    // 定义一个打印机对象
    QPrinter printer;
    // 创建预览对话框
    QPrintPreviewDialog preview(&printer, this);
    // 发信号给printPreview生成预览界面
    connect(&preview, &QPrintPreviewDialog::paintRequested, this, &MainWindow::printPreview);
    // 等待打印界面返回
    preview.exec();
}

void MainWindow::printPreview(QPrinter *printer)
{
    ui->textEdit->print(printer);

}

void MainWindow::createPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"), QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty()) {
            fileName.append(".pdf");
        }
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        ui->textEdit->print(&printer);
    }
}
