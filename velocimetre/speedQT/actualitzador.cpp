#include "actualitzador.h"
#include <QDebug>

Actualitzador::Actualitzador(QObject *qmlObject,QObject *rpmObject)
{
    setKmQML(qmlObject);
    setRpmQML(rpmObject);
    udpSocketUdpRx = new QUdpSocket(this);
    udpSocketUdpRx->bind(TX);
    connect(udpSocketUdpRx, SIGNAL(readyRead()),this, SLOT(vDatagramaUdpRxRebut()));

    rpm=0;
    km=0;
    /*
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    timer->start(200);*/
    /*
    QString aux("km:400");
    QStringList strList = aux.split(":");
    qDebug()<<"posicio 0: " + strList.at(0);
    qDebug()<<"posicio 1: " + strList.at(1);
    */
}

void Actualitzador::updateCaption(){
    /*
    qDebug()<<km;
    if(km>200){
        km = 0;
    }else
        km++;
    //qDebug()<<"1";
    //qDebug() << qmlObject->property("km");
    qmlObject->setProperty("km", km);

    if(rpm>8000){
        rpm=0;
    }else{
        rpm+=100;
    }
    //qDebug() << qmlObject->property("rpm");
    rpmObject->setProperty("rpm", rpm);

    //qDebug()<<"2";*/
}
/*
void Actualitzador::setController(QQmlApplicationEngine *controller){
    this->controller = controller;
    this->rootObject = controller->rootObjects().first();
    this->qmlObject = rootObject->findChild<QObject*>("Velocimetre");
}
*/
void Actualitzador::setKmQML(QObject *qmlObject){
    this->qmlObject = qmlObject;
    qDebug()<<"pass";
}
void Actualitzador::setRpmQML(QObject *qmlObject){
    this->rpmObject = qmlObject;
    qDebug()<<"pass";
}

void Actualitzador::vDatagramaUdpRxRebut(){
    while (udpSocketUdpRx->hasPendingDatagrams()) {
         QByteArray datagram;
         QHostAddress adrecaOrigen;
         quint16 portOrigen;
         datagram.resize(udpSocketUdpRx->pendingDatagramSize());
         udpSocketUdpRx->readDatagram(datagram.data(),datagram.size(),&adrecaOrigen,&portOrigen);
         vInterpretaTramaRebudaUdp(datagram,adrecaOrigen);
     }
}

void Actualitzador::vInterpretaTramaRebudaUdp(QByteArray datagrama,QHostAddress adrecaOrigen){
    /*ui->plainTextEdit->appendHtml(trUtf8("%1").arg(datagrama.data()));
    ui->plainTextEdit->ensureCursorVisible();*/
    //qDebug()<<datagrama.data();
    //qDebug()<<atoi(datagrama.data());
    /*QString textRebut = datagrama.data();
    QStringList strList = textRebut.split(":");
    if(strList(0)){
        textRebut.lastIndexOf(":");
        textRebut.
    }*/

    QString textRebut = datagrama.data();
    QStringList strList = textRebut.split(":");
    int numRebut = (strList.at(1)).toInt();

    //qDebug()<<"posicio 0: " + strList.at(0);
    //qDebug()<<"posicio 1: " + strList.at(1);
    qDebug()<<"STR: " + strList.at(0);
    if(strList.at(0)=="km"){
        km = (200*numRebut)/1024;
        //qDebug()<<km;
        qmlObject->setProperty("km", km);
    }else if(strList.at(0)=="rpm"){
        rpm = (8000*numRebut)/1024;
        qDebug()<<rpm;
        rpmObject->setProperty("rpm", rpm);
    }


    //dtrebut


    //qDebug()<<km;
}
