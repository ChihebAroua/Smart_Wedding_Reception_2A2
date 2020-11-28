#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"vehicules.h"
#include <QMessageBox>
#include<QPainter>
#include<QPrintDialog>
#include<QTextEdit>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include<QPainter>
#include<QTextEdit>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include<QPrinter>
#include "m_electronique.h"
#include "qcustomplot.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
ui->tableView->setModel(V.afficher());
ui->tableView_e->setModel(e.afficher());


}




MainWindow::~MainWindow()
{
    delete ui;
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

}}



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
void MainWindow::on_recherche_clicked()
{Vehicules v;

        v.rechercher(ui->rec->text(),ui->tableView);;

ui->rec->setText("");
            }



void MainWindow::on_pushButton_2_clicked()
{
   ui->tableView->setModel(V.afficherTriMarque());
}



void MainWindow::on_PDf_clicked()
{    QString filename="fichier.pdf";
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



void MainWindow::on_pushButton_3_clicked()
{
   Vehicules c(ui->id_m->text().toInt(),ui->marque_m->text(),ui->type_m->text());
    c.modifier(getselectedVehicule());
     ui->tableView->setModel(V.afficher());
     ui->marque_m->setText("");
     ui->type_m->setText("");
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

void MainWindow::on_pushButton_9_clicked()
{
    m_electronique k;

            k.rechercher(ui->rec_e->text(),ui->tableView_e);;

    ui->rec_e->setText("");

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
