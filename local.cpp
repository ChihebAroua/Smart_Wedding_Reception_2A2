#include "local.h"



local::local()
{
    nom="";
    adresse="";
    disponibilite="";
    prix=0;
    capacite=0;
    idl=0;

}

local::local(QString n,QString a,QString d,float p,int c,int i)
{
   nom=n;
   adresse=a;
   disponibilite=d;
   prix=p;
   capacite=c;
   idl=i;
}

bool local::ajouterlocal()
{
    QSqlQuery query;
    QString prix1=QString::number(prix);
    QString capacite1=QString::number(capacite);
     QString idl1=QString::number(idl);
    query.prepare("INSERT INTO LOCAUX(NOM,ADRESSE,DISPONIBILITE,PRIX,CAPACITE,IDL) ""VALUES(:nom,:adresse,:disponibilite,:prix,:capacite,:idl)");
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":prix",prix1);
    query.bindValue(":capacite",capacite1);
    query.bindValue(":idl",idl1);
    return query.exec();


}


QSqlQueryModel *local::afficherlocal()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from locaux");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("localisation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prixx"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("capacitee"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("identifiant"));

       return model;


}


bool local::supprimerlocal(int idle)
{

    QSqlQuery query;
     QString idl1=QString::number(idle);
    query.prepare("Delete from locaux where IDL=:idl ");
    query.bindValue(":idl",idl1);
    return query.exec();

}


bool local::modifierlocal()
{

    QSqlQuery query;
    QString prix1=QString::number(prix);
    QString capacite1=QString::number(capacite);
     QString idl1=QString::number(idl);
    query.prepare("UPDATE locaux set nom=:nom,adresse=:adresse,disponibilite=:disponibilite,prix=:prix,capacite=:capacite where idl=:idl");
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":prix",prix1);
    query.bindValue(":capacite",capacite1);
    query.bindValue(":idl",idl1);
    return query.exec();

}


QSqlQueryModel * local::chercherlocal(int idle)
{

QSqlQuery query;
QSqlQueryModel * model=new QSqlQueryModel();

QString idl=QString::number(idle);



    model->setQuery("select * from locaux where IDL LIKE '"+idl+"'" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("localisation"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("capacitee"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("identifiant"));
    return model;

}

QSqlQueryModel *local::trierlocal()
{
    QSqlQueryModel * model=new QSqlQueryModel();
      QString idl1=QString::number(idl);
    model->setQuery("select * from locaux order by idl" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("localisation"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prixx"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("capacitee"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("identifiant"));
      return model;


}


void local::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select prix from locaux");
    while (q.next()) {
        QString refer = q.value(3).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}


//yayayaya









