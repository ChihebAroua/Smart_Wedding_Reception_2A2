#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pack.h"
#include <QMainWindow>
#include "client.h"
#include <QSound>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:



    void on_Ajouter_Pack_clicked();

    //dvoid on_Nomp_textEdited(const QString &arg1);

    void on_Supprimer_2_clicked();






    void on_EnregistrerP_clicked();

    void on_AjouterC_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_recherchebuttonC_2_clicked();

    void on_recherchebuttonC_clicked();

    void on_recherchebuttonP_2_clicked();

    void on_recherchebuttonP_clicked();



    void on_PDFAc_clicked();

private:
    Ui::MainWindow *ui;
    pack tmppack;
    Client tmpclient;
    QSound *son;

};
#endif // MAINWINDOW_H
