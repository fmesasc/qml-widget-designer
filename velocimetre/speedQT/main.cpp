#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "actualitzador.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //a.setController(engine);

    //engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    //qDebug()<<"prova2";

    QObject *rootObject = engine.rootObjects().first();
    QObject *velObject = rootObject->findChild<QObject*>("Velocimetre");
    QObject *rpmObject = rootObject->findChild<QObject*>("Rpm");
    //qDebug() << qmlObject->property("km");

    Actualitzador a(velObject,rpmObject);
   // a.setKmQML(qmlObject);


    // Step 1: get access to the root object
  /*  QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->findChild<QObject*>("Velocimetre");

    // Step 2a: set or get the desired property value for the root object
    rootObject->setProperty("km", 0);
    qDebug() << rootObject->property("km");*/
/*
    // Step 2b: set or get the desired property value for any qml object
    qmlObject->setProperty("visible", true);
    qDebug() << qmlObject->property("visible");*/

    return app.exec();
}
