#include "commande.h"

commande::commande()
{
    num_cmd="";
    id_four="";
    ref_produit="";
    quantite="";
    date_cmd="";
    prix_unitaire="";
    TVA="";
    totale="";
}
commande::commande(QString n,QString i,QString r,QString q,QString d,QString p,QString tv,QString to){
    num_cmd=n;
    id_four=i;
    ref_produit=r;
    quantite=q;
    date_cmd=d;
    prix_unitaire=p;
    TVA=tv;
    totale=to;

}
bool commande::ajouter(){

    QSqlQuery query;
    query.prepare("INSERT INTO COMMANDE (NUM_CMD,ID_FOUR,REF_PRODUIT,QUANTITE,DATE_CMD,PRIX_UNITAIRE,TVA,TOTALE)"
                  "VALUES(:num_cmd, :id_four, :ref_produit, :quantite, :date_cmd, :prix_unitaire, :TVA, :totale)");
    query.bindValue(":num_cmd",num_cmd);
    query.bindValue(":id_four",id_four);
    query.bindValue(":ref_produit",ref_produit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":date_cmd",date_cmd);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":TVA",TVA);
    query.bindValue(":totale",totale);
    return query.exec();
}
QSqlQueryModel * commande::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from commande");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("num_cmd"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("id_four"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ref_produit"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("date_cmd"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("prix_unitaire"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("TVA"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("totale"));
    return model;
}
bool commande::supprimer(QString num_cmd){

    QSqlQuery query;
    query.prepare("delete from commande where num_cmd = :num_cmd");
    query.bindValue(":num_cmd",num_cmd);
    return query.exec();
}
bool commande::modifier(QString num_cmd){
    QSqlQuery query;
    query.prepare("update commande set id_four= :id_four ,ref_produit= :ref_produit ,quantite= :quantite ,date_cmd= :date_cmd ,prix_unitaire= :prix_unitaire ,TVA= :TVA ,totale= :totale where num_cmd=:num_cmd");
    query.bindValue(":num_cmd",num_cmd);
    query.bindValue(":id_four",id_four);
    query.bindValue(":ref_produit",ref_produit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":date_cmd",date_cmd);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":TVA",TVA);
    query.bindValue(":totale",totale);
    return query.exec();


}
QSqlQueryModel *commande::trier() //ml A-Z lieu // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM commande order by ref_produit ASC");
           q->exec();
           model->setQuery(*q);
           return model;
     //ml kbir l sghir
       /*    QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM permisconstruction order by codepostale DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;*/
}
QSqlQueryModel *commande::trierdec() //ml Z-A
{
    /*QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM commande order by ref_produit ASC");
           q->exec();
           model->setQuery(*q);
           return model;*/
     //ml kbir l sghir
           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM commande order by ref_produit DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}
