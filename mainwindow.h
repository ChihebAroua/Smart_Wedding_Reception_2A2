#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pack.h"
#include "client.h"
#include"employes.h"
#include"taches.h"
#include"vehicules.h"
#include"m_electronique.h"
#include "fournisseur.h"
#include "commande.h"
#include "local.h"
#include "troupe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int  getselectedVehicule();
    int getselectedM_elec();
private slots:

    void on_login_clicked();



    void on_backMP_clicked();

    void on_depclient_clicked();

    void on_AjouterC_clicked();

    void on_PDFAc_clicked();

    void on_Modifier_clicked();

    void on_PDFMc_clicked();

    void on_Supprimer_clicked();

    void on_trierC_clicked();

    void on_recherchebuttonC_clicked();

    void on_Ajouter_Pack_clicked();

    void on_EnregistrerP_clicked();

    void on_Supprimer_2_clicked();

    void on_recherchebuttonP_2_clicked();

    void on_recherchebuttonP_clicked();

    void on_depRH_clicked();
    void make_plot();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_supprimer_employe_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_ajouter_tache_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_modifier_tache_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_chercher_clicked();

    void on_comboBoxidt_currentIndexChanged(const QString &arg1);

    void on_comboBox_id_modifier_currentIndexChanged(const QString &arg1);

    void on_depLogistique_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();


    void on_tabWidget_currentChanged(int index);

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_PDf_clicked();

    void on_recherche_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_depSA_clicked();

    void on_pushButton_Ajouter_clicked();



    void on_pushButton_modifier_2_clicked();

    void on_modifieFournisseur_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_21_clicked();

    void on_tableView_4_activated(const QModelIndex &index);

    void on_tableView_5_activated(const QModelIndex &index);

    void on_depCG_clicked();

    void on_pushButton_24_clicked();

    void on_modifierlocal_clicked();

    void on_button_chercherlocal_clicked();

    void on_supprimerlocal_clicked();

    void on_exportpdflocal_clicked();

    void on_trierlocal_clicked();

    void on_imprimerlocal_clicked();

    void on_ajoutertroupe_clicked();

    void on_modifiertroupe_clicked();

    void on_button_cherchert_clicked();

    void on_Supprimer_3_clicked();

    void on_exportpdf_clicked();

    void on_button_triertroupe_clicked();

    void on_imprimertroupe_clicked();

private:
    Ui::MainWindow *ui;
    pack tmppack;
    Client tmpclient;
    employes tmp_employes;
    taches tmp_taches;
    Vehicules V;
    m_electronique e;
    fournisseur tempfournisseur;
    commande tempcommande;
    local tempLocal;
    troupe temptroupe;
};
#endif // MAINWINDOW_H
