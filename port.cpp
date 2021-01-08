#include "port.h"
#include "ui_port.h"
#include "arduinofy.h"
#include <QString>
port::port(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::port)
{
    ui->setupUi(this);
    //aruino Yahya et fourat
    int ret1 = FY.connect_arduino();
    switch (ret1) {
    case(0):qDebug()<<"arduino is available and connected to: "<<FY.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to: "<<FY.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";
    }
    QObject::connect(FY.getserial(),SIGNAL(readyRead()),this,SLOT(update_arduino()));
}

port::~port()
{
    delete ui;
}
void port::update_arduino()
{
QString test;
test=FY.read_from_arduino();
if(test=='1')
{
    ui->messagePort->setText("Client a temperature anormal \n");
}
else if(test=='2')
{ ui->messagePort->setText("Client a temperature normal \n");
}
}

void port::on_oui_clicked()
{
    FY.write_to_arduino("3");
}

void port::on_non_clicked()
{
    FY.write_to_arduino("4");
}
