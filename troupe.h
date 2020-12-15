#ifndef TROUPE_H
#define TROUPE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class troupe
{
public:
    troupe();
    troupe(int,QString,QString,QString,float,int);
    QString getNomt(){return nomt;}
    int getIDT(){return idt;}
    QString getDisponibilitet(){return disponibilitet;}
    float getPrixt(){return prixt;}
    int getDuree(){return duree;}
    bool ajoutertroupe();
    QSqlQueryModel * affichertroupe();
    bool supprimertroupe(int);
    bool modifiertroupe();

    QSqlQueryModel * triertroupe();
    QSqlQueryModel * cherchertroupe(int);
    void statistique1(QVector<double>* ticks,QVector<QString> *labels);

private:
QString nomt,disponibilitet,type;
float prixt;
int duree,idt;





};

#endif // TROUPE_H
