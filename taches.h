#ifndef TACHES_H
#define TACHES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class taches
{
public:
    taches();
    taches(QString,QString,QString,QString,QString,QString,QString,QString);
 QString getnom(){return nom;};
 QString getide(){return idp;};
 QString getidt(){return idt;};
 QString gettache(){return tache;};
 QString getdated(){return dated;};
 QString getdatef(){return datef;};
 QString getetat(){return etat;};
 QString getremarque(){return remarque;};
  bool ajouter();
   bool modifier();
  QSqlQueryModel * afficher();
     bool supprimer(QString);
      QSqlQueryModel * chercher(QString);
        QSqlQueryModel * afficher_combo();
private:
       QString nom,idp,idt,tache,dated,datef,etat,remarque;


};

#endif // TACHES_H
