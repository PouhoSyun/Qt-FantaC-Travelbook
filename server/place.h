#ifndef PLACE_H
#define PLACE_H
#include<QVector>
#include <QMainWindow>
class user;
class route;
class tag;
class place
{
public:
    place(QString name, QString introduction);
    QString PlaceName;
    QString Introduction;
    QVector<route*> PassingRoutes;
    QVector<tag*> Tags;
    void change_introduction(QString s);

    void add_route(route* r);

    void add_tag(tag* t);
};

#endif // PLACE_H
