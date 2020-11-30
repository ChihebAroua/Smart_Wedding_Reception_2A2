#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include "QDebug"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
        qDebug() <<"connexion réussite";
    w.show();
    }
    else
      qDebug()  <<"erreur de connexion";
    return a.exec();
}
