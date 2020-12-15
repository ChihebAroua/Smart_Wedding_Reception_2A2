#ifndef PACK_H
#define PACK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class pack
{
public:
    pack();
    pack(QString,QString,QString,QString,QString,QString,QString,int,float);
    QString get_nom();
    QString get_Id_pack();
    QString get_local();
    QString get_commande();
    QString get_troupe();
    QString get_vehicule();
    QString get_decoration();
    int  get_reduction();
    int  get_prix();
    bool ajouter_pack();
    bool modifier_pack();
    QSqlQueryModel * afficher_pack();
    bool supprimer_pack(QString);
    QSqlQueryModel *tri_pack(QString);
    QSqlQueryModel *recherche_pack(QString ,QString);
    private:
    QString nomP,idpack;
    QString local,commande,troupe,vehicule,decoration;
    int reduction;
    int  prixP;
};

#endif // PACK_H
