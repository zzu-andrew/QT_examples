#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Topic辅助工具");

    m_lpJsoFormPlant = new JsonFormPlant;

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::PushButtonAdd);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::GenerateJson);

}

MainWindow::~MainWindow()
{
    delete m_lpJsoFormPlant;
    delete ui;
}

void MainWindow::PushButtonAdd()
{
    m_lpJsoFormPlant->SetKey(ui->lineEdit->text());
    m_lpJsoFormPlant->SetType(ui->comboBox->currentText());
    m_lpJsoFormPlant->SetValue(ui->lineEdit_2->text());
    m_lpJsoFormPlant->SetStepSize(ui->spinBox_2->value());
    auto jsonInfo = m_lpJsoFormPlant->GetCurrentJsonForm();
    m_lpJsoFormPlant->AddJsonForm(jsonInfo);
    auto itemJson = m_lpJsoFormPlant->PriviewJsonInfo();
    std::string dumpStr = itemJson.dump(4);
    std::cout << dumpStr << std::endl;;
    ui->label->setText(QString::fromStdString(dumpStr));
}

void MainWindow::GenerateJson()
{

    auto num = ui->spinBox->value();
    auto retJson = m_lpJsoFormPlant->GenerateFormJson(num);

    std::string dumpStr = retJson.dump(4);


   ui->textEdit->setText(QString::fromStdString(dumpStr));



}
