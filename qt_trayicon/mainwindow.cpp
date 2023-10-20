#include "mainwindow.h"

#include <QMenu>
#include <QSystemTrayIcon>


TrayIcon::TrayIcon(QObject *parent) : QSystemTrayIcon(parent)
{
    m_menu = new QMenu();

    auto* captureAction = new QAction(tr("&Take Screenshot"), this);

       auto* launcherAction = new QAction(tr("&Open Launcher"), this);

       auto* configAction = new QAction(tr("&Configuration"), this);

       auto* infoAction = new QAction(tr("&About"), this);


       QAction* quitAction = new QAction(tr("&Quit"), this);

       // recent screenshots
       QAction* recentAction = new QAction(tr("&Latest Uploads"), this);

       m_menu->addAction(captureAction);
       m_menu->addAction(launcherAction);
       m_menu->addSeparator();
       m_menu->addAction(recentAction);
       m_menu->addSeparator();
       m_menu->addAction(configAction);
       m_menu->addSeparator();

       setToolTip(QStringLiteral("FireShot"));

       setContextMenu(m_menu);
       QIcon icon = QIcon::fromTheme("flameshot-tray", QIcon(":/image/tv.png"));
       setIcon(icon);

}

