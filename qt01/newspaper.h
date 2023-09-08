#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>
#include <QDebug>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name) : m_name(name) {}

    void Send() {
        // 通过emit调用信号接口发出信号
        emit NewPaper(m_name, 12);
    }

signals:
    // 用来发送信号的接口
    void NewPaper(const QString &name, int32_t id);

private:
    QString m_name;
};


class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}
    // 大丈夫剩余天地之间，不识其主而事之，是无智也！
    // 槽让你择名主而事之
    // 接收信号接口比较简单，只需要保证接收的参数信息顺序和发送的一致的情况下，参数个数小于等于发送接口的参数个数
    void ReceiverNewsPaper(const QString & name) {
        qDebug() << "Receiver Newspaper : " << name;
    }

private:

};


#endif // NEWSPAPER_H
