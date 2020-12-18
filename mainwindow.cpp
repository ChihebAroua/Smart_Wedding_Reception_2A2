#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fournisseur.h>
#include<QMessageBox>
#include<commande.h>
#include<QPrinter>
#include<QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include<QIntValidator>
#include<QValidator>
#include<QPdfWriter>
#include<QPainter>
#include "notification.h"
#include <QSystemTrayIcon>
#include <QtDebug>
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("(|\"|/|\\.,|[A-Z,a-z]){30}");
    ui->lineEdit_nom->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_num_cmd->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_num->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_quantite->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_prix->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_tva->setValidator(new QIntValidator(0,9999,this));
    ui->lineEdit_totale->setValidator(new QIntValidator(0,999999999,this));
    ui->tableView->setModel(tempfournisseur.afficher());
    ui->tableView_2->setModel(tempcommande.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Ajouter_clicked()
{   notification n;
    QString id_four=ui->lineEdit_id->text();
    QString nom_four=ui->lineEdit_nom->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString num_tel=ui->lineEdit_num->text();
    QString type_produit=ui->lineEdit_type->text();
    fournisseur f(id_four,nom_four,adresse,num_tel,type_produit);
    bool test=f.ajouter();
    if(test)
    {   n.setPopupText("Un fournisseur a été ajouté");
        n.show();
      // mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un fournisseur "));
        ui->tableView->setModel(tempfournisseur.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                 QObject::tr("Ajout avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



  }
    else
    {
        //  n.setPopupText("il y'a un probleme");
          //  n.show();
       QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                 QObject::tr("Ajout echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString num_cmd=ui->lineEdit_num_cmd->text();
    QString id_four=ui->lineEdit_idfour->text();
    QString ref_produit=ui->lineEdit_ref->text();
    QString quantite=ui->lineEdit_quantite->text();
    QString date_cmd=ui->dateEdit->date().toString();
    QString prix_unitaire=ui->lineEdit_prix->text();
    QString TVA=ui->lineEdit_tva->text();
    QString totale=ui->lineEdit_totale->text();
    commande c(num_cmd,id_four,ref_produit,quantite,date_cmd,prix_unitaire,TVA,totale);
    bool test=c.ajouter();
    if(test)
    {
       ui->tableView_2->setModel(tempcommande.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                 QObject::tr("Ajout avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



  }
    else
        QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                 QObject::tr("Ajout echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
   QString id_four=ui->lineEdit_supp->text();
   bool test=tempfournisseur.supprimer(id_four);
   if(test){

       ui->tableView->setModel(tempfournisseur.afficher());
       QMessageBox::information(nullptr,QObject::tr("suppression"),
                                QObject::tr("suppression avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);
   }
   else {
       QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
   }

}

void MainWindow::on_pushButton_modifier_clicked()
{
    QString id_four=ui->lineEdit_id->text();
    QString nom_four=ui->lineEdit_nom->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString num_tel=ui->lineEdit_num->text();
    QString type_produit=ui->lineEdit_type->text();
    fournisseur f(id_four,nom_four,adresse,num_tel,type_produit);
    bool test=f.modifier(id_four);
    if(test)
    {
        ui->tableView->setModel(tempfournisseur.afficher());
        QMessageBox::information(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



  }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}








void MainWindow::on_pushButton_9_clicked()
{
    QString num_cmd=ui->lineEdit_2->text();
    bool test=tempcommande.supprimer(num_cmd);
    if(test){

        ui->tableView_2->setModel(tempcommande.afficher());
        QMessageBox::information(nullptr,QObject::tr("suppression"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                 QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_8_clicked()
{
    QString num_cmd=ui->lineEdit_num_cmd->text();
    QString id_four=ui->lineEdit_idfour->text();
    QString ref_produit=ui->lineEdit_ref->text();
    QString quantite=ui->lineEdit_quantite->text();
    QString date_cmd=ui->dateEdit->date().toString();
    QString prix_unitaire=ui->lineEdit_prix->text();
    QString TVA=ui->lineEdit_tva->text();
    QString totale=ui->lineEdit_totale->text();

    commande c(num_cmd,id_four,ref_produit,quantite,date_cmd,prix_unitaire,TVA,totale);
    bool test=c.modifier(num_cmd);
    if(test)
    {
        ui->tableView_2->setModel(tempcommande.afficher());
        QMessageBox::information(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



  }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("print Livre");

    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(d.exec()!=QDialog::Accepted)
        return;
}

void MainWindow::on_actionprint_triggered()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QString id_four =ui->lineEdit_8->text();
       ui->tableView->setModel(tempfournisseur.recherche(id_four));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView_2->setModel(tempcommande.trier());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_2->setModel(tempcommande.trierdec());

}

void MainWindow::on_pushButton_11_clicked()
{
    QPdfWriter pdf("C:/Users/Helmi/Documents/Gestion_achats/pdfcommande.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste Des commandes");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Helmi/Documents/Gestion_achats/logo.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"num_cmd");
                          painter.drawText(1200,3300,"id_four");
                          painter.drawText(2300,3300,"ref_produit");
                          painter.drawText(3700,3300,"quantite");
                          painter.drawText(5000,3300,"date");
                          painter.drawText(6700,3300,"prix_unitaire");
                          painter.drawText(7900,3300,"TVA");
                          painter.drawText(8700,3300,"totale");


                          QSqlQuery query;
                          query.prepare("select * from commande");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2600,i,query.value(2).toString());
                              painter.drawText(3800,i,query.value(3).toString());
                              painter.drawText(4700,i,query.value(4).toString());
                              painter.drawText(6900,i,query.value(5).toString());
                              painter.drawText(7900,i,query.value(6).toString());
                              painter.drawText(8700,i,query.value(7).toString());


                             i = i + 500;
                          }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString id_four=ui->tableView->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from fournisseur where id_four LIKE '"+id_four+"%' or nom_four LIKE '"+id_four+"%' or adresse LIKE '"+id_four+"%' or num_tel LIKE '"+id_four+"%' or type_produit LIKE '"+id_four+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->lineEdit_id->setText(query.value(0).toString());
                ui->lineEdit_nom->setText(query.value(1).toString());
                ui->lineEdit_adresse->setText(query.value(2).toString());
                 ui->lineEdit_num->setText(query.value(3).toString());
                 ui->lineEdit_type->setText(query.value(4).toString());
            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString num_cmd=ui->tableView_2->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from commande where num_cmd LIKE '"+num_cmd+"%' or id_four LIKE '"+num_cmd+"%' or ref_produit LIKE '"+num_cmd+"%' or quantite LIKE '"+num_cmd+"%' or date_cmd LIKE '"+num_cmd+"%' or prix_unitaire LIKE '"+num_cmd+"%' or TVA LIKE '"+num_cmd+"%' or totale LIKE '"+num_cmd+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->lineEdit_num_cmd->setText(query.value(0).toString());
                ui->lineEdit_idfour->setText(query.value(1).toString());
                ui->lineEdit_ref->setText(query.value(2).toString());
                ui->lineEdit_quantite->setText(query.value(3).toString());
                //ui->dateEdit->setDate(QDate.value(4).toString());
                ui->lineEdit_prix->setText(query.value(5).toString());
                ui->lineEdit_tva->setText(query.value(6).toString());
                ui->lineEdit_totale->setText(query.value(7).toString());

            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_pushButton_12_clicked()
{
    QPdfWriter pdf("C:/Users/Helmi/Documents/Gestion_achats/pdffournisseur.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste Des Fournisseur");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Helmi/Documents/Gestion_achats/logo.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"id_four");
                          painter.drawText(1200,3300,"nom_four");
                          painter.drawText(2600,3300,"adresse_four");
                          painter.drawText(4000,3300,"num_tel");
                          painter.drawText(5400,3300,"ref_produit");



                          QSqlQuery query;
                          query.prepare("select * from fournisseur");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2600,i,query.value(2).toString());
                              painter.drawText(3900,i,query.value(3).toString());
                              painter.drawText(5500,i,query.value(4).toString());



                             i = i + 500;
                          }
}
