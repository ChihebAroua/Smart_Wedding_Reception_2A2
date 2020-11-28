#include "connection.h"
//first commit github
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("chiheb");//inserer nom de l'utilisateur
db.setPassword("23924440");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
