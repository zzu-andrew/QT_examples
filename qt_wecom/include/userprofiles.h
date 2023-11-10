#ifndef USERPROFILES_H
#define USERPROFILES_H


#include <QWidget>
#include "boderpane.h"

namespace Ui {
class UserProfiles;
}

class CMaskPane : public QWidget
{
    Q_OBJECT
public:
    explicit CMaskPane(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
};

class UserProfiles : public BoderPane
{
    Q_OBJECT
public:
    explicit UserProfiles(QWidget *parent = nullptr);
    ~UserProfiles();

private slots:
    void on_pushButton_clicked();

private:
    void CreateAllChildWnd();
    void InitCtrl();
    void Relayout();

private:
    Ui::UserProfiles *ui;
    QMovie *m_pMovie;
};

#endif // USERPROFILES_H
