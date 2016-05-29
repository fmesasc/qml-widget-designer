#include "cxprincipal.h"
#include "ui_cxprincipal.h"

#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include <QDesktopWidget>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "organitzador.h"
#include "Formes.h"
#include "tipustext.h"
#include <QFileDialog>
#include <QMessageBox>

CxPrincipal::CxPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::CxPrincipal) {
    ui->setupUi(this);
    this->setWindowTitle("IDE");
    //CREACIO DE LA BARRA D'EINES
    QAction *nouRect =ui->EinesDeCreacio->addAction(QIcon(":/icones/Cuadrat.png"), "Nou rectangle");
    QAction *novaRodona =ui->EinesDeCreacio->addAction(QIcon(":/icones/Rodona.png"), "Nova rodona");
    QAction *nouText =ui->EinesDeCreacio->addAction(QIcon(":/icones/Text.png"), "Nou text");
    ui->barraEstat->showMessage("Carregat");
    QQuickView *view = new QQuickView();
    view->setSource(QUrl("qrc:/principal.qml"));//http://wiki.qt.io/QML-Dynamic-Objects
    QWidget *container = QWidget::createWindowContainer(view);
    QObject *rootObject = dynamic_cast<QObject *>(view->rootObject());
    organitzador = new Organitzador(rootObject);
    ui->QMLcontent->addWidget(container);
    connect(nouRect, SIGNAL(triggered()), this, SLOT(crearRectanglePredef()));
    connect(novaRodona, SIGNAL(triggered()), this, SLOT(crearCerclePredef()));

    connect(ui->afegirForma, SIGNAL(triggered()), this, SLOT(novaForma()));
    connect(ui->afegirTxt, SIGNAL(triggered()), this, SLOT(crearText()));
    connect(nouText, SIGNAL(triggered()), this, SLOT(crearText()));
    connect(ui->actionPunts_de_tamany, SIGNAL(triggered(bool)),organitzador,SLOT(PuntsTamany(bool)));
    connect(this,&CxPrincipal::newExternalForm,organitzador,&Organitzador::newExternalForm);

}

CxPrincipal::~CxPrincipal()
{
    delete ui;
}

/**
 * @brief CxPrincipal::novaForma
 * Finestra per crear una nova forma.
 */
void CxPrincipal::novaForma(){
    ui->barraEstat->showMessage("Creant nova forma");
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(255,255,255,192));
    this->setPalette(palette);
    Formes *tr;
    tr = new Formes();
    connect(tr,&Formes::novaForma,organitzador,&Organitzador::addForma);
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth;
    int screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    int x, y;
    x = (screenWidth - tr->width()) / 2;
    y = (screenHeight - tr->height()) / 2;
    tr->move( x, y );
    tr->show();
}

/*!
 * \brief CxPrincipal::crearRectanglePredef
 * Crea un rectangle predefinit.
 */

void CxPrincipal::crearRectanglePredef(){
    ui->barraEstat->showMessage("Creat Rectangle predefinit");
    Formes *tr;
    tr = new Formes();
    connect(tr,&Formes::novaForma,organitzador,&Organitzador::addRectanglePreDef);
    tr->nouRectangleDef();
}

/*!
 * \brief CxPrincipal::crearCerclePredef
 * Crea un cercle predefinit
 */
void CxPrincipal::crearCerclePredef(){
    ui->barraEstat->showMessage("Creat Cercle predefinit");
    Formes *tr;
    tr = new Formes();
    connect(tr,&Formes::novaForma,organitzador,&Organitzador::addCerclePreDef);
    tr->nouRectangleDef();
}


/*!
 * \brief CxPrincipal::crearText
 * Crea un text predefinit
 */
void CxPrincipal::crearText(){
    ui->barraEstat->showMessage("Creant text.");
    tipusText *tt;
    tt = new tipusText;
    tt->show();
    connect(tt,&tipusText::nouText,organitzador,&Organitzador::addText);
}


void CxPrincipal::on_actionVelocimetre_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open QML"), "/home/francisco/Projecte/Ejercicios/20160512_cx/cx-supervisor/CX", tr("QML Files (*.qml)"));

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    //qDebug()<<in.readAll().;
    QString line ="";
    while(!in.atEnd()) {
        line.append(in.readLine());

        //QStringList fields = line.split(",");
        //model->appendRow(fields);
       // qDebug()<<fields;
    }
    qDebug()<<line;
    file.close();

    // organitzador->newExternalForm();
    emit newExternalForm(line);
}
