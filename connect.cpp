#include "connect.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
Connect::Connect()
{
 username="";
 password="";
}
Connect::Connect(QString user,QString pass)
{
 username=user;
 password=pass;
}
int Connect::login_user()
{QSqlQuery query;
    if(username=="admin" && password=="admin2020")
       { return 1;}

    else if (query.exec("SELECT *from EMPLOYES WHERE id like '"+password+"' and nom like '"+username+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count==1)
        {
            return 2;
        }
        else
            return 0;
    } else
        return 0;


}
