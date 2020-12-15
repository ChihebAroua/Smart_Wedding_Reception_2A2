#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connect.h"
#include"employes.h"
#include"taches.h"
#include"vehicules.h"
#include"m_electronique.h"
#include "qcustomplot.h"
#include "fournisseur.h"
#include "commande.h"
#include "local.h"
#include "troupe.h"
#include <QMessageBox>
#include <QApplication>
#include <QString>
#include <QComboBox>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPdfWriter>
#include<QIntValidator>
#include<QValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
                   ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
                   ui->lineEdit_cin_2->setValidator(new QIntValidator(0,99999999,this));
               ui->tableView_employes->setModel(tmp_employes.afficher());
               ui->comboBox_id_modifier->setModel(tmp_employes.afficher_combo());
               ui->tableView_tache->setModel(tmp_taches.afficher());
                ui->comboBox_ide->setModel(tmp_employes.afficher_combo());
                 ui->comboBox_ide2->setModel(tmp_employes.afficher_combo());
                ui->comboBoxidt->setModel(tmp_taches.afficher_combo());
                ui->tableView->setModel(V.afficher());
                ui->tableView_e->setModel(e.afficher());
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
                        ui->tableView_local->setModel(tempLocal.afficherlocal());
                       ui->tableView_troupe->setModel(temptroupe.affichertroupe());


                       //controle saisir:
                        ui->lineEdit_idl->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
                        ui->lineEdit_idt->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
                        ui->lineEdit_capacite->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
                        ui->lineEdit_prix->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
                        ui->lineEdit_prixt->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
                        ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                        ui->lineEdit_nomt->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                        ui->lineEdit_type->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
                        ui->lineEdit_duree->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
               //MainWindow::make_plot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString user_name= ui ->username->text() ;
    QString password = ui ->password->text() ;
     Connect EMP(user_name,password);
  int typePer=false;
          typePer=EMP.login_user();
  if(typePer==1)
  {
  ui->stackedWidget->setCurrentIndex(1);
  }
  else if(typePer==2)
  {
      QMessageBox::information(nullptr,QObject::tr("App access "),
                               QObject::tr("Access Confirmed. \n"
                                           "Click Cancel to exist."),QMessageBox::Cancel);
  }else if(typePer==0)
  {
      QMessageBox::information(nullptr,QObject::tr("App access"),
                               QObject::tr("Access denied. \n"
                                           "Click Cancel to exist."),QMessageBox::Cancel);
  }
}

