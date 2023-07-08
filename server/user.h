#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include "route.h"
#include"place.h"

extern QVector<place*> place_sum;//所有地点
QT_BEGIN_NAMESPACE
namespace Ui { class user; }
QT_END_NAMESPACE

class user : public QMainWindow
{
    Q_OBJECT

public:
    user(QWidget *parent = nullptr);
    ~user();

    QString account;//账号
    QString password;//密码
    QString name;//昵称
    QVector<route*> collect_routes;//收藏的路线
    QVector<route*> upload_routes;// 上传的路线
    QVector<place*> search_places;//搜索的路线
    void log_in(QString acc, QString pass);
    void change_name(QString nam);
    void search_place(QString s);//搜索地点
    void commend_route(QString st,route* r);//评论路线
    void collect_route(route* r);
    void peek_collect_route();
    void upload_route();
    void peek_upload_route();
    void change_route(route* s);
    void like(route* r);//点赞
    void collect(route* r);//收藏

private:
    Ui::user *ui;
};
#endif // USER_H
