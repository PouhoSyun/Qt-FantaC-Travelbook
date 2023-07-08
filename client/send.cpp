#include "send.h"

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>

Send::Send(QTcpSocket *tcp, Login *parent)
{
    m_tcp=tcp;
    m_login=parent;

    QObject::connect(m_tcp,&QTcpSocket::readyRead,this,&Send::back);
}

void Send::sendmsg(QString m_msg)
{
    m_tcp->write(m_msg.toUtf8());
}

void Send::back()
{
    QByteArray data=m_tcp->readAll();
    back_msg=data;
    emit(receive(back_msg));
}
