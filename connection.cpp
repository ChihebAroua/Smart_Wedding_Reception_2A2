#include "connection.h"
#include "QSqlDatabase"

//test git

connection::connection()
{

}
bool connection::createconnection(){

    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Gestion_achats");
    db.setUserName("helmi");
    db.setPassword("da7");

    if(db.open())
        test=true;
    return test;


}
