#include "appreciatedlg.h"
#include "ui_appreciatedlg.h"

AppreciateDlg::AppreciateDlg(QWidget *parent) :
    CBaseDlg(parent),
    ui(new Ui::AppreciateDlg)
{
    ui->setupUi(this);


    CreateAllChildWnd();
    InitCtrl();
    Relayout();
}

AppreciateDlg::~AppreciateDlg()
{
    delete ui;
}

void AppreciateDlg::CreateAllChildWnd()
{

}

void AppreciateDlg::InitCtrl()
{

}

void AppreciateDlg::Relayout()
{
    QVBoxLayout *layoutVMain = new QVBoxLayout();
    layoutVMain->addWidget(ui->label);
    layoutVMain->addWidget(ui->label_2);
    layoutVMain->addStretch();
    layoutVMain->setSpacing(20);
    layoutVMain->setContentsMargins(40, 10, 40, 60);

    centralWidget()->setLayout(layoutVMain);
}
