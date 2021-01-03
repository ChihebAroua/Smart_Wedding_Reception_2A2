#include "client.h"
#include <QMessageBox>
#include <QDebug>
Client::Client()
{
     nomC="";
     prenomC="";
     CIN="";
     packC="";
     dateC="";
     heureC="";
     AvanceC=0;
     localC="";
     troupeC="";
     DecorationC="";
     vehiculeC="";
     commandeC="";
}
Client::Client(QString nomC,QString prenomC,QString CIN,QString packC,QString dateC,QString heureC,QString localC,QString troupeC,QString decorationC,QString vehiculeC,QString commandeC,float avanceC)
{
    this->nomC=nomC;
     this->prenomC=prenomC;
     this->CIN=CIN;
    this-> packC=packC;
     this->dateC=dateC;
    this-> heureC=heureC;
    this-> AvanceC=avanceC;
    this-> localC=localC;
     this->troupeC=troupeC;
     this->DecorationC=decorationC;
     this->vehiculeC=vehiculeC;
     this->commandeC=commandeC;
}
QString Client::get_nom(){return nomC;}
QString Client::get_prenom(){return prenomC;}
QString Client::get_CIN(){return CIN;}
QString Client::get_pack(){return packC;}
QString Client::get_date(){return dateC;}
QString Client::get_heure(){return heureC;}
float  Client::get_avance(){return AvanceC;}
QString Client::get_local(){return localC;}
QString Client::get_commande(){return commandeC;}
QString Client::get_troupe(){return troupeC;}
QString Client::get_vehicule(){return vehiculeC;}
QString Client::get_decoration(){return DecorationC;}
 bool Client::ajouter_client()
 {
     QSqlQuery query,q;
   QString  localp, commandep,vehiculep,troupep,decorationp;
     QString avance= QString::number(AvanceC);
     query.prepare("INSERT INTO clients(nom, prenom,cin,pack,DATEM,heure,local, commande, vehicule, decoration, troupe, avance)"
                   "VALUES (:nom, :prenom,:cin,:pack,:date,:heure,:local, :commande, :vehicule, :decoration, :troupe, :avance)");

     query.bindValue(":nom",nomC);
     query.bindValue(":prenom",prenomC);
     query.bindValue(":cin",CIN);
     query.bindValue(":pack",packC);
     query.bindValue(":date",dateC);
  query.bindValue(":heure",heureC);
q.bindValue(":PACK",packC);
query.bindValue(":oui","oui");
    if(query.exec("SELECT *FROM PACKS WHERE IDPACK=:PACK"))
    { QMessageBox::information(nullptr,QObject::tr("exec"),QObject::tr("exec te5dem\n"
                                                                                   "\nClick Cancel to exist."),QMessageBox::Cancel);
        /*if(q.next())
        {QMessageBox::information(nullptr,QObject::tr("next"),QObject::tr("next te5dem\n"
                                                                          "\nClick Cancel to exist."),QMessageBox::Cancel);*/
localp      = q.value(4).toString();
commandep   = q.value(5).toString();
vehiculep   = q.value(6).toString();
decorationp = q.value(7).toString();
troupep     = q.value(8).toString();
//QDebug() << localp << commandep <<vehiculep <<decorationp <<troupep;
if(q.exec("SELECT *FROM PACKS WHERE IDPACK=:PACK AND LOCAL=:oui "))
     query.bindValue(":local",localC);
  else if(localp=="non")
    query.bindValue(":local","NULL");
if(commandep=="oui")
     query.bindValue(":commande",commandeC);
 else if(commandep=="non")
    query.bindValue(":commande","NULL");
if(vehiculep=="oui")
query.bindValue(":vehicule",vehiculeC);
    else if(vehiculep=="non")
query.bindValue(":vehicule","NULL");
if(troupep=="oui")
      query.bindValue(":troupe",troupeC);
    else if(troupep=="non")
  query.bindValue(":troupe","NULL");
if(decorationp=="oui")
query.bindValue(":decoration",DecorationC);
     else if(decorationp=="non")
    query.bindValue(":decoration","NULL");
    //}
    }

     query.bindValue(":avance",avance);
     return query.exec();
 }
 QSqlQueryModel * Client::afficher_client()
 {
  QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from clients");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("Pack"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Heure"));
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("Local"));
  model->setHeaderData(7,Qt::Horizontal,QObject::tr("Troupe"));
  model->setHeaderData(8,Qt::Horizontal,QObject::tr("Vehicule"));
  model->setHeaderData(9,Qt::Horizontal,QObject::tr("Decoration"));
  model->setHeaderData(10,Qt::Horizontal,QObject::tr("Commande"));
  model->setHeaderData(11,Qt::Horizontal,QObject::tr("Avance"));

  return model;
 }
 bool Client::supprimer_client(QString cin)
 {
     QSqlQuery query;
     query.prepare("Delete from clients where cin = :cin");
     query.bindValue(":cin",cin);
     return query.exec();
 }
 bool Client::modifier_client()
 {
     QSqlQuery query;

     QString avance= QString::number(AvanceC);
    query.prepare("UPDATE  clients set nom=:nom, prenom=:prenom,pack=:pack,DATEM=:date,heure=:heure,local=:local, commande=:commande, vehicule=:vehicule, decoration=:decoration, troupe=:troupe, avance=:avance WHERE CIN=:cin")  ;
    query.bindValue(":nom",nomC);
    query.bindValue(":prenom",prenomC);
    query.bindValue(":cin",CIN);
    query.bindValue(":pack",packC);
    query.bindValue(":date",dateC);
    query.bindValue(":heure",heureC);
    query.bindValue(":local",localC);
    query.bindValue(":commande",commandeC);
    query.bindValue(":vehicule",vehiculeC);
    query.bindValue(":troupe",troupeC);
    query.bindValue(":decoration",DecorationC);
    query.bindValue(":avance",avance);
    return query.exec();
 }
