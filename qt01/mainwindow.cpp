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

int32_t MainWindow::FileOperator()
{
    auto openAction = new QAction(QIcon(":/images/act_del_line.png"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    auto saveAction = new QAction(QIcon(":/images/act_del_line.png"),
    tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(openAction);
    file->addAction(saveAction);

    m_textEdit = new QTextEdit(this);
    // 将组件作为中心组件
    setCentralWidget(m_textEdit);

    // 使用信号槽触发响应动作
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    return 0;
}

// 打开文件
void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open file"), tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QTextStream in(&file);
        m_textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path is not exist!"), "Check again!", QMessageBox::Ok);
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Open file"), tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QTextStream out(&file);
        // 将 m_textEdit中文件转换为纯文本保存到out指定的文件中
        out << m_textEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path is not exist!"), "Check again!", QMessageBox::Ok);
    }
}

