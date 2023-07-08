#include "comm.h"

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>

comm::comm(QTcpSocket *tcp, Login *parent)
    : QObject{parent}
{
    m_tcp=tcp;
    m_login=parent;

    QObject::connect(m_tcp,&QTcpSocket::readyRead,this,&comm::back);
}

void comm::sendmsg(QString m_msg)
{
    m_tcp->write(m_msg.toUtf8());
}

void comm::back()
{
    QByteArray data=m_tcp->readAll();
    back_msg=data;
    emit(receive(back_msg));
}
