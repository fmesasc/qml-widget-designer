#ifndef ORGANITZADOR_H
#define ORGANITZADOR_H
//#include <QObject>
#include "objecte.h"

class Organitzador : public QObject
{
     Q_OBJECT
public:
    //Organitzador();
    Organitzador(QObject *objecte);
    void addObjecte(QString InstruccioQML, Objecte *obj);
    void deleteObjecte(Objecte *objecte);
    void setOrganitzadorRootElement(QObject *objecte);
    bool exist(QString id);
/*
signals:
    void addObjecte(QString string);*/
private:
    QObject *rootElement;
    QList<Objecte*> objectes;
public slots:
 //   void addRectangle(QString id, float width, float height);
    void addForma(QString id, float width, float height,QString Color,QString tipus);
    void addText(QString id,QString text,QString color,QString family,QString tamany,bool negreta, bool cursiva);
    void addRectanglePreDef();
    void addCerclePreDef();
    void PuntsTamany(bool a);
};

#endif // ORGANITZADOR_H
