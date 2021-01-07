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
{QSqlQuery query,q;
    QString depC,depRH,depCG,depSA,depL;
    depC="client";
     depRH="RH";
      depCG="coordination general";
       depSA="achats";
        depL="logistique";
    int a=0;
    if(username=="admin" && password=="admin2020")
       { a=1;}

    else if (query.exec("SELECT *from EMPLOYES WHERE id like '"+password+"' and nom like '"+username+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
       q.exec("SELECT *from EMPLOYES WHERE id like '"+password+"' and nom like '"+username+"'");
        if(count==1)
        {
          if(q.next())
          {
              if(q.value(6).toString()=="client")
              {
                  a=2;
              }
              else if(q.value(6).toString()=="RH")
              {
                  a=3;
              }
              else if(q.value(6).toString()=="logistique")
              {
                  a=4;
              }
              else if(q.value(6).toString()=="achats")
              {
                  a=5;
              } else if(q.value(6).toString()=="coordination general")
              {
                  a=6;
              }

          }
        }

    }
    else
        a=0;
    return a;
}


