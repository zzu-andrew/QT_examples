#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);
    // 这里必须去下textEdit的默认拖拽方式，因为textEdit的默认只是现实路径名，
    // 要是想显示全部文件这里这里就需要将textEdit的默认拖拽给关掉
    ui->textEdit->setAcceptDrops(false); // 取消textEdit的默认拖拽方式


}

MainWindow::~MainWindow()
{
    delete ui;
}

// 鼠标放开事件
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    // 获取事件带过来的mime数据(元数据)
    const auto *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        // 用例里面只取第一个本地文件路径
        QString fileName = urlList.at(0).toLocalFile();
        if (!fileName.isEmpty()) {
            // 创建file文件对象用来读取文件内容
            QFile file(fileName);
            auto bSuccess = file.open(QIODevice::ReadOnly);
            if (!bSuccess) {
                return ;
            }
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }


}

void MainWindow::dropEvent(QDropEvent *event)
{
    // 检查拖过来的数据是否包含URL，只有包含utl的数据才进行接受
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction(); // 如果是则接收对应的动作
    } else {
        event->ignore();
    }

}
