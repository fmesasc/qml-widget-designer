#ifndef TIPUSRECTANGLE_H
#define TIPUSRECTANGLE_H

#include <QWidget>

namespace Ui {
class tipusRectangle;
}

class Formes : public QWidget
{
    Q_OBJECT

public:
    explicit Formes(QWidget *parent = 0);
    void nouRectangleDef();
    void nouCercleDef();
    ~Formes();
signals:
    //void nouRectangle();
    //void nouRectangle(QString id, float width, float height);
    void novaForma(QString id, float width, float height, QString color, QString tipus);
    void nouRectangleDefinit();

private slots:
    void on_btnCancelar_clicked();
    void on_btnAfegir_clicked();
    void on_leColor_selectionChanged();

    void on_cbTipus_currentIndexChanged(const QString &arg1);

private:
    Ui::tipusRectangle *ui;
    void mostraMissatge(QString text);
};

#endif // TIPUSRECTANGLE_H
