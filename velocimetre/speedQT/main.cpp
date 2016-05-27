#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "actualitzador.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    QObject *rootObject = engine.rootObjects().first();
    QObject *velObject = rootObject->findChild<QObject*>("Velocimetre");
    QObject *rpmObject = rootObject->findChild<QObject*>("Rpm");

    Actualitzador a(velObject,rpmObject);

    return app.exec();
}
