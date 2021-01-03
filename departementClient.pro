QT       += core gui sql printsupport
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = test_son

TEMPLATE = app

CONFIG += c++11
CONFIG += console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    connexion.cpp \
    excel.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    pack.cpp

HEADERS += \
    client.h \
    connexion.h \
    excel.h \
    mail.h \
    mainwindow.h \
    notification.h \
    pack.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    resources.qrc
