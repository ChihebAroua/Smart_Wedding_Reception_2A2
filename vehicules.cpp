#include "vehicules.h"
#include<QString>

#include<QTableView>
Vehicules::Vehicules()
{}

Vehicules::Vehicules(int id_v,QString Marque_v ,QString Type_v)
{   this->id_v=id_v;
    this->Marque_v=Marque_v;
    this->Type_v=Type_v;

}
int Vehicules::getID_v(){return id_v;}
QString Vehicules::getMarque_v(){return Marque_v;}
QString Vehicules::getType_v(){return Type_v;}


bool Vehicules::ajouter()
{QSqlQuery query;
  QString res=QString::number(id_v);
  query.prepare("insert into vehicules (id_v,Marque_v,type_v) values (:id_v,:Marque_v,:type_v)");
  query.bindValue(":id_v",res);
  query.bindValue(":Marque_v",Marque_v);
  query.bindValue(":type_v",Type_v);
  return query.exec();
}

bool Vehicules::supprimer(int id)
{ QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("delete from Vehicules where id_v=:id");
   query.bindValue(":id",res);
  return query.exec();}

bool Vehicules::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from Vehicules ");

  return query.exec();
}

QSqlQueryModel * Vehicules::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Vehicules");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));

    return model;

}
QSqlQueryModel * Vehicules::afficherTriMarque(QString ch)
{
     QSqlQueryModel * model=new QSqlQueryModel();
        if(ch=="id")
               {
                   model->setQuery("select * from Vehicules  order by id_v" );
               }
               else if(ch=="type")
               {
                   model->setQuery("select * from Vehicules  order by type_v" );
               }
               else if(ch=="marque")
                   {

                   model->setQuery("select * from Vehicules  order by marque_v" );
                          }



        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));

        return model;


}
void Vehicules::rechercher(QString a,QTableView *g)
{ {QSqlQuery qry;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         qry.prepare("select * from vehicules where id_v like'%"+a+"%' OR type_v like '%"+a+"%' OR marque_v like '%"+a+"%'");
                     qry.exec();
                 m->setQuery(qry);
         g->setModel(m);


     }}
bool Vehicules::modifier(int d)
{QSqlQuery query ;
    query.prepare("update vehicules set id_v=?,type_v=?,marque_v=? where id_v=?");
    query.addBindValue(id_v);
    query.addBindValue(Marque_v);
    query.addBindValue(Type_v);
    query.addBindValue(d);
    if(query.exec())
        return true;
    return false;
}




