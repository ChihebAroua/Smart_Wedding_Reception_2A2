#ifndef VEHICULES_H
#define VEHICULES_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class Vehicules
{
public:
    Vehicules();
    Vehicules(int,QString,QString);
    QString getMarque_v();
    QString getType_v();
    int getID_v();
    bool ajouter();
   bool modifier(int d);
    bool supprimer(int);
    bool supprimerTout();
  void rechercher(QString a,QTableView *g);
 QSqlQueryModel * afficherTriMarque(QString);
    QSqlQueryModel * afficher();

private:
    QString Marque_v,Type_v;
    int id_v;
};




#endif // VEHICULES_H
