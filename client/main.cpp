#include "login.h"

#include <QApplication>
#include <QFile>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/images/login.css");
    qss.open(QIODevice::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();

    unsigned short port=8899;
    QString ip="127.0.0.1";
    QTcpSocket* all_tcp;
    all_tcp=new QTcpSocket;
    all_tcp->connectToHost(QHostAddress(ip),port);

    Login w(all_tcp);
    w.show();
    return a.exec();
}
