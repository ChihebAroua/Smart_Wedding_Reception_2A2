#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class employes
{
public:
    employes();
    employes(QString,QString,int,QString,QString,QString,float);
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getcin(){return cin;}
    QString getid(){return id;}
     QString getdate_embauche(){return date_embauche;}
      QString getdepartement(){return departement;}
    float getsalaire(){return salaire;}

    bool ajouter();
     bool modifier();
    bool supprimer(QString);
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_combo();
private:
    QString nom,prenom,id,date_embauche,departement;
    int cin;
    float salaire;

};

#endif // EMPLOYES_H
