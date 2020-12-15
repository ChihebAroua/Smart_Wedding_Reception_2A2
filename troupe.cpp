#include "troupe.h"

troupe::troupe()
{
    nomt="";
     type="";
    disponibilitet="";
    prixt=0;
    duree=0;
    idt=0;

}

troupe::troupe(int i,QString n,QString t ,QString d,float p,int du)
{
   nomt=n;
   type=t;
   disponibilitet=d;
   prixt=p;
   duree=du;
   idt=i;
}

bool troupe::ajoutertroupe()
{
    QSqlQuery query;
    QString prixt1=QString::number(prixt);
    QString duree1=QString::number(duree);
    QString idt1=QString::number(idt);
    query.prepare("INSERT INTO troupe(IDT,NOMT,DISPONIBILITET,TYPE,PRIXT,DUREE) ""VALUES(:idt,:nomt,:disponibilitet,:type,:prixt,:duree)");
    query.bindValue(":nomt",nomt);
    query.bindValue(":type",type);
    query.bindValue(":disponibilitet",disponibilitet);
    query.bindValue(":prixt",prixt1);
    query.bindValue(":duree",duree1);
    query.bindValue(":idt",idt1);
    return query.exec();


}


QSqlQueryModel *troupe::affichertroupe()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from troupe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("duree"));
       return model;


}


 bool troupe::supprimertroupe(int ide)
{

    QSqlQuery query;
     QString idt1=QString::number(ide);
    query.prepare("Delete from troupe where IDT=:idt ");
    query.bindValue(":idt",idt1);
    return query.exec();

}




 bool troupe::modifiertroupe()
 {
     QSqlQuery query;
     QString prixt1=QString::number(prixt);
     QString duree1=QString::number(duree);
     QString idt1=QString::number(idt);
     query.prepare("UPDATE troupe set nomt=:nomt,disponibilitet=:disponibilitet,type=:type,prixt=:prixt,duree=:duree where idt=:idt");
     query.bindValue(":nomt",nomt);
     query.bindValue(":type",type);
     query.bindValue(":disponibilitet",disponibilitet);
     query.bindValue(":prixt",prixt1);
     query.bindValue(":duree",duree1);
     query.bindValue(":idt",idt1);
     return query.exec();

 }


 QSqlQueryModel * troupe::cherchertroupe(int ide)
 {

 QSqlQuery query;
 QSqlQueryModel * model1=new QSqlQueryModel();
 QString idt=QString::number(ide);


     model1->setQuery("select * from TROUPE where idt LIKE '"+idt+"'" );
     model1->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model1->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model1->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
     model1->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
     model1->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
     model1->setHeaderData(5,Qt::Horizontal,QObject::tr("duree"));

     return model1;

 }



 QSqlQueryModel *troupe::triertroupe()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     QString id1=QString::number(idt);
     model->setQuery("select * from troupe  order by idt" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("dispo"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("duree"));
       return model;
 }

 void troupe::statistique1(QVector<double>* ticks,QVector<QString> *labels)
 {   QSqlQuery q;
     int i=0;
     q.exec("select prixt from troupe");
     while (q.next()) {
         QString refer = q.value(4).toString();
         i++;
         *ticks<<i;
         *labels <<refer;
 }
 }

