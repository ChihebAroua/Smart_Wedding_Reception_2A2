#ifndef LOCAL_H
#define LOCAL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class local
{
public:
    local();
    local(QString,QString,QString,float,int,int);
    QString getNom(){return nom;}
    QString getAdresse(){return adresse;}
    QString getDisponibilite(){return disponibilite;}
    float getPrix(){return prix;}
    int getCapacite(){return capacite;}
    int getIdl(){return idl;}
    bool ajouterlocal();
    QSqlQueryModel * afficherlocal();
    bool supprimerlocal(int);
    bool modifierlocal();

    QSqlQueryModel * trierlocal();

    QSqlQueryModel * chercherlocal(int);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

private:
QString nom,adresse,disponibilite;
float prix;
int capacite,idl;





};

#endif // LOCAL_H
