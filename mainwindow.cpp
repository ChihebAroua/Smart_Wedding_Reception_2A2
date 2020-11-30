
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "local.h"
#include "troupe.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPrintDialog>
#include <qcustomplot.h>
#include <QPainter>
#include <QTextStream>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked() //ajouter local
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

void MainWindow::on_supprimerlocal_clicked() //supprimerlocal
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






void MainWindow::on_ajoutertroupe_clicked() //ajoutertroupe
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







void MainWindow::on_Supprimer_3_clicked() //supprimertroupe
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



void MainWindow::on_exportpdf_clicked() // export pdf troupe musicale
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




void MainWindow::on_exportpdflocal_clicked()//export pdf local
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




void MainWindow::on_button_cherchert_clicked() // cherchertroupe
{



           int id=ui->lineEdit_cherchertroupe->text().toInt();
            ui->tableView_troupe->setModel(temptroupe.cherchertroupe(id));

            QMessageBox::information(nullptr, QObject::tr("chercher"),
                        QObject::tr("ok"), QMessageBox::Cancel);


}

void MainWindow::on_button_chercherlocal_clicked() // chercher local
{


   int idl=ui->lineEdit_chercherlocal->text().toInt();
     ui->tableView_local->setModel(tempLocal.chercherlocal(idl));

     QMessageBox::information(nullptr, QObject::tr("chercher"),
                 QObject::tr("ok"), QMessageBox::Cancel);



}


void MainWindow::on_button_triertroupe_clicked() //trier troupe
{


   ui->tableView_troupe->setModel(temptroupe.triertroupe());

}

void MainWindow::on_trierlocal_clicked()   //trier local
{
     ui->tableView_local->setModel(tempLocal.trierlocal());
}




void MainWindow::on_imprimerlocal_clicked() //imprimer local
{

    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void MainWindow::on_imprimertroupe_clicked() //imprimer troupe
{

    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}







void MainWindow::on_tabWidget_currentChanged(int index) // statistique troupe
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
              amande->setName("Repartition des prix selon leurs identifiants ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              temptroupe.statistique1(&ticks,&labels);



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
              QSqlQuery q1("select prixt from troupe");
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

void MainWindow::on_tabWidgetlocal_currentChanged(int index) //stat local
{


    // set dark background gradient:
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plott->setBackground(QBrush(gradient));


              // create empty bar chart objects:
              QCPBars *amande = new QCPBars(ui->plott->xAxis, ui->plott->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //set names and colors:
              amande->setName("Repartition des prix selon leurs identifiants ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              tempLocal.statistique(&ticks,&labels);


              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plott->xAxis->setTicker(textTicker);
              ui->plott->xAxis->setTickLabelRotation(60);
              ui->plott->xAxis->setSubTicks(false);
              ui->plott->xAxis->setTickLength(0, 4);
              ui->plott->xAxis->setRange(0, 8);
              ui->plott->xAxis->setBasePen(QPen(Qt::white));
              ui->plott->xAxis->setTickPen(QPen(Qt::white));
              ui->plott->xAxis->grid()->setVisible(true);
              ui->plott->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plott->xAxis->setTickLabelColor(Qt::white);
              ui->plott->xAxis->setLabelColor(Qt::white);

              // prepare y axis:
              ui->plott->yAxis->setRange(0,10);
              ui->plott->yAxis->setPadding(5); // a bit more space to the left border
              ui->plott->yAxis->setLabel("Statistiques");
              ui->plott->yAxis->setBasePen(QPen(Qt::white));
              ui->plott->yAxis->setTickPen(QPen(Qt::white));
              ui->plott->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plott->yAxis->grid()->setSubGridVisible(true);
              ui->plott->yAxis->setTickLabelColor(Qt::white);
              ui->plott->yAxis->setLabelColor(Qt::white);
              ui->plott->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plott->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // Add data:

              QVector<double> PlaceData;
              QSqlQuery q1("select prix from local");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);
              // setup legend:
              ui->plott->legend->setVisible(true);
              ui->plott->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plott->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plott->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(10);
              ui->plott->legend->setFont(legendFont);
              ui->plott->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);




}

void MainWindow::on_pushButton_4_clicked() // quitter local
{
    exit(1);
}
