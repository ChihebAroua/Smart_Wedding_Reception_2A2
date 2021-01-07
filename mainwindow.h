#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "local.h"
#include "troupe.h"
#include "stmp.h"
#include <QTranslator>

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
    void on_pushButton_clicked();

    void on_supprimerlocal_clicked();

    void on_ajoutertroupe_clicked();

    void on_Supprimer_3_clicked();

    void on_modifierlocal_clicked();

    void on_modifiertroupe_clicked();

    void on_exportpdf_clicked();

    void on_exportpdflocal_clicked();

    void on_button_cherchert_clicked();

    void on_button_chercherlocal_clicked();

    void on_button_triertroupe_clicked();

    void on_trierlocal_clicked();

    void on_pushButton_5_clicked();

    void on_imprimerlocal_clicked();

    void on_imprimertroupe_clicked();

    void on_plot_customContextMenuRequested(const QPoint &pos);

    void on_tabWidget_currentChanged(int index); //stat troupe

    void on_tabWidgetlocal_currentChanged(int index); //stat local

    void on_pushButton_4_clicked();

    void on_sendmail_clicked();

    void on_excel_clicked();

    void on_exceltroupe_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    local tempLocal;
    troupe temptroupe;
  QStringList files;
  QTranslator T;
};
#endif // MAINWINDOW_H
