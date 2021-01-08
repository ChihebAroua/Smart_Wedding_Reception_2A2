#ifndef PORT_H
#define PORT_H
#include "arduinofy.h"
#include <QDialog>

namespace Ui {
class port;
}

class port : public QDialog
{
    Q_OBJECT

public:
    explicit port(QWidget *parent = nullptr);
    ~port();
private slots:

    void on_oui_clicked();
    void update_arduino();
    void on_non_clicked();

private:
    Ui::port *ui;
    ArduinoFY FY;
};

#endif // PORT_H
