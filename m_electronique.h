#ifndef M_ELECTRONIQUE_H
#define M_ELECTRONIQUE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class m_electronique
{
public:
    m_electronique();

    m_electronique(int,QString,int,int);
   int getRef();
    QString getType();
    int getPrix();
      int getVoltage();

    bool ajouter();
   bool modifier(int d);
    bool supprimer(int);
    bool supprimerTout();
  void rechercher(QString a,QTableView *g);
  void statistique(QVector<double>* ticks,QVector<QString> *labels);

 QSqlQueryModel * afficherTriType();
    QSqlQueryModel * afficher();
private:
    QString type;
    int reference,prix,voltage;
};

#endif // M_ELECTRONIQUE_H
