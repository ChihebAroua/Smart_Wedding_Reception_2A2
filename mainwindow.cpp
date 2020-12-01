#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include"taches.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_cin_2->setValidator(new QIntValidator(0,99999999,this));
ui->tableView_employes->setModel(tmp_employes.afficher());
ui->comboBox_id_modifier->setModel(tmp_employes.afficher_combo());
ui->tableView_tache->setModel(tmp_taches.afficher());
 ui->comboBox_ide->setModel(tmp_employes.afficher_combo());
  ui->comboBox_ide2->setModel(tmp_employes.afficher_combo());
 ui->comboBoxidt->setModel(tmp_taches.afficher_combo());
MainWindow::make_plot();
}

MainWindow::~MainWindow()
{
    delete ui;
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


void MainWindow::on_pushButton_supprimer_employe_clicked()
{ QString id= ui->lineEdit_supprition->text();

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
void MainWindow::on_pushButton_16_clicked()
{  QString id= ui->lineEdit_supprimer_tache->text();

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


void MainWindow::on_pushButton_chercher_clicked()
{ QString variable=ui->lineEdit_chercher->text();;
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
void MainWindow::on_pushButton_trier_clicked()
{    if (ui->comboBox_trier->currentText()=="nom")
    {
        ui->tableView_tache->setModel(tmp_taches.trier(1));}
    else if (ui->comboBox_trier->currentText()=="l'id de la tache")
    {
        ui->tableView_tache->setModel(tmp_taches.trier(2));}

    else if (ui->comboBox_trier->currentText()=="état")
    {
        ui->tableView_tache->setModel(tmp_taches.trier(4));}


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



void MainWindow::make_plot(){// set dark background gradient:
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
    amande->setName("Repartition des employés selon les salaires ");
    amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    amande->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    tmp_employes.statistique(&ticks,&labels);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->plot->xAxis->setTicker(textTicker);
    ui->plot->xAxis->setTickLabelRotation(60);
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setRange(0, 20);
    ui->plot->xAxis->setBasePen(QPen(Qt::white));
    ui->plot->xAxis->setTickPen(QPen(Qt::white));
    ui->plot->xAxis->grid()->setVisible(true);
    ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->plot->yAxis->setRange(0,4000);
    ui->plot->yAxis->setPadding(5); // a bit more space to the left border
    ui->plot->yAxis->setLabel("Salaire des employés");
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
    QSqlQuery q1("select salaire from employes");
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


