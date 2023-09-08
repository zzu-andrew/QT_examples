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
        emit NewPaper(m_name);
    }

signals:
    void NewPaper(const QString &name);

private:
    QString m_name;
};


class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}

    void ReceiverNewsPaper(const QString & name) {
        qDebug() << "Receiver Newspaper : " << name;
    }

private:

};


#endif // NEWSPAPER_H
