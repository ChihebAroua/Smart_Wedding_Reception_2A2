#include "fournisseur.h"

fournisseur::fournisseur()
{
    id_four="";
    nom_four="";
    adresse="";
    num_tel="";
    type_produit="";
}
fournisseur::fournisseur(QString i, QString n,QString a,QString nu,QString t){
    id_four=i;
    nom_four=n;
    adresse=a;
    num_tel=nu;
    type_produit=t;

}
bool fournisseur::ajouter(){

    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_FOUR,NOM_FOUR,ADRESSE,NUM_TEL,TYPE_PRODUIT)"
                  "VALUES(:id_four, :nom_four, :adresse, :num_tel, :type_produit)");
    query.bindValue(":id_four",id_four);
    query.bindValue(":nom_four",nom_four);
    query.bindValue(":adresse",adresse);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":type_produit",type_produit);
    return query.exec();
}
QSqlQueryModel * fournisseur::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id_four"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_four"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("type_produit"));
    return model;
}
bool fournisseur::supprimer(QString id_four){

    QSqlQuery query;
    query.prepare("delete from fournisseur where id_four = :id_four");
    query.bindValue(":id_four",id_four);
    return query.exec();
}
bool fournisseur::modifier(QString id_four){
    QSqlQuery query;
    query.prepare("update fournisseur set  nom_four= :nom_four ,adresse= :adresse ,num_tel= :num_tel ,type_produit= :type_produit where id_four = :id_four");
    query.bindValue(":id_four",id_four);
    query.bindValue(":nom_four",nom_four);
    query.bindValue(":adresse",adresse);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":type_produit",type_produit);
    return query.exec();


}
QSqlQueryModel *fournisseur::recherche(QString id_four)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from fournisseur where id_four LIKE '"+id_four+"%' or nom_four LIKE '"+id_four+"%' or adresse LIKE '"+id_four+"%'");


     model->setHeaderData(0,Qt::Horizontal, QObject::tr("id_four"));
     model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_four"));
     model->setHeaderData(2,Qt::Horizontal, QObject::tr("adresse"));

 return model;
}
