#include "informacio.h"
#include "ui_informacio.h"
#include <QMessageBox>

informacio::informacio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::informacio)
{
    ui->setupUi(this);
}

informacio::~informacio()
{
    delete ui;
}
/*!
 * \brief informacio::setID
 * \param id ID de l'objecte
 * Mostra una ID al camp leID.
 */
void informacio::setID(QString *id){
    ui->leID->setText(*id);
}

/*!
 * \brief informacio::setRadi
 * \param radi
 * Mostra un radi al camp leRadi.
 */
void informacio::setRadi(QString radi){
    ui->leRadi->setText(radi);
}

/*!
 * \brief informacio::setAlcada
 * \param alcada
 * Mostra l'alçada al camp leAlcada.
 */
void informacio::setAlcada(QString alcada){
    ui->leAlcada->setText(alcada);
}

/*!
 * \brief informacio::setAmplada
 * \param amplada
 * Configura l'amplada al camp leAmplada.
 */
void informacio::setAmplada(QString amplada){
    ui->leAmplada->setText(amplada);
}

/*!
 * \brief informacio::setColor
 * \param color
 * Configura el color del camp leColor.
 */
void informacio::setColor(QString color){
    ui->leColor->setText(color);
}

/*!
 * \brief informacio::setTipus
 * \param tipus
 * Configura el tipus en el camp leTipus.
 */
void informacio::setTipus(QString tipus){
    ui->leTipus->setText(tipus);
}

/*!
 * \brief informacio::setEscala
 * \param escala
 * Configura l'escala al camp leEscala.
 */
void informacio::setEscala(QString escala){
    ui->leEscala->setText(escala);
}

/*!
 * \brief informacio::on_btnTancar_clicked
 * Tanca la informacio.
 */
void informacio::on_btnTancar_clicked()
{
    this->~informacio();
}

/*!
 * \brief informacio::on_btnActualitzar_clicked
 * Actualitza les dades.
 */
void informacio::on_btnActualitzar_clicked()
{
    emit actualitzar(this);
}

/*!
 * \brief informacio::on_btnGuardar_clicked
 * Guarda les dades modificades.
 */
void informacio::on_btnGuardar_clicked()
{
    QString radi = ui->leRadi->text();
    QString alcada = ui->leAlcada->text();
    QString amplada = ui->leAmplada->text();
    QString color = ui->leColor->text();
    QString tipus = ui->leTipus->text();
    QString escala = ui->leEscala->text();
    float fRadi;
    float fAlcada;
    float fAmplada;
    float fEscala;
    bool ok;
    fRadi = radi.toFloat(&ok);
    if(ok==false){
        mostraMissatge("Error amb el radi.");
        return;
    }
    fAlcada = alcada.toFloat(&ok);
    if(ok==false){
        mostraMissatge("Error amb l'alçada.");
        return;
    }
    fAmplada = amplada.toFloat(&ok);
    if(ok==false){
        mostraMissatge("Error amb l'amplada.");
        return;
    }
    fEscala = escala.toFloat(&ok);
    if(ok==false){
        mostraMissatge("Error amb l'amplada.");
        return;
    }
    emit guardarDades(this, fRadi,fAlcada,fAmplada,color,tipus,fEscala);
}

/*!
 * \brief informacio::mostraMissatge
 * \param text Missatge a mostrar.
 * Mostra un missatge.
 */
void informacio::mostraMissatge(QString text){
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}
