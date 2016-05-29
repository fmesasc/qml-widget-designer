#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T19:20:09
#
#-------------------------------------------------

QT       += core gui
QT += widgets
QT += qml quick
QT += quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CX
TEMPLATE = app


SOURCES += main.cpp\
        cxprincipal.cpp \
    objecte.cpp \
    organitzador.cpp \
    informacio.cpp \
    tipustext.cpp \
    Formes.cpp

HEADERS  += cxprincipal.h \
    objecte.h \
    organitzador.h \
    informacio.h \
    tipustext.h \
    Formes.h

FORMS    += cxprincipal.ui \
    tipusrectangle.ui \
    informacio.ui \
    tipustext.ui

OTHER_FILES +=

RESOURCES += \
    qml.qrc \
    idiomes.qrc \
    icons.qrc


DISTFILES += \
    deployment.pri \
    uml.qmodel
