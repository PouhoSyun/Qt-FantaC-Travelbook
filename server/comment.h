#ifndef COMMENT_H
#define COMMENT_H
#include<QVector>
class user;
class tag;

class comment
{
public:
    comment(user* a, QString b);
    user* User;
    QString s;
    QVector<tag*> Tags;
};

#endif // COMMENT_H
