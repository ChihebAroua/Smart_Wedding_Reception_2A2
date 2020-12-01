#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <connexion.h>
#include "notification.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;
    notification nf;
    bool test=c.createconnect();
     MainWindow w;
    if(test==true)
    {w.show();
        nf.notificationC();

    QMessageBox::information(nullptr,QObject::tr("Database is open"),QObject::tr("Connection successful.\n"
                                                                             "\nClick Cancel to exist."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Database is not open"),QObject::tr("Connection failed.\n"
                                                                                 "\nClick Cancel to exist."),QMessageBox::Cancel);
    }
    return a.exec();
}

