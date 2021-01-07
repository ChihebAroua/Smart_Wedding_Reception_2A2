#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vehicules.h"
#include <QMainWindow>
#include "m_electronique.h"
#include "QSystemTrayIcon"
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
int  getselectedVehicule();
int getselectedM_elec();
private slots:
    void on_ajouter_clicked();

   // void on_id_textEdited(const QString &arg1);





    void on_supprimer_clicked();



    void on_pushButton_clicked();




    void on_pushButton_3_clicked();

    void on_PDf_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

   // void on_plot_customContextMenuRequested(const QPoint &pos);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_rec_textChanged(const QString &arg1);


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Vehicules V;
    m_electronique e;
    QSystemTrayIcon *info;
};

#endif // MAINWINDOW_H
