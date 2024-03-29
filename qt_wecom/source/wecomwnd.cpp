﻿#include "wecomwnd.h"
#include "ui_wecomwnd.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QMediaPlayer>
//#include <QMediaPlaylist>
#include "navpane.h"
#include "pushbuttonex.h"
#include "iconhelper.h"
#include "logindlg.h"
#include "msgpane.h"
#include "msgqueue.h"
#include "contactspane.h"
#include "weatherpane.h"
#include "clockpane.h"
#include "incofontpane.h"
#include "tipwidget.h"
#include "catpane.h"
#include "notificationpane.h"
#include "component.h"
#include "datamgrpane.h"


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

WeComWnd::WeComWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeComWnd)
{
    ui->setupUi(this);

    m_pStackedWidget = NULL;
    m_pNavPane = NULL;
    m_eMainTabTitle = TABTITLE_MESSAGE;

    m_widgetTitle = NULL;
    m_btnMusic = NULL;
    m_labelMusicName = NULL;
    m_btnMin = NULL;
    m_btnMax = NULL;
    m_btnClose = NULL;
    m_trayIcon = NULL;
    m_systemTrayMenu = NULL;
    m_Logindlg = NULL;

    m_player = NULL;

    m_pMsgPane = NULL;
    m_pContactsPane = NULL;
    m_pWeatherPane = NULL;

    m_bMaxWindows = false;
    m_bMusicPlay = false;
    m_strMusicName = tr("成都-赵雷");

    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    setProperty("form", "mainwnd");
    setProperty("canMove", "true");

    NotificationMgr::GetInstance()->Init(this);

    CreateAllChildWnd();
    InitCtrl();
    InitSolts();
    Relayout();
    ChangePage();
    InitTrayIcon();


}

WeComWnd::~WeComWnd()
{
    delete ui;

    MSGQUEUE->ExitInstance();
}

void WeComWnd::Login()
{
    if (m_Logindlg)
    {
        m_Logindlg->show();
        m_Logindlg->setModal(true);
    }
}

void WeComWnd::CreateAllChildWnd()
{
#define NEW_OBJECT(pObj, TYPE) \
    if (NULL == pObj) { pObj = new TYPE(this); }

    NEW_OBJECT(m_pStackedWidget, QStackedWidget);
    NEW_OBJECT(m_pNavPane, NavPane);
    NEW_OBJECT(m_widgetTitle, QWidget);
    NEW_OBJECT(m_btnMusic, CPushButtonEx);
    NEW_OBJECT(m_btnMin, CPushButtonEx);
    NEW_OBJECT(m_btnMax, CPushButtonEx);
    NEW_OBJECT(m_btnClose, CPushButtonEx);
    NEW_OBJECT(m_trayIcon, QSystemTrayIcon);
    NEW_OBJECT(m_systemTrayMenu, QMenu);
    NEW_OBJECT(m_Logindlg, CLoginDlg);
    NEW_OBJECT(m_labelMusicName, QLabel);
    NEW_OBJECT(m_player, QMediaPlayer);

    NEW_OBJECT(m_pMsgPane, CMsgPane);
    NEW_OBJECT(m_pContactsPane, CContactsPane);
    NEW_OBJECT(m_pWeatherPane, CWeatherPane);
}

