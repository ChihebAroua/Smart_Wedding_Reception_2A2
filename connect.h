#ifndef CONNECT_H
#define CONNECT_H

#include "QString"
class Connect
{
public:
    Connect();
    Connect(QString,QString);
    int login_user();
    QString username;
    QString password;
private:

};

#endif // CONNECT_H
