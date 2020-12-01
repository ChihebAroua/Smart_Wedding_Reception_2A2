#include "connexion.h"
#include <QSqlDatabase>
connexion::connexion()
{

}
bool connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2A");
    db.setUserName("fourat");
    db.setPassword("ess2020");

    if(db.open())
        test=true;


    return test;
}
