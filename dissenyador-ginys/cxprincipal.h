#ifndef CXPRINCIPAL_H
#define CXPRINCIPAL_H

#include <QMainWindow>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "organitzador.h"

namespace Ui {
class CxPrincipal;
}

class CxPrincipal : public QMainWindow
{
    Q_OBJECT
public:
    explicit CxPrincipal(QWidget *parent = 0);
    ~CxPrincipal();
signals:
    void createNew();
private slots:
    void novaForma();
    void crearRectanglePredef();
    void crearCerclePredef();
    void crearText();
private:
    Ui::CxPrincipal *ui;
    Organitzador *organitzador;
    //QObject *rootObject;
    //Organitzador organitzador;
};

#endif // CXPRINCIPAL_H
