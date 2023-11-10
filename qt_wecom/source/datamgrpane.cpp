﻿#include "datamgrpane.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVariant>
#include "dynamiccard.h"
#include "public.h"
#include <QDebug>
#include "userpane.h"
#include <QGraphicsDropShadowEffect>
#include "userprofiles.h"
#include "appreciatedlg.h"
#include "carouselpane.h"


CDataMgrPane::CDataMgrPane(QWidget *parent) : QWidget(parent)
{
    m_widgetCards = NULL;
    m_widgetTopPic = NULL;
    m_pScrollArea = NULL;
    m_widgetContent = NULL;
    m_pAppreciateDlg = NULL;

    m_webView1 = NULL;
    m_webView2 = NULL;
    m_webView3 = NULL;
    m_webView4 = NULL;

    CreateAllChildWnd();
    InitTopPic();
    InitCtrl();
    InitEcharts();
    Relayout();
}

void CDataMgrPane::CreateAllChildWnd()
{
#define NEW_OBJECT(pObj, TYPE) \
    if (NULL == pObj) { pObj = new TYPE(this); }

    NEW_OBJECT(m_widgetContent, QWidget);
    NEW_OBJECT(m_widgetCards, QWidget);
    NEW_OBJECT(m_widgetTopPic, QWidget);
    NEW_OBJECT(m_pScrollArea, QScrollArea);
    NEW_OBJECT(m_pAppreciateDlg, AppreciateDlg);

    NEW_OBJECT(m_webView1, QWebEngineView);
    NEW_OBJECT(m_webView2, QWebEngineView);
    NEW_OBJECT(m_webView3, QWebEngineView);
    NEW_OBJECT(m_webView4, QWebEngineView);
}

void CDataMgrPane::InitCtrl()
{
    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式
    setProperty("form", "iconfontpane");

    m_pScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    m_pScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    m_pScrollArea->setWidgetResizable(true);
    m_pScrollArea->setWidget(m_widgetContent);
    m_widgetContent->setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式
    m_widgetContent->setProperty("form", "iconfontpane");
    m_pScrollArea->setStyleSheet(".QScrollArea{border-style:none;background:#FFFFFF}");

    m_widgetCards->setFixedHeight(125);
}

void CDataMgrPane::InitTopPic()
{
    m_widgetTopPic->setFixedHeight(500);

    QWidget *w = new QWidget(m_widgetTopPic);
    //QLabel *labImg = new QLabel(m_widgetTopPic);
    QLabel *labName = new QLabel(m_widgetTopPic);

    CarouselPane *labImg = new CarouselPane(m_widgetTopPic);
    QStringList listImgFileName;
    listImgFileName << ":/qss/res/img/about.jpg" << ":/qss/res/img/bg/2007013.jpg" << ":/qss/res/img/bg/2007028.jpg" << ":/qss/res/img/bg/2007033.jpg" << ":/qss/res/img/bg/2007276.jpg" ;
    labImg->SetImageList(listImgFileName);
    labImg->StartPlay();

    labName->setFixedHeight(30);
    labName->setText(tr("阿木大叔"));
    labName->setStyleSheet("font: 14px; color:#727272;");
    labName->setAlignment(Qt::AlignCenter);

    //labImg->setStyleSheet("border-radius:5px; border-image: url(:/qss/res/img/about.jpg);");

    m_widgetTopPic->setStyleSheet(".QWidget{background: #F6F6F6; border-radius:5px;}");

    QVBoxLayout *layoutMain = new QVBoxLayout(w);
    layoutMain->addWidget(labImg);
    layoutMain->addWidget(labName);
    //layoutMain->setMargin(8);

    {
        QVBoxLayout *layoutMain = new QVBoxLayout(m_widgetTopPic);
        layoutMain->addWidget(w);
        //layoutMain->setMargin(8);
    }


    // 设置边框阴影
    m_widgetTopPic->setAttribute(Qt::WA_TranslucentBackground, true);
    // 设置具体阴影
    QGraphicsDropShadowEffect *shadowBorder = new QGraphicsDropShadowEffect(m_widgetTopPic);
    shadowBorder->setOffset(0, 0);
    // 阴影颜色
    shadowBorder->setColor(QColor(0x44, 0x44, 0x44, 127));
    // 阴影半径
    shadowBorder->setBlurRadius(8);
    m_widgetTopPic->setGraphicsEffect(shadowBorder);
}

void CDataMgrPane::InitEcharts()
{
    m_webView1->load(QUrl("qrc:/html/html/echarts/Gauge1.html"));
    m_webView2->load(QUrl("qrc:/html/html/echarts/Gauge2.html"));
    m_webView3->load(QUrl("qrc:/html/html/echarts/Gauge4.html"));
    m_webView4->load(QUrl("qrc:/html/html/echarts/Gauge3.html"));

    m_webView1->setContextMenuPolicy(Qt::NoContextMenu);
    m_webView1->setFixedHeight(320);
    m_webView1->show();

    m_webView2->setContextMenuPolicy(Qt::NoContextMenu);
    m_webView2->setMinimumSize(630, 320);
    m_webView2->show();

    m_webView3->setContextMenuPolicy(Qt::NoContextMenu);
    m_webView3->setFixedHeight(320);
    m_webView3->show();

    m_webView4->setContextMenuPolicy(Qt::NoContextMenu);
    m_webView4->setFixedHeight(320);
    m_webView4->show();
}

