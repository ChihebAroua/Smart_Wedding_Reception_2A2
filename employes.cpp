#include "employes.h"

employes::employes()
{   nom="";
    prenom="";
    cin=0;
    id="";
    date_embauche="";
    departement="";
    salaire=0;

}
employes::employes(QString n,QString p,int c,QString i,QString e,QString d,float s)
{   nom=n;
    prenom=p;
    cin=c;
    id=i;
    date_embauche=e;
    departement=d;
    salaire=s;


}
bool employes::ajouter()
{ QSqlQuery query;
    QString cins=QString::number(cin);
    QString salaires=QString::number(salaire);
    query.prepare("insert  into employes(nom,prenom,cin,id,date_embauche,departement,salaire)""values (:nom,:prenom,:cin,:id,:date_embauche,:departement,:salaire)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin",cins);
    query.bindValue(":id",id);
    query.bindValue(":date_embauche",date_embauche);
    query.bindValue(":departement",departement);
    query.bindValue(":salaire",salaires);
    return query.exec();
}
QSqlQueryModel * employes::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from EMPLOYES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_d'embauche"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("département"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("salaire"));


    return model ;

}
QSqlQueryModel * employes::afficher_combo()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select id from EMPLOYES");

    return model ;

}


bool employes::supprimer(QString ide)
{QSqlQuery query;
    query.prepare("Delete from employes where ID= :id");
     query.bindValue(":id",ide);
     return query.exec();

}
bool employes::modifier()
{ QSqlQuery query;
    QString cins=QString::number(cin);
    QString salaires=QString::number(salaire);
    query.prepare("update  employes set nom='"+nom+"',prenom='"+prenom+"',cin='"+cins+"',id='"+id+"',date_embauche='"+date_embauche+"',departement='"+departement+"',salaire='"+salaires+"' where id='"+id+"'");
    return query.exec();
}


void employes::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select nom from employes ");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}

