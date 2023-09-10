#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextCodec>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

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

    int32_t GetUi();

    int32_t FileOperator();

    void openFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    QTextEdit * m_textEdit;
};

#endif // MAINWINDOW_H
