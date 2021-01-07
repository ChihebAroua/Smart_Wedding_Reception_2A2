#ifndef VEHICULES_H
#define VEHICULES_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include "QFileDialog"
#include "QTextBrowser"
#include "QPrinter"

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
  QSqlQueryModel * rechercher(QString a);
 QSqlQueryModel * afficherTriMarque(QString ch);
    QSqlQueryModel * afficher();
    void exporterpdf_empl(QTextBrowser *text);

private:
    QString Marque_v,Type_v;
    int id_v;
};




#endif // VEHICULES_H
