#include "m_electronique.h"
#include<QString>

#include<QTableView>
m_electronique::m_electronique()
{

}
m_electronique::m_electronique(int ref,QString type ,int prix, int voltage)
{   this->reference=ref;
    this->type=type;
    this->prix=prix;
    this->voltage=voltage;

}
int m_electronique::getRef(){return reference;}
QString m_electronique::getType(){return type;}
int m_electronique::getPrix(){return prix;}
int m_electronique::getVoltage(){return voltage;}

bool m_electronique::ajouter()
{QSqlQuery query;
  QString res=QString::number(reference);
  query.prepare("insert into m_electronique (refs,type_e,prix,voltage) values (:refs,:type_e,:prix,:voltage)");
  query.bindValue(":refs",res);
  query.bindValue(":type_e",type);
  query.bindValue(":prix",prix);
  query.bindValue(":voltage",voltage);
  return query.exec();
}

bool m_electronique::supprimer(int ref)
{ QSqlQuery query;
   QString res=QString::number(ref);
   query.prepare("delete from m_electronique where refs=:refs");
   query.bindValue(":refs",res);
  return query.exec();}

bool m_electronique::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from m_electronique ");

  return query.exec();
}

QSqlQueryModel * m_electronique::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from m_electronique");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("voltage"));

    return model;

}
QSqlQueryModel * m_electronique::afficherTriType()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from m_electronique ORDER BY type_e ASC");// asc assendant dsc descendant
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("voltage"));
    return model;

}
void m_electronique::rechercher(QString a,QTableView *g)
{ {QSqlQuery qry;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         qry.prepare("select * from m_electronique where refs like'%"+a+"%' OR type_e like '%"+a+"%' OR prix like '%"+a+"%' OR voltage like '%"+a+"%'");
                     qry.exec();
                 m->setQuery(qry);
         g->setModel(m);


     }}
bool m_electronique::modifier(int d)
{QSqlQuery query ;
    query.prepare("update m_electronique set refs=?,type_e=?,prix=?,voltage=? where refs=?");
    query.bindValue(0,reference);
    query.bindValue(1,type);
    query.bindValue(2,prix);
    query.bindValue(3,voltage);
    query.bindValue(4,d);
    if(query.exec())
        return true;
    return false;
}

void m_electronique::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select refs from m_electronique");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}


