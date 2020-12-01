#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,float);

    QString get_nom();
    QString get_prenom();
    QString get_CIN();
    QString get_pack();
    QString get_date();
    QString get_heure();
    float  get_avance();
    QString get_local();
    QString get_commande();
    QString get_troupe();
    QString get_vehicule();
    QString get_decoration();
    bool ajouter_client();
    bool modifier_client();
    QSqlQueryModel * afficher_client();
    QSqlQueryModel *tri_client(QString);
    QSqlQueryModel *recherche_client(QString ,QString);

    bool supprimer_client(QString);
    private:
    QString nomC;
    QString prenomC;
    QString CIN;
    QString packC;
    QString dateC;
    QString heureC;
    float AvanceC;
    QString localC;
    QString troupeC;
    QString DecorationC;
    QString vehiculeC;
    QString commandeC;




};

#endif // CLIENT_H
