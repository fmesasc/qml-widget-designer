#include "Formes.h"
#include "ui_tipusrectangle.h"
#include <QValidator>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QDebug>

/*!
 * \brief Formes::Formes
 * \param parent
 * Constructor
 */
Formes::Formes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipusRectangle)
{
    ui->setupUi(this);
    ui->cbTipus->addItem("Rectangle");
    ui->cbTipus->addItem("Cercle");
}
/*!
 * \brief Formes::~Formes
 * Destructor
 */
Formes::~Formes()
{
    delete ui;
}
/*!
 * \brief Formes::on_btnCancelar_clicked
 * Tanca la finestra.
 */
void Formes::on_btnCancelar_clicked()
{
    this->close();
}

/*!
 * \brief Formes::on_btnAfegir_clicked
 * Afegeix la forma desitjada.
 */
void Formes::on_btnAfegir_clicked()
{
    QString amplada = ui->leAmplada->text();
    QString alcada = ui->leAlcada->text();
    QString id = ui->leID->text();
    QString color = ui->leColor->text();
    QString tipus = ui->cbTipus->currentText();
    QString radi = ui->leRadi->text();
    float ampla;
    float alca;
    bool ok;
    if(tipus=="Rectangle"){
        ampla = amplada.toFloat(&ok);
        if(ok==false){
            mostraMissatge("Error amb l'amplada.");
            return;
        }
        alca = alcada.toFloat(&ok);
        if(ok==false){
            mostraMissatge("Error amb l'alçada.");
            return;
        }
    }else if (tipus=="Cercle"){
        float rad = radi.toFloat(&ok);
        if(ok==false){
            mostraMissatge("Error amb el radi.");
            return;
        }
        ampla = rad;
        alca = ampla;
    }
    emit novaForma(id, ampla, alca, color, tipus);
}

/*!
 * \brief Formes::mostraMissatge
 * \param text
 * Mostra el missatge desitjat.
 */
void Formes::mostraMissatge(QString text){
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}

/*!
 * \brief Formes::on_leColor_selectionChanged
 * Fa el canvi del color seleccionat.
 */
void Formes::on_leColor_selectionChanged()
{
    QColor color = QColorDialog::getColor(Qt::green);
    ui->leColor->setText(color.name());
}

/*!
 * \brief Formes::on_cbTipus_currentIndexChanged
 * \param arg1
 * Configuració per l'utilització d'una forma concreta.
 */
void Formes::on_cbTipus_currentIndexChanged(const QString &arg1)
{
    if(arg1=="Rectangle"){
        ui->leAlcada->setVisible(true);
        ui->lAlcada->setVisible(true);
        ui->leAmplada->setVisible(true);
        ui->lAmplada->setVisible(true);
        ui->leRadi->setVisible(false);
        ui->lRadi->setVisible(false);
    }else if (arg1=="Cercle"){
        ui->leAlcada->setVisible(false);
        ui->lAlcada->setVisible(false);
        ui->leAmplada->setVisible(false);
        ui->lAmplada->setVisible(false);
        ui->leRadi->setVisible(true);
        ui->lRadi->setVisible(true);
    }
}

/*!
 * \brief Formes::nouRectangleDef
 * Crea un nou rectangle predefinit.
 */
void Formes::nouRectangleDef(){
    emit novaForma("1", 100, 100, "#00FF00", "Rectangle");
}

/*!
 * \brief Formes::nouCercleDef
 * Crea un nou cercle predefinit.
 */
void Formes::nouCercleDef(){
    emit novaForma("1", 100, 100, "#00FF00", "Cercle");
}

