#include "user.h"

#include <QApplication>
#include"user.h"
#include"place.h"
#include"tag.h"
#include"route.h"
#include"comment.h"
#include"tele.h"
#include<QPushButton>
#include <QApplication>
#include <QMessageBox>
#include <QVBoxLayout>
#include<QDebug>
#include <QInputDialog>
#include <QMap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建用户
    user s;
    QMap<QString,QString> qm;

    tele* svr=new tele(&qm);

    // 创建主窗口
       QWidget window;
       window.setWindowTitle("读取用户输入示例");
       window.resize(600, 400);
       // 创建按钮
       QPushButton *  btn1=new QPushButton("修改昵称",&window);
       QPushButton *  btn2=new QPushButton("搜索地点",&window);
       QPushButton *  btn3=new QPushButton("查看收藏路线",&window);
       QPushButton *  btn4=new QPushButton("上传路线",&window);

       btn1->move(0,0);
       btn1->resize(150,50);
       btn2->move(200,0);
       btn2->resize(150,50);
       btn3->move(0,100);
       btn3->resize(150,50);
       btn4->move(200,100);
       btn4->resize(150,50);

       QObject::connect(btn1, &QPushButton::clicked, [&]() {
           bool ok;
           QString text = QInputDialog::getText(&window, "输入框", "请输入修改后的昵称:", QLineEdit::Normal, "", &ok);
           if (ok && !text.isEmpty()) {
               s.change_name(text);
               qDebug() << "您的昵称以修改为：" << text;
           }
       });
       QObject::connect(btn2, &QPushButton::clicked, [&]() {
           bool ok;
           QString text = QInputDialog::getText(&window, "输入框", "请输入地点:", QLineEdit::Normal, "", &ok);
           if (ok && !text.isEmpty()) {
               s.search_place(text);

           }
       });

       route* rou;
        int k=0;
        int inputValue=1;


           QObject::connect(btn4, &QPushButton::clicked, [&]() {
           bool ok;
           for(int i=0;i<inputValue;i++)
           {
           if(k==0)
           {
                inputValue = QInputDialog::getInt(nullptr, "输入整数", "请输入地点总数:", 0, -100, 100, 1, &ok);
                k=1;
           }
           QString text1 = QInputDialog::getText(&window, "输入框", "请输入地点", QLineEdit::Normal, "", &ok);
           QString text2 = QInputDialog::getText(&window, "输入框", "请输入地点介绍", QLineEdit::Normal, "", &ok);
           if (ok && !text1.isEmpty())
           {

               place* p=new place(text1,text2);
               p->PassingRoutes.push_back(rou);
               place_sum.push_back(p);
               rou->passing_place.push_back(p);
           }
           }
       });

       window.show();
    return a.exec();
}
