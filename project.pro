QT       += core gui sql printsupport
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TEMPLATE = app

CONFIG += console
CONFIG += c++11
QT += serialport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinofy.cpp \
    client.cpp \
    commande.cpp \
    connect.cpp \
    connexion.cpp \
    employes.cpp \
    excel.cpp \
    fournisseur.cpp \
    local.cpp \
    m_electronique.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    pack.cpp \
    port.cpp \
    qcustomplot.cpp \
    taches.cpp \
    troupe.cpp \
    vehicules.cpp

HEADERS += \
    arduino.h \
    arduinofy.h \
    client.h \
    commande.h \
    connect.h \
    connexion.h \
    employes.h \
    excel.h \
    fournisseur.h \
    local.h \
    m_electronique.h \
    mail.h \
    mainwindow.h \
    notification.h \
    pack.h \
    port.h \
    qcustomplot.h \
    taches.h \
    troupe.h \
    vehicules.h

FORMS += \
    mainwindow.ui \
    port.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Traduction.qrc \
    image.qrc \
    pdf.qrc
