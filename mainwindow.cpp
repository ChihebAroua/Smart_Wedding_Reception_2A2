#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pack.h"
#include "client.h"
#include <QMessageBox>
#include <QApplication>
#include <QApplication>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPdfWriter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
     son=new QSound("C:/Users/User/Desktop/2eme/semestre 1/projet c++/Nouveau dossier/departementClient/son1.wav");
    ui->tableView->setModel(tmppack.afficher_pack());
    ui->tableView_2->setModel(tmpclient.afficher_client());
    ui->comboBoxP->setModel(tmppack.afficher_pack());
    ui->packM->setModel(tmppack.afficher_pack());
ui->avance->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->avanceA_4->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->CINA_3->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->CINA_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->CINS->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->idp->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->idp_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->reductionp_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->reductionp->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->prixp->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->prixp_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
ui->IDSupp->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
 ui->NomA_4->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
  ui->NomA_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
   ui->PrenomA_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->PrenomA_3->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
     ui->localC->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
      ui->localMA->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
       ui->troupeC->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
        ui->troupeMA->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
         ui->vehiculeC->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
          ui->vehiculeMA->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
           ui->commandeC->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
            ui->commandeMA->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
             ui->decorationC->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
              ui->decorationMA->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
               ui->Nomp->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                ui->Nomp_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                 ui->localp->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                  ui->localp_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                   ui->commandep->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                    ui->commandep_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                     ui->troupep->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                      ui->troupep_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                       ui->vehiculep->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                        ui->vehiculep_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                         ui->decorationp->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                          ui->decorationp_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ajouter_Pack_clicked()
{      son->play();

QString nomP= ui ->Nomp->text() ;
QString idpack= ui ->idp->text() ;
int reduction= ui->reductionp->text().toInt();
int  prixP= ui->prixp->text().toFloat();
QString local=ui->localp->text();
QString commande=ui->commandep->text();
QString troupe=ui->troupep->text();
QString vehicule=ui->vehiculep->text();
QString decoration=ui->decorationp->text();
pack p(nomP,idpack,local,commande,troupe,vehicule,decoration,reduction,prixP);
bool test=p.ajouter_pack();
if(test==true)
{
    ui->tableView->setModel(tmppack.afficher_pack());
    ui->comboBoxP->setModel(tmppack.afficher_pack());

    QMessageBox::information(nullptr,QObject::tr("Ajouter une pack"),
                             QObject::tr("Pack ajoutée. \n"
                                         "Click Cancel to exist."),QMessageBox::Cancel);
}
else
{
    QMessageBox::information(nullptr,QObject::tr("Ajouter une pack"),
                             QObject::tr("Erreur . \n"
                                         "Click Cancel to exist."),QMessageBox::Cancel);
}
}


void MainWindow::on_Supprimer_2_clicked()
{      son->play();

    QString id= ui-> IDSupp ->text();
   bool test= tmppack.supprimer_pack(id);
   if(test)
   {
       ui->tableView->setModel(tmppack.afficher_pack());
       ui->comboBoxP->setModel(tmppack.afficher_pack());

       QMessageBox::information(nullptr,QObject::tr("Supprimer une pack"),
                                QObject::tr("Pack supprimée. \n"
                                            "Click Cancel to exist."),QMessageBox::Cancel);
   }
   }












