#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "notification.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    notification n;
    bool test=c.createconnect();
    a.setStyle("fusion");


    QTranslator T;
        QStringList langs;
        langs<< "French" << "English" << "German";
        const QString lang=QInputDialog::getItem(NULL,"Language","Select a language",langs);
        if(lang == "English")
        {
            T.load(":/english.qm");
        }
        else if(lang == "German")
        {
           T.load(":/german.qm");
        }
        if(lang !="French"){
            a.installTranslator(&T);
        }





    MainWindow w;
    if(test)
    {w.show();
        n.notificationC();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
