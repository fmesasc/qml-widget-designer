TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    actualitzador.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES += \
    vel_03div_agulla.svg

HEADERS += \
    actualitzador.h
