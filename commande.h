#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class commande
{
public:
    commande();
    commande(QString,QString,QString,QString,QString,QString,QString,QString);
    QString getnum_cmd(){return num_cmd;}
    QString getid_four(){return id_four;}
    QString getref_produit(){return ref_produit;}
    QString getquantite(){return quantite;}
    QString getdate_cmd(){return date_cmd;}
    QString getprix_unitaire(){return prix_unitaire;}
    QString getTVA(){return TVA;}
    QString gettotale(){return totale;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierdec();



private:
    QString num_cmd,id_four,ref_produit,quantite,date_cmd,prix_unitaire,TVA,totale;
};

#endif // COMMANDE_H
