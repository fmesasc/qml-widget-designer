#ifndef ACTUALITZADOR_H
#define ACTUALITZADOR_H
#include <QTimer>
#include <QQmlApplicationEngine>
#include <QtNetwork>

#define TX 45455

class Actualitzador : QObject{
Q_OBJECT
public:
    Actualitzador(QObject *qmlObject,QObject *rpmObject);
    QTimer *timer;
    int km;
    int rpm;
    //void setController(QQmlApplicationEngine *controller);
    void setKmQML(QObject *qmlObject);
    void setRpmQML(QObject *rpmObject);
public slots:
    void updateCaption();
private slots:
    void vDatagramaUdpRxRebut();

private:
    QObject *qmlObject;
    QObject *rpmObject;
    //Ui::Actualitzador *ui;
    QUdpSocket *udpSocketUdpRx;
    void vInterpretaTramaRebudaUdp(QByteArray datagrama,QHostAddress adrecaOrigen);
};

#endif // ACTUALITZADOR_H
