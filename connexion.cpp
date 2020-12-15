#include "connexion.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

connexion::connexion()
{

}
bool connexion::createconnect()
{
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projectf");
    db.setUserName("fourat");
    db.setPassword("fourat2A");

    if(db.open())
      {
        test=true;}


  return test;
}
