#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "mainwindow.h"
#include <QMap>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Button_min_clicked();

    void on_Button_close_clicked();

    void on_btnRegister_clicked();

    void on_btnregisterAccount_clicked();

    void on_btnRegisterCancel_clicked();

    void on_btnLogin_clicked();

    void deliver(QString msg);

private:
    Ui::Login *ui;
    mainWindow *m_mainWindow;
    void readUserInfo();
    QMap<QString, QString> m_userInfo;
    QTcpSocket *m_tcp;
    QString m_msg;
    QString back_msg;

    void* m_comm;
};
#endif // LOGIN_H
