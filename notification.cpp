#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notificationC(QString data,int a)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif"));

    notifyIcon->show();
    if (a==1)
   {QString t1,t2;
        t1="l'employé ayant l'id:";
        t1=t1+data;
        t2=" a utilisé la porte privé maintenant";
        t2=t1+t2;
        notifyIcon->showMessage("Notification ",t2,QSystemTrayIcon::Information,15000);}
else if(a==0)
       {QString t1;
        t1="une personne inconnue a essayé d'utiliser la porte privé sous l'id:";
        t1=t1+data;
        notifyIcon->showMessage("Attention ",t1,QSystemTrayIcon::Information,15000);}
}
