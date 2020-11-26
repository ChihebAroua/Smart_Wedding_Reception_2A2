#include "connection.h"

connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("moenes");//inserer nom de l'utilisateur
db.setPassword("aqw789zsx456");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void connection::closeconnect()
{ db.close();}
