#include "taches.h"

taches::taches()
{   nom="";
    idp="";
    idt="";
    tache="";
    dated="";
    datef="";
    etat="";
    remarque="";

}
 taches::taches(QString n,QString ip,QString it,QString t,QString dd,QString df,QString e,QString r)
 {   nom=n;
     idp=ip;
     idt=it;
     tache=t;
     dated=dd;
     datef=df;
     etat=e;
     remarque=r;
 }
 bool taches::ajouter()
 { QSqlQuery query;
     query.prepare("insert into taches(nom,ID_employe,ID_tache,tache_a_realise,date_debut,date_fin,etat,remarque)""values (:nom,:ID_employe,:ID_tache,:tache_a_realise,:date_debut,:date_fin,:etat,:remarque)");
     query.bindValue(":nom",nom);
     query.bindValue(":ID_employe",idp);
     query.bindValue(":ID_tache",idt);
     query.bindValue(":tache_a_realise",tache);
     query.bindValue(":date_debut",dated);
     query.bindValue(":date_fin",datef);
     query.bindValue(":etat",etat);
      query.bindValue(":remarque",remarque);
     return query.exec();
 }
 QSqlQueryModel * taches::afficher()
 { QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from taches");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("id employé"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("id tache"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("tache à réalisé"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("date début"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("date fin"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("état"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("remarque"));

     return model ;

 }
 QSqlQueryModel * taches::afficher_combo()
 { QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select ID_tache from taches");

     return model ;}

 bool taches::supprimer(QString idt)
 {QSqlQuery query;
     query.prepare("Delete from TACHES where ID_TACHE = :ID_TACHE");
      query.bindValue(":ID_TACHE",idt);
      return query.exec();

 }
 bool taches::modifier()
 { QSqlQuery query;

     query.prepare("update  TACHES set nom='"+nom+"',ID_employe='"+idp+"',ID_tache='"+idt+"',tache_a_realise='"+tache+"',date_debut='"+dated+"',date_fin='"+datef+"',etat='"+etat+"',remarque='"+remarque+"' where ID_tache='"+idt+"'");
     return query.exec();
 }
 QSqlQueryModel * taches::chercher(QString variable,int n){

 QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();
if(n==1)
       {model1->setQuery("select * from taches where ID_tache LIKE '"+variable+"' " );


}
else if(n==2)
      { model1->setQuery("select * from taches where nom LIKE '"+variable+"' " );}
else if(n==3)
      { model1->setQuery("select * from taches where date_debut LIKE '"+variable+"' " );}
else if(n==4)
      { model1->setQuery("select * from taches where date_fin LIKE '"+variable+"' " );}
else if(n==5)
      { model1->setQuery("select * from taches where etat LIKE '"+variable+"' " );}


     model1->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
     model1->setHeaderData(1,Qt::Horizontal,QObject::tr("id employé"));
     model1->setHeaderData(2,Qt::Horizontal,QObject::tr("id tache"));
     model1->setHeaderData(3,Qt::Horizontal,QObject::tr("tache à réalisé"));
     model1->setHeaderData(4,Qt::Horizontal,QObject::tr("date début"));
     model1->setHeaderData(5,Qt::Horizontal,QObject::tr("date fin"));
     model1->setHeaderData(6,Qt::Horizontal,QObject::tr("état"));
     model1->setHeaderData(7,Qt::Horizontal,QObject::tr("remarque"));



     return model1;

 }
 QSqlQueryModel * taches::trier(int n)
 {   QSqlQuery query;
     QSqlQueryModel * model1=new QSqlQueryModel();
     if(n==1)
     {model1->setQuery("select * from taches order by nom "  );}
else if(n==2)
    { model1->setQuery("select * from taches order by ID_tache " );}

else if(n==4)
    { model1->setQuery("select * from taches order by etat " );}

     model1->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
     model1->setHeaderData(1,Qt::Horizontal,QObject::tr("id employé"));
     model1->setHeaderData(2,Qt::Horizontal,QObject::tr("id tache"));
     model1->setHeaderData(3,Qt::Horizontal,QObject::tr("tache à réalisé"));
     model1->setHeaderData(4,Qt::Horizontal,QObject::tr("date début"));
     model1->setHeaderData(5,Qt::Horizontal,QObject::tr("date fin"));
     model1->setHeaderData(6,Qt::Horizontal,QObject::tr("état"));
     model1->setHeaderData(7,Qt::Horizontal,QObject::tr("remarque"));

 return model1;}
