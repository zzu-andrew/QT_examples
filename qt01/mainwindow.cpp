#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

    QMenu *file = menuBar()->addMenu("&File");
    // 创建一个菜单子项
    auto openAction = new QAction(QIcon(":/images/act_del_line.png"), tr("&Open..."), this);
//    auto openAction = new QAction(this);
    // 菜单子项添加快捷键
    openAction->setShortcuts(QKeySequence::Open);
    // 当鼠标放到菜单子项上时status bar上面将会显示
    openAction->setStatusTip(tr("Open an existing file"));
    file->addAction(openAction);

    auto saveAction = new QAction(QIcon(":/images/act_del_line.png"),tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    // 添加一个菜单用来放置上述菜单子项
    file->addAction(saveAction);

    // 创建一个文本编辑器，并将其作为主窗口
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

    // 通过Dialog窗口来获取文件路径
    QString path = QFileDialog::getOpenFileName(this, tr("Open file"), ".", "Code file(*.cpp);;JPEG Files(*.jpg);;PNG Files(*.png)");
    if (!path.isEmpty())
    {
        // 按照只读的当时打开文件
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        // 使用文件流方式来将文件内容读取到文本编辑器中
        QTextStream in(&file);
        m_textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path is not exist!"), "Check again!", QMessageBox::Ok);
    }
}

// 保存文件
void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Open file"), ".", tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        // 这里注意，要设置为写，否则保存失败
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