void MainWindow::on_EnregistrerP_clicked()
{
    son->play();

    QString nomP= ui ->Nomp_2->text() ;
    QString idpack= ui ->idp_2->text() ;
    int reduction= ui->reductionp_2->text().toInt();
    int  prixP= ui->prixp_2->text().toFloat();
    QString local=ui->localp_2->text();
    QString commande=ui->commandep_2->text();
    QString troupe=ui->troupep_2->text();
    QString vehicule=ui->vehiculep_2->text();
    QString decoration=ui->decorationp_2->text();
    pack p(nomP,idpack,local,commande,troupe,vehicule,decoration,reduction,prixP);
    bool test= p. modifier_pack();
    if(test==true)
    {
        ui->tableView->setModel(tmppack.afficher_pack());

        QMessageBox::information(nullptr,QObject::tr("Modifier une pack"),
                                 QObject::tr("Pack modifiée. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
    }else
    {
        QMessageBox::information(nullptr,QObject::tr("Erreur"),
                                 QObject::tr("Erreur. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
    }
}

void MainWindow::on_AjouterC_clicked()
{      son->play();

    QString nom= ui ->NomA_4->text() ;
    QString prenom= ui ->PrenomA_3->text() ;
    QString cin= ui ->CINA_3->text() ;
    int avance= ui->avance->text().toFloat();
    QString packC=ui->comboBoxP->currentText();
    QString date= ui ->dateM_A_3->text() ;
    QString heure= ui ->HeureM_A_3->text() ;
    QString local=ui->localC->text();
    QString commande=ui->commandeC->text();
    QString troupe=ui->troupeC->text();
    QString vehicule=ui->vehiculeC->text();
    QString decoration=ui->decorationC->text();
    Client c(nom,prenom,cin,packC,date,heure,local,commande,vehicule,decoration,troupe,avance);
    bool test=c.ajouter_client();
    if(test==true)
    {
        ui->tableView_2->setModel(tmpclient.afficher_client());

        QMessageBox::information(nullptr,QObject::tr("Ajouter un client"),
                                 QObject::tr("client ajouté. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Ajouter un client"),
                                 QObject::tr("Erreur. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
    }

}

void MainWindow::on_Supprimer_clicked()
{      son->play();

    QString cin= ui-> CINS ->text();
   bool test= tmpclient.supprimer_client(cin);
   if(test)
   {
       ui->tableView_2->setModel(tmpclient.afficher_client());
       QMessageBox::information(nullptr,QObject::tr("Supprimer un client"),
                                QObject::tr("clinet supprimé. \n"
                                            "Click Cancel to exist."),QMessageBox::Cancel);
   }
}

void MainWindow::on_Modifier_clicked()
{      son->play();

    QString nom= ui ->NomA_2->text() ;
    QString prenom= ui ->PrenomA_2->text() ;
    QString CIN= ui->CINA_2->text();
    QString  date= ui->dateM_A_2->text();
    QString  heure= ui->HeureM_A_2->text();
    QString pack=ui->packM->currentText();
    float avance=ui->avanceA_4->text().toFloat();
    QString local=ui->localMA->text();
    QString commande=ui->commandeMA->text();
    QString troupe=ui->troupeMA->text();
    QString vehicule=ui->vehiculeMA->text();
    QString decoration=ui->decorationMA->text();
    Client c(nom, prenom,CIN,pack,date,heure,local, commande, vehicule, decoration, troupe, avance);
    bool test= c. modifier_client();
    if(test==true)
    {
        ui->tableView_2->setModel(tmpclient.afficher_client());

        QMessageBox::information(nullptr,QObject::tr("Modifier un client"),
                                 QObject::tr("client modifié. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
    }else
    {
        QMessageBox::information(nullptr,QObject::tr("Erreur"),
                                 QObject::tr("Erreur. \n"
                                             "Click Cancel to exist."),QMessageBox::Cancel);
}
}

void MainWindow::on_recherchebuttonC_2_clicked()
{      son->play();

    QString ch=ui->comboBoxTR->currentText();
     ui->tableView_2->setModel(tmpclient.tri_client(ch));
}

void MainWindow::on_recherchebuttonC_clicked()
{      son->play();

    QString ch=ui->comboBoxRE->currentText();
    QString mot= ui ->rechercheC->text() ;
    ui->tableView_2->setModel(tmpclient.recherche_client(ch,mot));


}

void MainWindow::on_recherchebuttonP_2_clicked()
{      son->play();

    QString ch=ui->comboBoxPTR->currentText();
     ui->tableView->setModel(tmppack.tri_pack(ch));
}

void MainWindow::on_recherchebuttonP_clicked()
{      son->play();

    QString ch=ui->comboBoxPTR->currentText();
    QString mot= ui ->rechercheP->text() ;
    ui->tableView->setModel(tmppack.recherche_pack(ch,mot));
}


void MainWindow::on_PDFAc_clicked()
{      son->play();

                QPixmap logo;
                logo.load("ROYALGEMS");
                logo.scaled(logo.width()*330,logo.height()*169);
                QString nom= ui ->NomA_4->text() ;
                QString prenom= ui ->PrenomA_3->text() ;
                QString cin= ui ->CINA_3->text() ;
                int avance= ui->avance->text().toFloat();
                QString packC=ui->comboBoxP->currentText();
                QString date= ui ->dateM_A_3->text() ;
                QString heure= ui ->HeureM_A_3->text() ;
                QString local=ui->localC->text();
                QString commande=ui->commandeC->text();
                QString troupe=ui->troupeC->text();
                QString vehicule=ui->vehiculeC->text();
                QString decoration=ui->decorationC->text();
                QString pdf_name= "contart_"+nom+"_"+prenom+".pdf";
                QPdfWriter pdf(pdf_name);
                QPainter painter(&pdf);
                painter.drawPixmap(3000,0,logo.width()*10,logo.height()*10,logo);
                QString avanceC= QString::number(avance);

                   painter.setPen(Qt::blue);
                   painter.drawText(5000,2000,"Contart client ");
                painter.setPen(Qt::blue);
                painter.drawText(100,28000,"Nom : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,2800,nom);
                painter.setPen(Qt::blue);
                painter.drawText(100,3100,"Prenom : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,3100,prenom);
                painter.setPen(Qt::blue);
                painter.drawText(100,3400,"Cin : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,3400,cin);
                painter.setPen(Qt::blue);
                painter.drawText(100,3700,"Pack : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,3700,packC);
                painter.setPen(Qt::blue);
                painter.drawText(100,4000,"Avance : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,4000,avanceC);
                painter.setPen(Qt::blue);
                painter.drawText(100,4300,"Local : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,4300,local);
                painter.setPen(Qt::blue);
                painter.drawText(100,4600,"Troupe musical : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,4600,troupe);
                painter.setPen(Qt::blue);
                painter.drawText(100,4900,"Véhicule : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,4900,vehicule);
                painter.setPen(Qt::blue);
                painter.drawText(100,5200,"Commande : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,5200,commande);
                painter.setPen(Qt::blue);
                painter.drawText(100,5300,"Décoration : ");
                painter.setPen(Qt::black);
                painter.drawText(2000,5300,decoration);
                painter.end();
}
