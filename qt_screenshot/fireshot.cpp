//
// Created by wangyz38535 on 2023/9/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QAction>

#include "fireshot.h"
#include "utils/spdlog_wrapper.h"

FireShot::FireShot(QWidget *parent) : QDialog(parent) {

}

FireShot::~FireShot() {
    SPD_FLUSH();
}
int32_t FireShot::CreateActions() {

    m_lpSettingAction = new QAction(tr("&Settings"), this);
    QIcon settingIcon(":/images/menu-setting.png");
    m_lpShotAction;  // 截图按钮
    m_lpQuitAction; // 退出按钮

    return 0;
}

