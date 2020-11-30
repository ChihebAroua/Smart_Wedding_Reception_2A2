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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempfournisseur.afficher());
    ui->tableView_2->setModel(tempcommande.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
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
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM COMMANDE ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DES COMMANDES  <br></h1>\n <br> <table>  <tr>  <th> Num_cmd </th> <th>id_four </th> <th>ref_produit </th> <th> quantite </th> <th>date_cmd </th> <th>prix_unitaire </th> <th>TVA </th> <th>totale </th>    </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" "  " " "</td>   <td>"+q.value(5).toString()+" </td> <td>"+q.value(6).toString()+" <td>"+q.value(7).toString()+" <td>"+q.value(8).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
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
