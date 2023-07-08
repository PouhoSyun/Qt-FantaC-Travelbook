#include "route.h"
#include <QMainWindow>
#include<QPushButton>
#include<QVBoxLayout>
route::route()
{

}
void route::like()
{
    like_number++;
    return;
}

void route:: addcomment(comment* c)
{
    comments.push_back(c);
}

void route::addtag(tag* t)
{
    Tag.push_back(t);
}

void route::create_route_window()
{

    QPushButton *button1 = new QPushButton("简介", route_window);
            QPushButton *button2 = new QPushButton(summary, route_window);
            QVBoxLayout *layout = new QVBoxLayout(route_window);
            layout->addWidget(button1);
            layout->addWidget(button2);
    for(int j=0;j<(passing_place).size();j++)
    {
        QPushButton *button = new QPushButton("路线" + QString::number(j), route_window);
                    route_window->centralWidget()->layout()->addWidget(button);


    }
}
void route::openButtonClicked()
{
    route_window->activateWindow();
}
