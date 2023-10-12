//
// Created by wangyz38535 on 2023/9/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QAction>
#include <QMenu>
#include <QDesktopWidget>

#include "fireshot.h"
#include "utils/spdlog_wrapper.h"



FireShot::FireShot(QWidget *parent) :
    QDialog(parent), m_lpTrayIcon(new QSystemTrayIcon(this)),
    m_lpTrayIconMenu(new QMenu(this)),
    m_lpSettingDlg(new SettingDlg(this)) {

}

FireShot::~FireShot() {
    SPD_FLUSH();
}

void FireShot::OnShowSetting()
{
    if (!m_lpSettingDlg->isVisible())
    {
        m_lpSettingDlg->showNormal();
        int w = QApplication::desktop()->width(),
            h = QApplication::desktop()->height();

        int w1 = m_lpSettingDlg->width(),
            h1 = m_lpSettingDlg->height();

        m_lpSettingDlg->move((w - w1) / 2, (h - h1) / 2);
    }


}

int32_t FireShot::CreateActions() {
    // construct tray setting icon
    m_lpSettingAction = new QAction(tr("&Settings"), this);
    QIcon settingIcon(":/icons/icon/menu-setting.png");
    m_lpSettingAction->setIcon(settingIcon);
    connect(m_lpSettingAction, SIGNAL(triggered()), this, SLOT(OnShowSetting));
    // construct tray shot icon
    m_lpShotAction = new QAction(tr("S$hot"), this);
    QIcon shotIcon(":/icons/icon/menu-shot.png");
    m_lpShotAction->setIcon(shotIcon);
    connect(m_lpShotAction, &QAction::triggered, this, &FireShot::OnStartShot);

    m_lpQuitAction = new QAction(tr("&Quit"), this);
    QIcon quitIcon(":/icons/icon/menu-exit.png");
    m_lpQuitAction->setIcon(quitIcon);
    connect(m_lpQuitAction, &QAction::triggered, this, &FireShot::OnExitShot);
    ; // 退出按钮

    return 0;
}

