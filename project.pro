QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

CONFIG += console
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    commande.cpp \
    connect.cpp \
    connexion.cpp \
    employes.cpp \
    fournisseur.cpp \
    local.cpp \
    m_electronique.cpp \
    main.cpp \
    mainwindow.cpp \
    pack.cpp \
    qcustomplot.cpp \
    taches.cpp \
    troupe.cpp \
    vehicules.cpp

HEADERS += \
    client.h \
    commande.h \
    connect.h \
    connexion.h \
    employes.h \
    fournisseur.h \
    local.h \
    m_electronique.h \
    mainwindow.h \
    pack.h \
    qcustomplot.h \
    taches.h \
    troupe.h \
    vehicules.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
