#include "user.h"
#include "ui_user.h"
#include"route.h"
#include<QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
class place;
QVector<place*> place_sum;

user::~user()
{
    delete ui;
}

void user::change_name(QString nam)//修改昵称
        {
            name=nam;
        }

void user::search_place(QString s)//搜索地点
        {
            int k=0;
            QVector<place*>::const_iterator i;
            for(i=place_sum.begin();i!=place_sum.end();i++)
            {
                if(s==(*i)->PlaceName)
                {

                    QMainWindow *newWindow = new QMainWindow(this);
                    newWindow->setWindowTitle(s);
                    QPushButton *button1 = new QPushButton("简介", newWindow);
                            QPushButton *button2 = new QPushButton((*i)->Introduction, newWindow);
                            QVBoxLayout *layout = new QVBoxLayout(newWindow);
                            layout->addWidget(button1);
                            layout->addWidget(button2);
                    for(int j=0;j<((*i)->PassingRoutes).size();j++)
                    {
                        QPushButton *button = new QPushButton("路线" + QString::number(j), newWindow);
                                    newWindow->centralWidget()->layout()->addWidget(button);

                    }
                    newWindow->show();
                    k=1;

                }

            }
            if(k==0)
            {
                QDialog dialog1(this);
                       QVBoxLayout *layout = new QVBoxLayout(&dialog1);
                       QLabel *commentsLabel = new QLabel("未找到您搜索的地点", &dialog1);
                       layout->addWidget(commentsLabel);
                       dialog1.setLayout(layout);
                       dialog1.exec();
            }
            return;
        }
void user::commend_route(QString st,route* r)//评论路线
        {
            comment* Comment=new comment(this,st);
            (*r).comments.push_back(Comment);
            return;
        }
void user::collect_route(route* r)
        {
            collect_routes.push_back(r);
            return;
        }
void user::upload_route()
        {

        }
void user::like(route* r)//点赞
        {
            (*r).like_number++;
        }
void user:: collect(route* r)//收藏
        {
            collect_routes.push_back(r);
        }
user::user(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::user)
{
    ui->setupUi(this);

}
