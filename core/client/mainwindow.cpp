#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->port->setText("8899");
    ui->ip->setText("127.0.0.1");
    setWindowTitle("客户端");
    ui->disCon->setDisabled(true);

    m_tcp=new QTcpSocket;

    connect(m_tcp,&QTcpSocket::readyRead,this,[=](){
        QByteArray data=m_tcp->readAll();
        ui->rec->append("服务器发出："+data);
    });

    connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
        m_tcp->close();
        m_tcp->deleteLater();
        m_status->setText("未连接");
        ui->rec->append("断开与服务器的连接------");
        ui->connect->setDisabled(false);
        ui->disCon->setEnabled(false);
    });

    connect(m_tcp,&QTcpSocket::connected,this,[=](){
        m_status->setText("已连接");
        ui->rec->append("成功连接到服务器------");
        ui->connect->setDisabled(true);
        ui->disCon->setEnabled(true);
    });

    m_status=new QLabel;
    m_status->setText("未连接");
    ui->statusbar->addWidget(new QLabel("连接状态："));
    ui->statusbar->addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendMsg_clicked()
{
    QString msg=ui->msg->toPlainText();
    m_tcp->write(msg.toUtf8());
    ui->rec->append("客户端发出："+msg);
}

void MainWindow::on_connect_clicked()
{
    QString ip=ui->ip->text();
    unsigned short port=ui->port->text().toUShort();
    m_tcp->connectToHost(QHostAddress(ip),port);
}

void MainWindow::on_disCon_clicked()
{
    m_tcp->close();
    ui->connect->setEnabled(true);
    ui->disCon->setDisabled(true);
}

