#ifndef ROUTE_H
#define ROUTE_H
#include"place.h"
#include"comment.h"
#include"tag.h"
#include <QMainWindow>
class user;
class route
{
public:
    route();
    QMainWindow* route_window;
    int like_number;
    int collect_number;
    QString summary;
    QVector<place*> passing_place;
    QVector<comment*> comments;
    QVector<tag*> Tag;
    void like();
    void addcomment(comment* c);
    void addtag(tag* t);
    void create_route_window();
    void openButtonClicked();
};

#endif // ROUTE_H