void MainWindow::on_backMP_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_depclient_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_AjouterC_clicked()
{
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


void MainWindow::on_PDFMc_clicked()
{

    QPixmap logo;
    logo.load("ROYALGEMS");
    logo.scaled(logo.width()*330,logo.height()*169);
    QString nom= ui ->NomA_2->text() ;
    QString prenom= ui ->PrenomA_2->text() ;
    QString cin= ui ->CINA_2->text() ;
    int avance= ui->avanceA_4->text().toFloat();
    QString packC=ui->packM->currentText();
    QString date= ui ->dateM_A_2->text() ;
    QString heure= ui ->HeureM_A_2->text() ;
    QString local=ui->localMA->text();
    QString commande=ui->commandeMA->text();
    QString troupe=ui->troupeMA->text();
    QString vehicule=ui->vehiculeMA->text();
    QString decoration=ui->decorationMA->text();
    QString pdf_name= "contart_"+nom+"_"+prenom+".pdf";
    QPdfWriter pdf(pdf_name);
    QPainter painter(&pdf);
    painter.drawPixmap(3000,0,logo.width()*10,logo.height()*10,logo);
    QString avanceC= QString::number(avance);

       painter.setPen(Qt::blue);
       painter.drawText(5000,2000,"Contart client ");
    painter.setPen(Qt::blue);
    painter.drawText(100,2800,"Nom : ");
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
    painter.drawText(100,5500,"Décoration : ");
    painter.setPen(Qt::black);
    painter.drawText(2000,5500,decoration);
    painter.end();
}

void MainWindow::on_Modifier_clicked()
{
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



void MainWindow::on_PDFAc_clicked()
{
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
                    painter.drawText(100,2800,"Nom : ");
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
                    painter.drawText(100,5500,"Décoration : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,5500,decoration);
                    painter.end();
}

void MainWindow::on_Supprimer_clicked()
{
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


void MainWindow::on_trierC_clicked()
{
    QString ch=ui->comboBoxTR->currentText();
         ui->tableView_2->setModel(tmpclient.tri_client(ch));
}

void MainWindow::on_recherchebuttonC_clicked()
{
    QString ch=ui->comboBoxRE->currentText();
      QString mot= ui ->rechercheC->text() ;
      ui->tableView_2->setModel(tmpclient.recherche_client(ch,mot));
}

void MainWindow::on_Ajouter_Pack_clicked()
{
    QString nomP= ui ->Nomp->text() ;
    QString idpack= ui ->idp->text() ;
    int reduction= ui->reductionp->text().toInt();
    int  prixP= ui->prixp->text().toFloat();
    QString local=ui->comboBoxLA->currentText();
    QString commande=ui->comboBoxCA->currentText();
    QString troupe=ui->comboBoxTA->currentText();
    QString vehicule=ui->comboBoxVA->currentText();
    QString decoration=ui->comboBoxDA->currentText();
    pack p(nomP,idpack,local,commande,troupe,vehicule,decoration,reduction,prixP);
    bool test=p.ajouter_pack();
    if(test==true)
    {
        ui->tableView->setModel(tmppack.afficher_pack());
        ui->comboBoxP->setModel(tmppack.afficher_pack());
        ui->packM->setModel(tmppack.afficher_pack());

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

void MainWindow::on_EnregistrerP_clicked()
{
    QString nomP= ui ->Nomp_2->text() ;
      QString idpack= ui ->idp_2->text() ;
      int reduction= ui->reductionp_2->text().toInt();
      int  prixP= ui->prixp_2->text().toFloat();
      QString local=ui->comboBoxLM->currentText();
      QString commande=ui->comboBoxCM->currentText();
      QString troupe=ui->comboBoxTM->currentText();
      QString vehicule=ui->comboBoxVM->currentText();
      QString decoration=ui->comboBoxDM->currentText();
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

void MainWindow::on_Supprimer_2_clicked()
{
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

void MainWindow::on_recherchebuttonP_2_clicked()
{

    QString ch=ui->comboBoxTR->currentText();
     ui->tableView_2->setModel(tmpclient.tri_client(ch));
}


void MainWindow::on_recherchebuttonP_clicked()
{

    QString ch=ui->comboBoxRE->currentText();
    QString mot= ui ->rechercheC->text() ;
    ui->tableView_2->setModel(tmpclient.recherche_client(ch,mot));
}

void MainWindow::on_depRH_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int cin= ui->lineEdit_cin->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QString id= ui->lineEdit_identifient->text();
         QString date_embauche= ui->dateEdit_embauche->text();
         QString departement= ui->comboBox_departement->currentText();
         float salaire= ui->lineEdit_salaire->text().toFloat();
        employes employe(nom,prenom,cin,id,date_embauche,departement,salaire);
        bool test= employe.ajouter();

        if(test)
        {
            ui->tableView_employes->setModel(tmp_employes.afficher());
            ui->comboBox_id_modifier->setModel(tmp_employes.afficher_combo());
            ui->comboBox_ide2->setModel(tmp_employes.afficher_combo());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("Ajout effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlDatabase db;
                   QTableView table_commande;
                   QSqlQueryModel * Modal=new  QSqlQueryModel();

                   QSqlQuery qry;
                    qry.prepare("SELECT * FROM employes ");
                    qry.exec();
                    Modal->setQuery(qry);
                    table_commande.setModel(Modal);



                    db.close();


                    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = table_commande.model()->rowCount();
                    const int columnCount =  table_commande.model()->columnCount();


                    const QString strTitle ="Document";


                    out <<  "<html>\n"
                        "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg(strTitle)
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                       << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des employés")
                       <<"<br>"
                        <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!table_commande.isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!table_commande.isColumnHidden(column)) {
                                QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                            "<br><br>"
                            //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                            <<"<br>"
                            <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                        out << "<thead><tr bgcolor=#f0f0f0>";

                            out <<  "</table>\n"

                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;
                    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                    if (dialog->exec() == QDialog::Accepted) {

                        QLabel lab;
                         QPixmap pixmap(":/img/aze.png");
                        lab.setPixmap(pixmap);
                        QPainter painter(&lab);
                        //QPrinter printer(QPrinter::PrinterResolution);

                        //pixmap.load("aze.png");
                        //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                        //painter.drawPixmap(10,10,50,50, pixmap);

                        document->print(&printer);
                    }

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName("/tmp/commandes.pdf");
                    printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                    delete document;
}

void MainWindow::on_pushButton_supprimer_employe_clicked()
{
    QString id= ui->lineEdit_supprition->text();

        bool test=tmp_employes.supprimer(id);

        if(test)
        {
            ui->tableView_employes->setModel(tmp_employes.afficher());
            ui->comboBox_id_modifier->setModel(tmp_employes.afficher_combo());
             ui->comboBox_ide->setModel(tmp_employes.afficher_combo());
           ui->comboBox_ide2->setModel(tmp_employes.afficher_combo());
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("Supprition effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                        QObject::tr("Supprition non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int cin= ui->lineEdit_cin_2->text().toInt();
       QString nom= ui->lineEdit_nom_2->text();
       QString prenom= ui->lineEdit_prenom_2->text();
       QString id= ui->label_id->text();
        QString date_embauche= ui->dateEdit_embauche_2->text();
        QString departement= ui->comboBox_departement_2->currentText();
        float salaire= ui->lineEdit_salaire_2->text().toFloat();
       employes employe(nom,prenom,cin,id,date_embauche,departement,salaire);
       bool test= employe.modifier();

       if(test)
       {
           ui->tableView_employes->setModel(tmp_employes.afficher());
           ui->comboBox_id_modifier->setModel(tmp_employes.afficher_combo());

           QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("modification effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                       QObject::tr("modification non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_ajouter_tache_clicked()
{

    QString nom= ui->lineEdit_nome->text();
    QString idp= ui->comboBox_ide->currentText();
    QString idt= ui->lineEdit_identifient_idt->text();
    QString tache= ui->lineEdit_tache->text();
    QString dated= ui->dateTimeEdit_dd->text();
    QString datef= ui->dateTimeEdit_df->text();
  QString etat=ui->comboBox_etat->currentText();
  QString remarque=ui->lineEdit_remarque->text();
    taches taches(nom,idp,idt,tache,dated,datef,etat,remarque);
   bool test2=taches.ajouter();

   if(test2)
   {
       ui->tableView_tache->setModel(tmp_taches.afficher());
        ui->comboBoxidt->setModel(tmp_taches.afficher_combo());

       QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                   QObject::tr("Ajout non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_16_clicked()
{
    QString id= ui->lineEdit_supprimer_tache->text();

        bool test=tmp_taches.supprimer(id);

        if(test)
        {
            ui->tableView_tache->setModel(tmp_taches.afficher());
             ui->comboBoxidt->setModel(tmp_taches.afficher_combo());
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("Supprition effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                        QObject::tr("Supprition non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_tache_clicked()
{

    QString nom= ui->lineEdit_nome_2->text();
    QString idp=  ui->comboBox_ide2->currentText();
    QString idt= ui->label_idt->text();
    QString tache= ui->lineEdit_tache_2->text();
    QString dated= ui->dateTimeEdit_dd_2->text();
    QString datef= ui->dateTimeEdit_df_2->text();
  QString etat=ui->comboBox_etat_2->currentText();
  QString remarque=ui->lineEdit_remarque_2->text();
    taches taches(nom,idp,idt,tache,dated,datef,etat,remarque);
   bool test2=taches.modifier();

   if(test2)
   {
       ui->tableView_tache->setModel(tmp_taches.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modification effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                   QObject::tr("Modification non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_trier_clicked()
{
    if (ui->comboBox_trier->currentText()=="nom")
      {
          ui->tableView_tache->setModel(tmp_taches.trier(1));}
      else if (ui->comboBox_trier->currentText()=="l'id de la tache")
      {
          ui->tableView_tache->setModel(tmp_taches.trier(2));}

      else if (ui->comboBox_trier->currentText()=="état")
      {
          ui->tableView_tache->setModel(tmp_taches.trier(4));}
}

void MainWindow::on_pushButton_chercher_clicked()
{
    QString variable=ui->lineEdit_chercher->text();;
        if(ui->comboBox_recherche->currentText()=="identifient")
        {
         ui->tableView_tache->setModel(tmp_taches.chercher(variable,1));}
        else if (ui->comboBox_recherche->currentText()=="nom")
        {
            ui->tableView_tache->setModel(tmp_taches.chercher(variable,2));}
        else if (ui->comboBox_recherche->currentText()=="date de début ")
        {
            ui->tableView_tache->setModel(tmp_taches.chercher(variable,3));}
        else if (ui->comboBox_recherche->currentText()=="date du fin")
        {
            ui->tableView_tache->setModel(tmp_taches.chercher(variable,4));}
        else if (ui->comboBox_recherche->currentText()=="état")
        {
            ui->tableView_tache->setModel(tmp_taches.chercher(variable,5));}




        QMessageBox::information(nullptr, QObject::tr("chercher"),
                    QObject::tr("ok"), QMessageBox::Cancel);
         ui->tableView_tache->setModel(tmp_taches.afficher());
}

void MainWindow::on_comboBoxidt_currentIndexChanged(const QString &arg1)
{
    QString idt= ui->comboBoxidt->currentText();
       QSqlQuery query;
        query.prepare("select * from taches where ID_TACHE='"+idt+"'");
        if (query.exec())
        { while (query.next()) {
                ui->lineEdit_nome_2->setText(query.value(0).toString());
                ui->comboBox_ide2->setCurrentText(query.value(1).toString());
                ui->label_idt->setText(query.value(2).toString());
                  ui->lineEdit_tache_2->setText(query.value(3).toString());
                  ui->dateTimeEdit_dd_2->setDate(query.value(4).toDate());
                   ui->dateTimeEdit_df_2->setDate(query.value(5).toDate());
                  ui->comboBox_etat_2->setCurrentText(query.value(6).toString());
                  ui->lineEdit_remarque_2->setText(query.value(7).toString());


   }
   }
}

void MainWindow::on_comboBox_id_modifier_currentIndexChanged(const QString &arg1)
{
    QString id= ui->comboBox_id_modifier->currentText();
       QSqlQuery query;
        query.prepare("select * from EMPLOYES where id='"+id+"'");
        if (query.exec())
        { while (query.next()) {
                ui->lineEdit_nom_2->setText(query.value(0).toString());
                ui->lineEdit_prenom_2->setText(query.value(1).toString());
                ui->lineEdit_cin_2->setText(query.value(2).toString());
                  ui->label_id->setText(query.value(3).toString());
                  ui->dateEdit_embauche_2->setDate(query.value(4).toDate());
                  ui->comboBox_departement_2->setCurrentText(query.value(5).toString());
                  ui->lineEdit_salaire_2->setText(query.value(6).toString());

   }

        }

}

void MainWindow::on_depLogistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{
    int ref=ui->ref->text().toInt();
         int prix=ui->prix->text().toInt();
        int voltage=ui->voltage->text().toInt();
        QString type=ui->type_e->text();;




        m_electronique V(ref,type,prix,voltage);
     bool test=V.ajouter();
     if(test){
         //refresh
         ui->tableView_e->setModel(V.afficher());


         ui->ref->setText("");
         ui->prix->setText("");
         ui->voltage->setText("");
          ui->type_e->setText("");

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("problem"),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

           if(reply == QMessageBox::Yes){

       int k=getselectedM_elec();
       bool test=e.supprimer(k);
       if(test){
         ui->tableView_e->setModel(e.afficher());
         QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                     QObject::tr("electronique a ete supprimé avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


       }
       else
           QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }

}
int MainWindow::getselectedVehicule()
{
int s=ui->tableView->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView->model()->index(s, 0,QModelIndex());
int aff=ui->tableView->model()->data(index).toString().toInt();
return aff;
}


int MainWindow::getselectedM_elec()
{
int s=ui->tableView_e->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_e->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_e->model()->data(index).toString().toInt();
return aff;
}

void MainWindow::on_pushButton_6_clicked()
{

    /*QString k="7777";
    int o=5;
        m_electronique i(o,k,o,o);
      */

        m_electronique i(ui->ref_e->text().toInt(),ui->type_e_2->text(),ui->prix_e->text().toInt(),ui->vol->text().toInt());
        bool k=i.modifier(getselectedM_elec());
        i.modifier(getselectedM_elec());

        if(k){
            ui->tableView_e->setModel(e.afficher());
                  ui->marque_m->setText("");
                  ui->type_m->setText("");
            }
    else

                  QMessageBox::information(nullptr, QObject::tr("***************s"),
                              QObject::tr("***************s"), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_7_clicked()
{
    bool test=e.supprimerTout();

        QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

            if(reply == QMessageBox::Yes){
        if(test){
             ui->tableView_e->setModel(e.afficher());
            QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                        QObject::tr("tout a ete supprimé avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

       }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString filename="fichier.pdf";
            //Settings
            QPrinter printer;
            printer.setOrientation(QPrinter::Landscape);


             printer.setOutputFileName("C:/Users/Chihab/Desktop/PDF/electronique/fichier.pdf");
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFormat(QPrinter::PdfFormat);

            QPainter painter(&printer);
            painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
            ui->tableView_e->render(&painter );

            painter.end();
            QMessageBox::information(this,tr("Exported!"),tr("Equipements list is now availble in pdf format "));
}

void MainWindow::on_pushButton_9_clicked()
{
    m_electronique k;

                k.rechercher(ui->rec_e->text(),ui->tableView_e);;

        ui->rec_e->setText("");
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView_e->setModel(e.afficherTriType());
}



void MainWindow::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
                 QLinearGradient gradient(0, 0, 0, 400);
                 gradient.setColorAt(0, QColor(90, 90, 90));
                 gradient.setColorAt(0.38, QColor(105, 105, 105));
                 gradient.setColorAt(1, QColor(70, 70, 70));
                 ui->plot->setBackground(QBrush(gradient));


                 // create empty bar chart objects:
                 QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                 amande->setAntialiased(false);
                 amande->setStackingGap(1);
                  //set names and colors:
                 amande->setName("Repartition des matérieux electro selon leurs ID ");
                 amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                 amande->setBrush(QColor(0, 168, 140));
                 // stack bars on top of each other:


                 // prepare x axis with country labels:
                 QVector<double> ticks;
                 QVector<QString> labels;
                 e.statistique(&ticks,&labels);



                 QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                 textTicker->addTicks(ticks, labels);
                 ui->plot->xAxis->setTicker(textTicker);
                 ui->plot->xAxis->setTickLabelRotation(60);
                 ui->plot->xAxis->setSubTicks(false);
                 ui->plot->xAxis->setTickLength(0, 4);
                 ui->plot->xAxis->setRange(0, 8);
                 ui->plot->xAxis->setBasePen(QPen(Qt::white));
                 ui->plot->xAxis->setTickPen(QPen(Qt::white));
                 ui->plot->xAxis->grid()->setVisible(true);
                 ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                 ui->plot->xAxis->setTickLabelColor(Qt::white);
                 ui->plot->xAxis->setLabelColor(Qt::white);

                 // prepare y axis:
                 ui->plot->yAxis->setRange(0,10);
                 ui->plot->yAxis->setPadding(5); // a bit more space to the left border
                 ui->plot->yAxis->setLabel("Statistiques");
                 ui->plot->yAxis->setBasePen(QPen(Qt::white));
                 ui->plot->yAxis->setTickPen(QPen(Qt::white));
                 ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                 ui->plot->yAxis->grid()->setSubGridVisible(true);
                 ui->plot->yAxis->setTickLabelColor(Qt::white);
                 ui->plot->yAxis->setLabelColor(Qt::white);
                 ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                 ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                 // Add data:

                 QVector<double> PlaceData;
                 QSqlQuery q1("select prix from m_electronique");
                 while (q1.next()) {
                               int  nbr_fautee = q1.value(0).toInt();
                               PlaceData<< nbr_fautee;
                                 }
                 amande->setData(ticks, PlaceData);
                 // setup legend:
                 ui->plot->legend->setVisible(true);
                 ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                 ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                 ui->plot->legend->setBorderPen(Qt::NoPen);
                 QFont legendFont = font();
                 legendFont.setPointSize(10);
                 ui->plot->legend->setFont(legendFont);
                 ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();

       QString marque=ui->marque->text();
      QString type=ui->type->text();;
   Vehicules V(id,marque,type);
   bool test=V.ajouter();
   if(test){
       //refresh
       ui->tableView->setModel(V.afficher());


       ui->marque->setText("");
       ui->type->setText("");
       ui->id->setText("");

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("problem"),
                   QObject::tr("connection failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_clicked()
{



    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes){
    //int id=ui->supp_id->text().toInt();
    int k=getselectedVehicule();
    bool test=V.supprimer(k);
    if(test){
      ui->tableView->setModel(V.afficher());
      QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                  QObject::tr("vehicule a ete supprimé avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_clicked()
{
    bool test=V.supprimerTout();

     QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

         if(reply == QMessageBox::Yes){
     if(test){
          ui->tableView->setModel(V.afficher());
         QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                     QObject::tr("tout a ete supprimé avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_PDf_clicked()
{
    QString filename="fichier.pdf";
         //Settings
         QPrinter printer;
         printer.setOrientation(QPrinter::Landscape);


          printer.setOutputFileName("C:/Users/Chihab/Desktop/PDF/fichier.pdf");
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFormat(QPrinter::PdfFormat);

         QPainter painter(&printer);
         painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
         ui->tableView->render(&painter );

         painter.end();
         QMessageBox::information(this,tr("Exported!"),tr("Equipements list is now availble in pdf format "));

}

void MainWindow::on_recherche_clicked()
{
    Vehicules v;

            v.rechercher(ui->rec->text(),ui->tableView);;

    ui->rec->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(V.afficherTriMarque());
}

void MainWindow::on_pushButton_3_clicked()
{
    Vehicules c(ui->id_m->text().toInt(),ui->marque_m->text(),ui->type_m->text());
       c.modifier(getselectedVehicule());
        ui->tableView->setModel(V.afficher());
        ui->marque_m->setText("");
        ui->type_m->setText("");
}

void MainWindow::on_depSA_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    QString id_four=ui->lineEdit_id->text();
        QString nom_four=ui->lineEdit_nom->text();
        QString adresse=ui->lineEdit_adresse->text();
        QString num_tel=ui->lineEdit_num->text();
        QString type_produit=ui->lineEdit_type->text();
        fournisseur f(id_four,nom_four,adresse,num_tel,type_produit);
        bool test=f.ajouter();
        if(test)
        {
            ui->tableView->setModel(tempfournisseur.afficher());
            QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                     QObject::tr("Ajout avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



      }
        else
            QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                     QObject::tr("Ajout echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_modifieFournisseur_clicked()
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


void MainWindow::on_pushButton_12_clicked()
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

void MainWindow::on_pushButton_11_clicked()
{
    QString id_four =ui->lineEdit_9->text();
           ui->tableView->setModel(tempfournisseur.recherche(id_four));
}

void MainWindow::on_pushButton_14_clicked()
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("print Livre");

        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if(d.exec()!=QDialog::Accepted)
            return;
}

void MainWindow::on_pushButton_15_clicked()
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

void MainWindow::on_pushButton_17_clicked()
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

void MainWindow::on_pushButton_18_clicked()
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

void MainWindow::on_pushButton_19_clicked()
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

void MainWindow::on_pushButton_22_clicked()
{
    ui->tableView_2->setModel(tempcommande.trier());
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->tableView_2->setModel(tempcommande.trierdec());
}

void MainWindow::on_pushButton_21_clicked()
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

void MainWindow::on_tableView_4_activated(const QModelIndex &index)
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

void MainWindow::on_tableView_5_activated(const QModelIndex &index)
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

void MainWindow::on_depCG_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_24_clicked()
{
    QString nom=ui->lineEdit_nom->text();
      QString adresse=ui->lineEdit_adresse->text();
      QString disponibilite=ui->lineEdit_disponibilite->text();
      int capacite=ui->lineEdit_capacite->text().toInt();
      int idl=ui->lineEdit_idl->text().toInt();
      float prix=ui->lineEdit_prix->text().toFloat();
      local l(nom,adresse,disponibilite,prix,capacite,idl);
      bool test ;
      test=l.ajouterlocal();

      if(test)
   {
           ui->tableView_local->setModel(tempLocal.afficherlocal());
          QMessageBox::information(nullptr, QObject::tr("Ajout local"),
                      QObject::tr("Ajout avec succés.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
          QMessageBox::critical(nullptr, QObject::tr("Ajout local"),
                      QObject::tr("Ajout impossible.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifierlocal_clicked()
{
    QString nom=ui->lineEdit_nom->text();
       QString adresse=ui->lineEdit_adresse->text();
       QString disponibilite=ui->lineEdit_disponibilite->text();
       int capacite=ui->lineEdit_capacite->text().toInt();
       int idl=ui->lineEdit_idl->text().toInt();
       float prix=ui->lineEdit_prix->text().toFloat();
       local l(nom,adresse,disponibilite,prix,capacite,idl);
       bool test ;
       test=l.modifierlocal();

       if(test)
    {
            ui->tableView_local->setModel(tempLocal.afficherlocal());
           QMessageBox::information(nullptr, QObject::tr("modifier local"),
                       QObject::tr("modifier avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
           QMessageBox::critical(nullptr, QObject::tr("modifier local"),
                       QObject::tr("modifier impossible.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_button_chercherlocal_clicked()
{

    int idl=ui->lineEdit_chercherlocal->text().toInt();
      ui->tableView_local->setModel(tempLocal.chercherlocal(idl));

      QMessageBox::information(nullptr, QObject::tr("chercher"),
                  QObject::tr("ok"), QMessageBox::Cancel);
}

void MainWindow::on_supprimerlocal_clicked()
{
    int idl=ui->lineEdit_supprimerlocal->text().toInt();
       bool test;
       test=tempLocal.supprimerlocal(idl);
       if(test)
       {
            ui->tableView_local->setModel(tempLocal.afficherlocal());
           QMessageBox::information(nullptr, QObject::tr("supprimer local"),
                       QObject::tr("supprission avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("supprimer local"),
                       QObject::tr("supprision échoué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_exportpdflocal_clicked()
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM LOCAL");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LOCAL<br></h1>\n <br> <table>  <tr>  <th>NOM</th> <th>Localisation</th> <th> Disponibilité</th> <th>PRIX</th> <th>capacité</th> <th>identifiant</th>   </tr>" ;


        while ( q.next())
        {

     pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" </td>   <td>" +q.value(1).toString() +"</td>   <td>"+q.value(2).toString()+"</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;
        }

        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
}

void MainWindow::on_trierlocal_clicked()
{
    ui->tableView_local->setModel(tempLocal.trierlocal());
}

void MainWindow::on_imprimerlocal_clicked()
{
    QPrinter rd;
            QPrintDialog d(&rd,this);
            d.setWindowTitle("Print Livre");
            d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
            if (d.exec() != QDialog::Accepted)
                return ;
}

void MainWindow::on_ajoutertroupe_clicked()
{
    QString nomt=ui->lineEdit_nomt->text();
        QString type=ui->lineEdit_type->text();
        QString disponibilitet=ui->lineEdit_disponibilitet->text();
        int duree=ui->lineEdit_duree->text().toInt();
        int idt=ui->lineEdit_idt->text().toInt();
        float prixt=ui->lineEdit_prixt->text().toFloat();
        troupe t(idt,nomt,disponibilitet,type,prixt,duree);
        bool test ;
        test=t.ajoutertroupe();

        if(test)
     {
             ui->tableView_troupe->setModel(temptroupe.affichertroupe());
            QMessageBox::information(nullptr, QObject::tr("Ajout troupe"),
                        QObject::tr("Ajout avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
            QMessageBox::critical(nullptr, QObject::tr("Ajout troupe"),
                        QObject::tr("Ajout impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifiertroupe_clicked()
{
    QString nomt=ui->lineEdit_nomt->text();
        QString type=ui->lineEdit_type->text();
        QString disponibilitet=ui->lineEdit_disponibilitet->text();
        int duree=ui->lineEdit_duree->text().toInt();
        int idt=ui->lineEdit_idt->text().toInt();
        float prixt=ui->lineEdit_prixt->text().toFloat();
        troupe t(idt,nomt,disponibilitet,type,prixt,duree);
        bool test ;
        test=t.modifiertroupe();

        if(test)
     {
             ui->tableView_troupe->setModel(temptroupe.affichertroupe());
            QMessageBox::information(nullptr, QObject::tr("modifier troupe"),
                        QObject::tr("modifier avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
            QMessageBox::critical(nullptr, QObject::tr("modifier troupe"),
                        QObject::tr("modifier impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_button_cherchert_clicked()
{

    int id=ui->lineEdit_cherchertroupe->text().toInt();
     ui->tableView_troupe->setModel(temptroupe.cherchertroupe(id));

     QMessageBox::information(nullptr, QObject::tr("chercher"),
                 QObject::tr("ok"), QMessageBox::Cancel);

}

void MainWindow::on_Supprimer_3_clicked()
{
    int idt=ui->lineEdit_supprimertroupe->text().toInt();
        bool test;
        test=temptroupe.supprimertroupe(idt);
        if(test)
        {
             ui->tableView_troupe->setModel(temptroupe.affichertroupe());
            QMessageBox::information(nullptr, QObject::tr("supprimer troupe"),
                        QObject::tr("supprission avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer troupe"),
                        QObject::tr("supprision échoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_exportpdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

         QPrinter printer(QPrinter::PrinterResolution);
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;
           QSqlQuery q;
           q.prepare("SELECT * FROM TROUPE");
           q.exec();
           QString pdf="<br> <h1  style='color:red'>TROUPE<br></h1>\n <br> <table>  <tr>  <th>IDENTIFIANT</th> <th>NOM</th> <th> Disponibilité </th> <th> TYPE</th> <th>PRIX</th> <th>Duree</th>    </tr>" ;


           while ( q.next()) {

               pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td>" +q.value(1).toString() +" </td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(2).toString()+"</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

           }
           doc.setHtml(pdf);
           doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
           doc.print(&printer);

}

void MainWindow::on_button_triertroupe_clicked()
{
    ui->tableView_troupe->setModel(temptroupe.triertroupe());
}

void MainWindow::on_imprimertroupe_clicked()
{
    QPrinter rd;
          QPrintDialog d(&rd,this);
          d.setWindowTitle("Print Livre");
          d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
          if (d.exec() != QDialog::Accepted)
              return ;
}
