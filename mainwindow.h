#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"employes.h"
#include"taches.h"
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
    void on_pushButton_ajouter_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_supprimer_employe_clicked();

    void on_pushButton_ajouter_tache_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_modifier_tache_clicked();

    void on_comboBox_id_modifier_currentIndexChanged(const QString &arg1);

    void on_pushButton_chercher_clicked();

    void on_pushButton_pdf_clicked();

    void on_comboBoxidt_currentIndexChanged(const QString &arg1);

    void on_pushButton_trier_clicked();

private:
    Ui::MainWindow *ui;
    employes tmp_employes;
    taches tmp_taches;

};
#endif // MAINWINDOW_H
