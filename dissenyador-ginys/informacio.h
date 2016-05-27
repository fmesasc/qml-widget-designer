#ifndef INFORMACIO_H
#define INFORMACIO_H

#include <QWidget>

namespace Ui {
class informacio;
}

class informacio : public QWidget
{
    Q_OBJECT

public:
    explicit informacio(QWidget *parent = 0);
    ~informacio();
    void setID(QString *id);
    void setRadi(QString radi);
    void setAlcada(QString alcada);
    void setAmplada(QString amplada);
    void setColor(QString color);
    void setTipus(QString tipus);
    void setEscala(QString escala);
    QString getRadi();
    QString getAlcada();
    QString getAmplada();
    QString getColor();
    QString getTipus();
    QString getEscala();

private slots:
    void on_btnTancar_clicked();
    void on_btnActualitzar_clicked();

    void on_btnGuardar_clicked();

signals:
    void actualitzar(informacio*);
    void guardarDades(informacio *info, float Radi,float Alcada,float Amplada,QString color,QString tipus, float Escala);
private:
    Ui::informacio *ui;
    void mostraMissatge(QString text);
};

#endif // INFORMACIO_H
