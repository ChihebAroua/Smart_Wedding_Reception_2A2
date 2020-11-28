#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vehicules.h"
#include <QMainWindow>
#include "m_electronique.h"
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

    void on_id_textEdited(const QString &arg1);





  //  void on_pushButton_clicked();

    void on_supprimer_clicked();

 //   void on_pushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_recherche_clicked();

    void on_pushButton_3_clicked();

    void on_PDf_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_plot_4_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    Vehicules V;
    m_electronique e;
};

#endif // MAINWINDOW_H
