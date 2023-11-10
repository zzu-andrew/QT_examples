#ifndef APPRECIATEDLG_H
#define APPRECIATEDLG_H

#include <QWidget>
#include "basedlg.h"

namespace Ui {
class AppreciateDlg;
}

class AppreciateDlg : public CBaseDlg
{
    Q_OBJECT

public:
    explicit AppreciateDlg(QWidget *parent = 0);
    ~AppreciateDlg();

private:
    void CreateAllChildWnd();
    void InitCtrl();
    void Relayout();

private:
    Ui::AppreciateDlg *ui;
};

#endif // APPRECIATEDLG_H