void WeComWnd::InitCtrl()
{
    m_pNavPane->setFixedWidth(60);

    QLabel *label1 = new QLabel();
    label1->setStyleSheet("background-image: url(:/qss/res/img/compass_01.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label2 = new QLabel();
    label2->setStyleSheet("background-image: url(:/qss/res/img/compass_02.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label3 = new QLabel();
    label3->setStyleSheet("background-image: url(:/qss/res/img/compass_03.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label4 = new QLabel();
    label4->setStyleSheet("background-image: url(:/qss/res/img/File Vault.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label5 = new QLabel();
    label5->setStyleSheet("background-image: url(:/qss/res/img/Folder Actions Setup.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label6 = new QLabel();
    label6->setStyleSheet("background-image: url(:/qss/res/img/Generic Application.png);background-position:center;background-repeat:no-repeat;");

    QLabel *label7 = new QLabel();
    label7->setStyleSheet("background-image: url(:/qss/res/img/Generic Network.png);background-position:center;background-repeat:no-repeat;");

    m_pStackedWidget->insertWidget(TABTITLE_MESSAGE, m_pMsgPane);
    m_pStackedWidget->insertWidget(TABTITLE_CONTACTS, new CDataMgrPane(this));  m_pContactsPane->hide();
    m_pStackedWidget->insertWidget(TABTITLE_CALENDAR, new CComponent(this));
    m_pStackedWidget->insertWidget(TABTITLE_WORKSPACE, new CClockPane(this));
    m_pStackedWidget->insertWidget(TABTITLE_WEDOC, new CIncoFontPane(this));
    m_pStackedWidget->insertWidget(TABTITLE_WEDRIVE, m_pWeatherPane);
    m_pStackedWidget->insertWidget(TABTITLE_MEETING, new CCatPane(this));

    m_btnMusic->setFixedSize(36, 26);
    m_btnMin->setFixedSize(36, 26);
    m_btnMax->setFixedSize(36, 26);
    m_btnClose->setFixedSize(36, 26);
    IconHelper::SetIcon(m_btnMusic, QChar(0xe674), 15);
    IconHelper::SetIcon(m_btnMin, QChar(0xe7d8), 15);
    IconHelper::SetIcon(m_btnMax, QChar(0xe693), 15);
    IconHelper::SetIcon(m_btnClose, QChar(0xe64f), 15);
    m_btnMusic->setProperty("toolbar", "true");
    m_btnMin->setProperty("toolbar", "true");
    m_btnMax->setProperty("toolbar", "true");
    m_btnClose->setProperty("toolbar_close", "true");
    m_labelMusicName->setText(tr("成都-赵雷"));
    m_labelMusicName->hide();
    m_labelMusicName->setFixedWidth(50);
    m_labelMusicName->setStyleSheet("color:#ACACAC;");

    QString fileName = QCoreApplication::applicationDirPath();

//    QMediaPlaylist *medialist= new QMediaPlaylist;
//    medialist->addMedia(QUrl::fromLocalFile(QString("%1/res/music/chengdu.mp3").arg(fileName)));
//    medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
//    m_player->setPlaylist(medialist);
//    m_player->setVolume(50);

    QTimer *pTimer = new QTimer(this);
    connect(pTimer,  SIGNAL(timeout()),  this,  SLOT(OnScrollCaption()));
    pTimer->start(1000);

    AUTOTIP->setParent(this);   //设置实例的引用者
    m_Logindlg->hide();
}

void WeComWnd::InitSolts()
{
    connect(m_pNavPane, SIGNAL(SignalTabChange(EMainTabTitle)), this, SLOT(OnTabChange(EMainTabTitle)));
    connect(this, SIGNAL(SignalTabChange(EMainTabTitle)), m_pNavPane, SLOT(OnMainTabChange(EMainTabTitle)));
    connect(this, SIGNAL(SignalTabChange(EMainTabTitle)), m_pWeatherPane, SLOT(OnMainTabChange(EMainTabTitle)));
    connect(m_Logindlg, SIGNAL(SignalLoginFinish()), this, SLOT(show()));

    connect(m_btnMin, SIGNAL(clicked()), this, SLOT(OnMinWindows()));
    connect(m_btnMax, SIGNAL(clicked()), this, SLOT(OnMaxWindows()));
    connect(m_btnClose, SIGNAL(clicked()), this, SLOT(OnClose()));
    connect(m_btnMusic, SIGNAL(clicked()), this, SLOT(OnOpenMusic()));
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
                SLOT(OnSystemTrayIconActivated(QSystemTrayIcon::ActivationReason)));
}

void WeComWnd::Relayout()
{
    QHBoxLayout *layoutTitle = new QHBoxLayout(m_widgetTitle);
    layoutTitle->addStretch();
    layoutTitle->addWidget(m_labelMusicName);
    layoutTitle->addWidget(m_btnMusic);
    layoutTitle->addWidget(m_btnMin);
    layoutTitle->addWidget(m_btnMax);
    layoutTitle->addWidget(m_btnClose);
    layoutTitle->setSpacing(0);
    //layoutTitle->setMargin(0);

    QVBoxLayout *layoutMainPane = new QVBoxLayout();
    layoutMainPane->addWidget(m_widgetTitle);
    layoutMainPane->addWidget(m_pStackedWidget);
    layoutMainPane->setSpacing(0);
    //layoutMainPane->setMargin(0);

    QHBoxLayout *layoutMain = new QHBoxLayout();
    layoutMain->addWidget(m_pNavPane);
    layoutMain->addLayout(layoutMainPane);
    layoutMain->setSpacing(0);
    //layoutMain->setMargin(1);

    setLayout(layoutMain);
}

void WeComWnd::ChangePage()
{
    m_pStackedWidget->setCurrentIndex(m_eMainTabTitle);

    update();

    emit SignalTabChange(m_eMainTabTitle);
}

void WeComWnd::UpdateCtrlText()
{
    if (m_bMaxWindows)
    {
        m_btnMax->setToolTip(tr("向下还原"));
        IconHelper::SetIcon(m_btnMax, QChar(0xe64e), 15);
        setProperty("canMove", "false");
    }
    else
    {
        m_btnMax->setToolTip(tr("最大化"));
        IconHelper::SetIcon(m_btnMax, QChar(0xe693), 15);
        setProperty("canMove", "true");
    }
}

void WeComWnd::InitTrayIcon()
{
    QAction *pRest = new QAction(tr("休息一下"), m_systemTrayMenu);
    QAction *pGoOffwork = new QAction(tr("下班了"), m_systemTrayMenu);

    QMenu *pChildRest = new QMenu(m_systemTrayMenu);
    pChildRest->setTitle(tr("休息一下"));
    pChildRest->addAction(pRest);
    pChildRest->addAction(pGoOffwork);

    QAction *restoreAction = new QAction(tr("打开主窗口"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    QAction *quitAction = new QAction(tr("退出"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_systemTrayMenu->addMenu(pChildRest);
    m_systemTrayMenu->addSeparator();
    m_systemTrayMenu->addAction(restoreAction);
    m_systemTrayMenu->addAction(quitAction);

    m_trayIcon->setContextMenu(m_systemTrayMenu);
    m_trayIcon->setIcon(QIcon(":/qss/res/WeComCopy_Tray.png"));  //设置托盘图标显示
    m_trayIcon->setToolTip(tr("企业微信:逍遥子")); //显示提示信息
    m_trayIcon->show();
}

void WeComWnd::mouseDoubleClickEvent( QMouseEvent *event )
{
    if(!m_widgetTitle->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        return;

    OnMaxWindows();
}

void WeComWnd::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);         // 创建画家对象
    painter.setRenderHint(QPainter::Antialiasing, true); // 反走样

    QRect rcClient = rect();

    if (TABTITLE_MESSAGE == m_eMainTabTitle /*|| TABTITLE_CONTACTS == m_eMainTabTitle*/)
    {
        QRect rcClientLeft(rcClient);
        rcClientLeft.setRight(m_pNavPane->width() + 250);
        rcClientLeft.setTop(rcClientLeft.top() + 1);
        rcClientLeft.setBottom(rcClientLeft.bottom() - 1);
        rcClientLeft.setLeft(rcClientLeft.left() + m_pNavPane->width());

        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor("#E6E8EB"));
        painter.drawRect(rcClientLeft);

        QRect rcClientRight(rcClient);
        rcClientRight.setRight(rcClient.right() - 1);
        rcClientRight.setTop(rcClientLeft.top());
        rcClientRight.setBottom(rcClientLeft.bottom());
        rcClientRight.setLeft(rcClientLeft.right());

        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor("#F2F3F5"));
        painter.drawRect(rcClientRight);

        QPen pen(QColor("#D4D6D9"));
        painter.setPen(pen);
        painter.drawLine(rcClientLeft.topRight(), rcClientLeft.bottomRight());
    }
//    else if (TABTITLE_WORKSPACE == m_eMainTabTitle)
//    {
//        painter.setPen(Qt::NoPen);
//        painter.setBrush(QColor("#5BB3E3"));
//        painter.drawRect(rcClient);
//    }
}

void WeComWnd::OnTabChange( EMainTabTitle eMainTabTitle )
{
    if (m_eMainTabTitle == eMainTabTitle)
        return;

    m_eMainTabTitle = eMainTabTitle;

    ChangePage();
}

void WeComWnd::OnMinWindows()
{
    setWindowState(Qt::WindowMinimized);
    update();
}

void WeComWnd::OnMaxWindows()
{
    m_bMaxWindows = !m_bMaxWindows;

    if (m_bMaxWindows)
        setWindowState(Qt::WindowMaximized);
    else
        setWindowState(Qt::WindowNoState);

    UpdateCtrlText();
    update();
}

void WeComWnd::OnClose()
{
    hide();
}

void WeComWnd::OnOpenMusic()
{
    m_bMusicPlay = !m_bMusicPlay;

    if (m_bMusicPlay)
    {
        m_player->play();

        IconHelper::SetIcon(m_btnMusic, QChar(0xe678), 15);
        m_labelMusicName->show();
    }
    else
    {
        m_player->pause();
        IconHelper::SetIcon(m_btnMusic, QChar(0xe674), 15);
        m_labelMusicName->hide();
    }
}

void WeComWnd::OnScrollCaption()
{
    static int nPos = 0;

    // 当截取的位置比字符串长时，从头开始
    if (nPos > m_strMusicName.length())
        nPos = 0;

    m_labelMusicName->setText(m_strMusicName.mid(nPos));
    nPos++;
}

void WeComWnd::OnSystemTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
        showNormal();   //系统托盘中的图标被单击
    else if(reason == QSystemTrayIcon::DoubleClick)
        showNormal();   //系统托盘中的图标被双击
}
