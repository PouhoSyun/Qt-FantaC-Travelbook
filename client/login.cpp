#include "login.h"
#include "comm.h"
#include "ui_login.h"
#include <QMovie>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QHostAddress>

Login::Login(QTcpSocket* all_tcp,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    m_tcp=all_tcp;

    comm* mm_comm=new comm(m_tcp,this);
    m_comm=mm_comm;

    connect((comm*)m_comm,&comm::receive,this,&Login::deliver);

    //label_top动画效果
    QMovie * movie = new QMovie(this);
    movie->setFileName(":/images/gifLabel.gif");
    movie->start();
    ui->label_top->setMovie(movie);

    m_mainWindow = new mainWindow;
}

Login::~Login()
{
    delete m_mainWindow;
    delete ui; 
}


void Login::on_Button_min_clicked()
{
    this->showMinimized();
}


void Login::on_Button_close_clicked()
{
    this->close();
}

void Login::on_btnRegister_clicked()
{
    if (ui->registerPassword->text() != ui->registerConfirmPassword->text())
    {
        QMessageBox::critical(this, "注册失败", "两次输入密码不一致");
        return;
    }
    ((comm*)m_comm)->sendmsg(ui->account->text()+"litchee"+ui->registerConfirmPassword->text()+"register");
}

void Login::on_btnregisterAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Login::on_btnRegisterCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Login::on_btnLogin_clicked()
{
    ((comm*)m_comm)->sendmsg(ui->account->text()+"loginreq");
    qDebug()<<"send"<<ui->account->text();
}

void Login::deliver(QString msg)
{
    qDebug()<<"receive"<<msg;
    if(msg.endsWith("loginreq")){
        msg=msg.first(msg.size()-8);
        if(msg=="unexist")
        {
            QMessageBox::critical(this, "登录失败", "用户不存在");
        }
        else if (msg != ui->password->text())
        {
            QMessageBox::critical(this, "登录失败", "密码错误");
        }
        else{
            m_mainWindow->show();
            this->close();
        }
    }
    else if(msg.endsWith("register")){
        msg=msg.first(msg.size()-8);
        if(msg=="exist"){
            QMessageBox::critical(this, "注册失败", "用户存在");
        }
        else{
            QMessageBox::information(this, "提示", "注册成功");
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

