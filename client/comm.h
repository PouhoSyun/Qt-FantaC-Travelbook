#ifndef COMM_H
#define COMM_H

#include "login.h"
#include <QObject>
#include <QTcpSocket>

class comm : public QObject
{
    Q_OBJECT
public:
    explicit comm(QTcpSocket* tcp,Login* parent);

    void sendmsg(QString msg);

    QString back_msg;
    QTcpSocket* m_tcp;
    Login* m_login;

signals:
    void receive(QString msg_rec);

public slots:
    void back();

signals:

};

#endif // COMM_H
