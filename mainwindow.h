#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<fournisseur.h>
#include <QMainWindow>
#include<commande.h>
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon ;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_Ajouter_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_modifier_clicked();

    //void on_pushButton_ajoute_cmd_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_actionprint_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur tempfournisseur;
    commande tempcommande;
    QSystemTrayIcon *mysystem;
};
#endif // MAINWINDOW_H
