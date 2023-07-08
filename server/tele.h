#ifndef TELE_H
#define TELE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

class tele : public QObject
{
    Q_OBJECT
public:
    explicit tele(QMap<QString,QString>* qm,QObject *parent = nullptr);
    QTcpServer *m_s;
    QTcpSocket *m_tcp;
    unsigned short port=8899;
    QString ip="127.0.0.1";
    QMap<QString,QString>* m_mp;

signals:
    void receive(QString msg);

private slots:
    void deliver(QString msg);

};

#endif // TELE_H
