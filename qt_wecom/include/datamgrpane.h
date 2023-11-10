#ifndef CDATAMGRPANE_H
#define CDATAMGRPANE_H

#include <QWidget>
#include <QtWidgets>
#include <QWebEngineView>

class AppreciateDlg;
class CDataMgrPane : public QWidget
{
    Q_OBJECT
public:
    explicit CDataMgrPane(QWidget *parent = 0);

private:
    void CreateAllChildWnd();
    void InitCtrl();
    void InitTopPic();
    void InitEcharts();
    void Relayout();

    void resizeEvent(QResizeEvent *event);

public slots:
    void OnBtnAppreciateClicked();

private:
    QScrollArea *m_pScrollArea;
    QWidget *m_widgetContent;
    QWidget *m_widgetTopPic;
    QWidget *m_widgetCards;
    AppreciateDlg *m_pAppreciateDlg;


    QWebEngineView *m_webView1;
    QWebEngineView *m_webView2;
    QWebEngineView *m_webView3;
    QWebEngineView *m_webView4;
};

#endif // CDATAMGRPANE_H
