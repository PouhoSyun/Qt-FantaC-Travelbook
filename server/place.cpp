#include "place.h"
#include <QMainWindow>
#include<QPushButton>
#include<QVBoxLayout>
#include"route.h"
place::place(QString name, QString introduction)
{
    PlaceName=name;
    Introduction=introduction;
}
void place::change_introduction(QString s)
{
    Introduction=s;
    return;
}

void place::add_route(route* r)
{
    PassingRoutes.push_back(r);
}

void place::add_tag(tag* t)
{
    Tags.push_back(t);
}



