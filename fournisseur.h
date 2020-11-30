#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,QString);
    QString getid_four(){return id_four;}
    QString getnom_four(){return nom_four;}
    QString getadresse(){return adresse;}
    QString gettype_produit(){return type_produit;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);

    QSqlQueryModel* recherche(QString);

private:
      QString id_four,nom_four,adresse,num_tel,type_produit;


};

#endif // FOURNISSEUR_H