void CDataMgrPane::Relayout()
{
    QHBoxLayout *layoutCards = new QHBoxLayout(m_widgetCards);

    CDynamicCard *pCard1 = new CDynamicCard(m_widgetCards);
    pCard1->SetValue(100001);
    pCard1->SetTitle(tr("点击次数"));
    pCard1->SetIcon(QChar(0xe662));
    pCard1->SetBgColor(QColor("#2D8CF0"));

    CDynamicCard *pCard2 = new CDynamicCard(m_widgetCards);
    pCard2->SetValue(999);
    pCard2->SetTitle(tr("收藏次数"));
    pCard2->SetIcon(QChar(0xe64c));
    pCard2->SetBgColor(QColor("#19BE6B"));

    CDynamicCard *pCard3 = new CDynamicCard(m_widgetCards);
    pCard3->SetValue(2233);
    pCard3->SetTitle(tr("转发次数"));
    pCard3->SetIcon(QChar(0xe665));
    pCard3->SetBgColor(QColor("#FF9900"));

    layoutCards->addWidget(pCard1);
    layoutCards->addStretch();
    layoutCards->addWidget(pCard2);
    layoutCards->addStretch();
    layoutCards->addWidget(pCard3);
    layoutCards->setSpacing(4);
    //layoutCards->setMargin(0);

    CUserPane *pUserPane = new CUserPane(this);
    pUserPane->setFixedSize(400, 470);

    QHBoxLayout *layoutUserPane = new QHBoxLayout();
    layoutUserPane->addWidget(pUserPane);
    layoutUserPane->addWidget(new UserProfiles(this));
    //layoutUserPane->addStretch();
    layoutUserPane->setSpacing(4);
    layoutUserPane->setContentsMargins(0, 0, 0, 0);

    QPushButton *btnAppreciate = new QPushButton(tr("赞赏"), this);
    btnAppreciate->setProperty("Circular", "true");
    connect(btnAppreciate, SIGNAL(clicked()), this, SLOT(OnBtnAppreciateClicked()));

    QHBoxLayout *layoutAppreciate = new QHBoxLayout();
    layoutAppreciate->addStretch();
    layoutAppreciate->addWidget(btnAppreciate);
    layoutAppreciate->addStretch();
    layoutAppreciate->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *layoutEChars = new QVBoxLayout();
    layoutEChars->addWidget(m_webView1);

    QHBoxLayout *layoutEChars34 = new QHBoxLayout();
    layoutEChars34->addWidget(m_webView3);
    layoutEChars34->addWidget(m_webView4);
    layoutEChars34->setSpacing(0);

    layoutEChars->addWidget(m_webView2);
    layoutEChars->addLayout(layoutEChars34);

    QVBoxLayout *layoutContent = new QVBoxLayout();
    layoutContent->addWidget(m_widgetTopPic);
    layoutContent->addWidget(m_widgetCards);
    layoutContent->addLayout(layoutEChars);
    layoutContent->addLayout(layoutUserPane);
    layoutContent->addLayout(layoutAppreciate);
    layoutContent->addStretch();
    layoutContent->setSpacing(8);
    //layoutContent->setMargin(4);
    m_widgetContent->setLayout(layoutContent);

    QVBoxLayout *layoutMain = new QVBoxLayout(this);
    layoutMain->addWidget(m_pScrollArea);
    layoutMain->setSpacing(0);
    layoutMain->setContentsMargins(0, 0, 0, 10);
    setLayout(layoutMain);
}

void CDataMgrPane::resizeEvent(QResizeEvent *event)
{
    int nCardsW = width() - 4 * 2 - 4 * 2;
    double fCardW = (double)nCardsW / 3;
    double fCardH =  fCardW / ((double)257 / 112);
    m_widgetCards->setFixedHeight(fCardH + 8);

    int nPicW = width() - 4 * 2 - 4 * 2;
    double fPicH =  nPicW / ((double)16 / 9);
    m_widgetTopPic->setFixedHeight(fPicH + 8);
}

void CDataMgrPane::OnBtnAppreciateClicked()
{
    QPushButton *btnAppreciate = (QPushButton *)sender();
    m_pAppreciateDlg->setModal(true);
    m_pAppreciateDlg->show();

    QPoint ptBtn = btnAppreciate->mapToGlobal(btnAppreciate->pos());
    QPoint point(ptBtn);
    point.setX(ptBtn.x() - btnAppreciate->pos().x() - m_pAppreciateDlg->width() / 2 + btnAppreciate->width() / 2);
    point.setY(ptBtn.y() - btnAppreciate->pos().y() - m_pAppreciateDlg->height());

    QRect rcStart, rcEnd;
    rcStart = QRect(point.x(), 0, m_pAppreciateDlg->width(), m_pAppreciateDlg->height());
    rcEnd = QRect(point.x(), point.y(), m_pAppreciateDlg->width(), m_pAppreciateDlg->height());

    QPropertyAnimation *animation = new QPropertyAnimation(m_pAppreciateDlg, "geometry");
    animation->setDuration(100);
    animation->setStartValue(rcStart);
    animation->setEndValue(rcEnd);
    animation->start();
}
