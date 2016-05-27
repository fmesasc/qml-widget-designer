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
}
/*!
 * \brief Actualitzador::updateCaption
 * Aumenta de forma automatica el comtador de velocimetre i rpm
 */
void Actualitzador::updateCaption(){
    if(km>200){
        km = 0;
    }else
        km++;
    qmlObject->setProperty("km", km);
    if(rpm>8000){
        rpm=0;
    }else{
        rpm+=100;
    }
    rpmObject->setProperty("rpm", rpm);
}

/*!
 * \brief Actualitzador::setKmQML
 * \param qmlObject
 * Modifica els km del QML.
 */
void Actualitzador::setKmQML(QObject *qmlObject){
    this->qmlObject = qmlObject;
}

/*!
 * \brief Actualitzador::setRpmQML
 * \param qmlObject
 * Modifica les RPM del QML.
 */
void Actualitzador::setRpmQML(QObject *qmlObject){
    this->rpmObject = qmlObject;
}

/*!
 * \brief Actualitzador::vDatagramaUdpRxRebut
 * Rep un datagrama via udp.
 */
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

/*!
 * \brief Actualitzador::vInterpretaTramaRebudaUdp
 * \param datagrama
 * \param adrecaOrigen
 * Procesa la trama rebuda per posar-hi les dades.
 */
void Actualitzador::vInterpretaTramaRebudaUdp(QByteArray datagrama,QHostAddress adrecaOrigen){
    QString textRebut = datagrama.data();
    QStringList strList = textRebut.split(":");
    int numRebut = (strList.at(1)).toInt();
    if(strList.at(0)=="km"){
        km = (200*numRebut)/1024;
        qmlObject->setProperty("km", km);
    }else if(strList.at(0)=="rpm"){
        rpm = (8000*numRebut)/1024;
        rpmObject->setProperty("rpm", rpm);
    }
}
