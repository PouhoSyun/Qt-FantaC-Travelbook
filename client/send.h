#ifndef SEND_H
#define SEND_H

#include "login.h"

#include <QObject>
#include <QTcpSocket>

class Send:public QWidget{
    Q_OBJECT

public:
    Send(QTcpSocket* tcp,Login* parent);
    void sendmsg(QString msg);

    QString back_msg;
    QTcpSocket* m_tcp;
    Login* m_login;

signals:
    void receive(QString msg_rec);

public slots:
    void back();
};

#endif // SEND_H