QSqlQueryModel *Client::tri_client(QString ch)
{QSqlQueryModel *model=new QSqlQueryModel();
    if(ch=="nom")
    {
        model->setQuery("select * from clients  order by nom" );
    }
    else if(ch=="prenom")
    {
        model->setQuery("select * from clients  order by prenom" );
    }
    else if(ch=="date")
        {

        model->setQuery("select * from clients  order by DATEM" );
               }

   else if(ch=="pack")
    {
        model->setQuery("select * from clients  order by pack" );
           }
    else if(ch=="avance")
     {
         model->setQuery("select * from clients  order by avance" );
            }
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Pack"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Heure"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Local"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("Troupe"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("Vehicule"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("Decoration"));
        model->setHeaderData(10,Qt::Horizontal,QObject::tr("Commande"));
        model->setHeaderData(11,Qt::Horizontal,QObject::tr("Avance"));
              return model;
}
QSqlQueryModel *Client::recherche_client(QString ch,QString mot)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    if(ch=="nom")
            {model->setQuery("select * from clients where nom LIKE '"+mot+"'" );}
    else if(ch=="prenom")
    {model->setQuery("select * from clients where prenom LIKE '"+mot+"'" );}
    else if(ch=="CIN")
    {model->setQuery("select * from clients where cin LIKE '"+mot+"'" );}
    else if(ch=="local")
    {model->setQuery("select * from clients where local LIKE '"+mot+"'" );}
    else if(ch=="troupe")
    {model->setQuery("select * from clients where troupe LIKE '"+mot+"'" );}
    else if(ch=="vehicule")
    {model->setQuery("select * from clients where vehicule LIKE '"+mot+"'" );}
    else if(ch=="pack")
    {model->setQuery("select * from clients where pack LIKE '"+mot+"'" );}
    else if(ch=="")
    {model->setQuery("select * from clients " );}




    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Pack"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Heure"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Local"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Troupe"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Vehicule"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("Decoration"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("Commande"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("Avance"));
          return model;
}
