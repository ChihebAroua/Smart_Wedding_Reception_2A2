#include "pack.h"

pack::pack()
{
    nomP="";
    idpack="";
    local="no";
    troupe="no";
    vehicule="no";
    commande="no";
    decoration="no";
    reduction=0;
    prixP=0;
}
pack::pack(QString nomP,QString idpack,QString local,QString commande,QString troupe,QString vehicule,QString decoration,int reduction,float prixP)
{
this->idpack=idpack;
this->local=local;
this->troupe=troupe;
this->nomP=nomP;
this->commande=commande;
this->vehicule=vehicule;
this->decoration=decoration;
this->reduction=reduction;
this->prixP=prixP;
}

QString pack::get_nom(){return nomP;}
QString pack::get_Id_pack(){return idpack;}
QString pack::get_local(){return local;}
QString pack::get_commande(){return commande;}
QString pack::get_troupe(){return troupe;}
QString pack::get_vehicule(){return vehicule;}
QString pack::get_decoration(){return decoration;}
int  pack::get_reduction(){return reduction;}
int  pack::get_prix(){return prixP;}


bool pack::ajouter_pack()
{
  QSqlQuery query;
  QString red= QString::number(reduction);
  QString prix= QString::number(prixP);
  query.prepare("INSERT INTO pack(nom, idpack, local, commande, vehicule, decoration, troupe, reduction, prix)"
                "VALUES (:nomP, :idpack, :local, :commande, :vehicule, :decoration, :troupe, :reduction, :prixP)");
  query.bindValue(":nomP",nomP);
  query.bindValue(":idpack",idpack);
  if(local!="oui" && local!="non")
  {
  return false;
  }
      else
  {query.bindValue(":local",local);}
  if(commande!="oui" && commande!="non")
  {
  return false;
  }
      else
  {query.bindValue(":commande",commande);}
  if(vehicule!="oui" && vehicule!="non")
  {
  return false;
  }
      else
  {query.bindValue(":vehicule",vehicule);}
  if(troupe!="oui" && troupe!="non")
  {
  return false;
  }
      else
  {query.bindValue(":troupe",troupe);}
  if(decoration!="oui" && decoration!="non")
  {
  return false;
  }
      else
  {query.bindValue(":decoration",decoration);}
  query.bindValue(":reduction",red);
  query.bindValue(":prixP",prix);
  return query.exec();
}


QSqlQueryModel * pack::afficher_pack()
{
 QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from pack");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Id_pack"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Local"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Commande"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Vehicule"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Decoration"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Troupe"));
 model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reduction"));
 model->setHeaderData(8,Qt::Horizontal,QObject::tr("Prix"));
 return model;
}

bool pack::supprimer_pack(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from pack where idpack = :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool pack::modifier_pack()
{
    QSqlQuery query;

    QString red= QString::number(reduction);
    QString prix= QString::number(prixP);

   query.prepare("UPDATE  PACK set nom=:nomP,local=:local,commande=:commande,troupe=:troupe,vehicule=:vehicule,decoration=:decoration,reduction=:reduction,prix=:prixP WHERE idpack=:idpack")  ;
   query.bindValue(":nomP",nomP);
   query.bindValue(":idpack",idpack);
   query.bindValue(":local",local);
   query.bindValue(":commande",commande);
   query.bindValue(":vehicule",vehicule);
   query.bindValue(":troupe",troupe);
   query.bindValue(":decoration",decoration);
   query.bindValue(":reduction",red);
   query.bindValue(":prixP",prix);
   return query.exec();

}
QSqlQueryModel * pack::tri_pack(QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
        if(ch=="nom")
        {
            model->setQuery("select * from pack  order by nom" );
        }
        else if(ch=="id_pack")
        {
            model->setQuery("select * from pack  order by id_pack" );
        }

        else if(ch=="prix")
        {
            model->setQuery("select * from pack  order by prix" );
                }
       else if(ch=="reduction")
        {
            model->setQuery("select * from pack  order by reduction" );
               }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Id_pack"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Local"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Commande"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Vehicule"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Decoration"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Troupe"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reduction"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("Prix"));
                  return model;
}
QSqlQueryModel *pack::recherche_pack(QString ch,QString mot)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    if(ch=="nom")
            {model->setQuery("select * from pack where nom LIKE '"+mot+"'" );}
    else if(ch=="id_pack")
    {model->setQuery("select * from pack where idpack LIKE '"+mot+"'" );}
    else if(ch=="prix")
    {model->setQuery("select * from pack where prix LIKE '"+mot+"'" );}
    else if(ch=="")
    {model->setQuery("select * from pack " );}




    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Id_pack"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Local"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Commande"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Vehicule"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Decoration"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Troupe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reduction"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Prix"));
          return model;
}
