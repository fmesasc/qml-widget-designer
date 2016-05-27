#include "tipustext.h"
#include "ui_tipustext.h"
#include <QFontDialog>
#include <QColorDialog>
tipusText::tipusText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipusText)
{
    ui->setupUi(this);
}

tipusText::~tipusText()
{
    delete ui;
}

/*!
 * \brief tipusText::on_pushButton_clicked
 * Realitza les operacions necesaries al fer click en el boto font.
 */
void tipusText::on_pushButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Arial", 10), this);
    if (ok) {
        ui->cbCursiva->setChecked(font.italic());
        ui->cbNegreta->setChecked(font.bold());
        ui->leFamilia->setText(font.family());
        ui->leSize->setText(QString::number(font.pointSize()));
    }
    else{
        return;
    }
}

/*!
 * \brief tipusText::on_btnCancel_clicked
 * Cancela la creació del text
 */
void tipusText::on_btnCancel_clicked()
{
    this->~tipusText();
}

/*!
 * \brief tipusText::on_btnAdd_clicked
 * Afegeix el text que has predefinit.
 */
void tipusText::on_btnAdd_clicked()
{
    QString id = ui->leID->text();
    QString text = ui->leText->text();
    QString color = ui->leColor->text();
    QString family = ui->leFamilia->text();
    QString tamany = ui->leSize->text();
    if(!id.isEmpty() && !text.isEmpty() && !color.isEmpty() && !family.isEmpty()){
        emit nouText(id,text,color,family,tamany,ui->cbNegreta->isChecked(),ui->cbCursiva->isChecked());
    }
}

/*!
 * \brief tipusText::on_btnColor_clicked
 * Permet seleccionar un color i el introdueix al line edit leColor.
 */
void tipusText::on_btnColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::green);
    ui->leColor->setText(color.name());
}
