#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "notification.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    notification n;
    bool test=c.createconnect();
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
