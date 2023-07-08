#include "tele.h"
#include <QMap>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

tele::tele(QMap<QString,QString>* qm,QObject *parent)
    : QObject{parent}
{
    m_s=new QTcpServer(this);
    m_mp=qm;
    m_s->listen(QHostAddress::Any,port);

    connect(m_s,&QTcpServer::newConnection,this,[=](){
        m_tcp=m_s->nextPendingConnection();
        qDebug()<<"连上了\n";
        connect(m_tcp,&QTcpSocket::readyRead,this,[=](){
            QString data=m_tcp->readAll();
            emit(receive(data));
        });
    });
}

void tele::deliver(QString msg)
{
    if(msg.endsWith("loginreq")){
        msg=msg.first(msg.size()-8);
        if(m_mp->find(msg)==m_mp->end()){
            m_tcp->write(QString("unexistloginreq").toUtf8());
        }
        else{
            m_tcp->write(QString(m_mp->value(msg)+"loginreq").toUtf8());
        }
    }
    else if(msg.endsWith("register")){
        msg=msg.first(msg.size()-8);
        QStringList temp=msg.split("litchee");
        if(m_mp->find(temp[0])==m_mp->end()){
            m_mp->insert(temp[0],temp[1]);
        }
        else{
            m_tcp->write(QString("existregister").toUtf8());
        }
    }
}
