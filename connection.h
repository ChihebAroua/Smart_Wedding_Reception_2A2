#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    bool createconnect();
    void closeconnect();
};

#endif // CONNECTION_H