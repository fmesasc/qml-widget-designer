#ifndef OBJECTE_H
#define OBJECTE_H

#include <QObject>
#include "informacio.h"

class Objecte : public QObject
{
    Q_OBJECT
public:
    Objecte();
    Objecte(QObject *objecte);
    QString getID();
    void setID(QString id);
    QString getTipus();
    void setTipus(QString tipus);
    void setObject(QObject *objecte);
    QObject* getObject();
    void setColor(QString RGB);
    QString getColor();
    void setRadi(float Radi);
    float getRadi();
    void setAlcada(float Alcada);
    float getAlcada();
    void setAmplada(float Amplada);
    float getAmplada();
    void setEscala(float Escala);
    float getEscala();
    void mostraPunts(bool a);
public slots:
    void mostraInfo();
    void actualitzaInfo(informacio *info);
    void novaInfo(informacio *info, float Radi,float Alcada,float Amplada,QString color,QString tipus, float Escala);
private:
    QObject *obj;
    QString id;
    QString tipus;
};

#endif // OBJECTE_H
