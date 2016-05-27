#include "objecte.h"
#include <QQuickItem>
#include <QQmlProperty>
#include "informacio.h"

Objecte::Objecte(QObject *objecte)
{
    this->obj = objecte;
}

/*!
 * \brief Objecte::getID
 * \return Retorna la ID de l'objecte.
 */
QString Objecte::getID(){
    return id;
}

/*!
 * \brief Objecte::setID
 * \param id
 * Modifica la ID de l'Objecte.
 */
void Objecte::setID(QString id){
    this->id = id;
}

/*!
 * \brief Objecte::getTipus
 * \return Retorna el tipus de l'objecte
 */
QString Objecte::getTipus(){
    return this->tipus;
}

/*!
 * \brief Objecte::setTipus
 * \param tipus
 * Modifica el tipus d'identificador.
 */
void Objecte::setTipus(QString tipus){
    this->tipus = tipus;
}

/*!
 * \brief Objecte::setObject
 * \param objecte
 * Modifica l'apuntador de l'objeto.
 */
void Objecte::setObject(QObject *objecte){
    this->obj = objecte;
}

/*!
 * \brief Objecte::setColor
 * \param RGB
 * Modifica el color de l'objecte.
 */
void Objecte::setColor(QString RGB){
    QColor color;
    color.setNamedColor(RGB);
    QVariant variante = color;
    obj->children().at(0)->setProperty("color",variante);
}

/*!
 * \brief Objecte::getColor
 * \return Retorna el color de l'objecte.
 */
QString Objecte::getColor(){
    QVariant variant = obj->children().at(0)->property("color");
    QColor color = variant.value<QColor>();
    return color.name();
}

/*!
 * \brief Objecte::setRadi
 * \param Radi
 * Modifica el radi de l'objecte.
 */
void Objecte::setRadi(float Radi){
    QVariant variante = Radi;
    obj->children().at(0)->setProperty("radius",variante);
}

/*!
 * \brief Objecte::getRadi
 * \return Retorna el radi de l'objecte.
 */
float Objecte::getRadi(){
    QVariant variant = obj->children().at(0)->property("radius");
    float radi = variant.value<float>();
    return radi;
}

/*!
 * \brief Objecte::setAlcada
 * \param Alcada
 * Modifica l'alçada de l'objecte
 */
void Objecte::setAlcada(float Alcada){
    QVariant variante = Alcada;
    obj->children().at(0)->setProperty("height",variante);
}

/*!
 * \brief Objecte::getAlcada
 * \return Retorna l'alçada de l'objecte.
 */
float Objecte::getAlcada(){
    QVariant variant = obj->children().at(0)->property("height");
    float alcada = variant.value<float>();
    return alcada;
}

/*!
 * \brief Objecte::setAmplada
 * \param Amplada
 * Modifica l'amplada de l'objecte
 */
void Objecte::setAmplada(float Amplada){
    QVariant variante = Amplada;
    obj->setProperty("width",variante);
}

/*!
 * \brief Objecte::getAmplada
 * \return Retorna l'amplada de l'objecte.
 */
float Objecte::getAmplada(){
    QVariant variant = obj->children().at(0)->property("width");
    float width = variant.value<float>();
    return width;
}

/*!
 * \brief Objecte::setEscala
 * \param Escala
 * Modifica l'escala de l'objecte
 */
void Objecte::setEscala(float Escala){
    QVariant variante = Escala;
    obj->setProperty("scale",variante);

}
/*!
 * \brief Objecte::getEscala
 * \return Retorna l'escala de l'objecte.
 */
float Objecte::getEscala(){
    QVariant variant = obj->children().at(0)->property("scale");
    float scala = variant.value<float>();
    return scala;
}

/*!
 * \brief Objecte::getObject
 * \return Retorna l'objecte per mostrar a pantalla.
 */
QObject* Objecte::getObject(){
    return obj;
}

/*!
 * \brief Objecte::mostraInfo
 * Mostra l'informacio en una finestra.
 */
void Objecte::mostraInfo(){
    informacio *info;
    info = new informacio;
    info->setWindowTitle("Informació");
    info->show();
    actualitzaInfo(info);
    connect(info,SIGNAL(guardarDades(informacio*,float,float,float,QString,QString,float)),this,SLOT(novaInfo(informacio*,float,float,float,QString,QString,float)));
}

/*!
 * \brief Objecte::actualitzaInfo
 * \param info
 * Actualitza la informacio de l'objecte.
 */
void Objecte::actualitzaInfo(informacio *info){
    info->setID(&id);
    info->setRadi(QString::number(getRadi()));
    info->setAlcada(QString::number(getAlcada()));
    info->setAmplada(QString::number(getAmplada()));
    info->setColor(getColor());
    info->setEscala(QString::number(getEscala()));
}

/*!
 * \brief Objecte::novaInfo
 * \param info Direcció de la informació
 * \param Radi Radi a mostrar
 * \param Alcada Alçada a mostrar
 * \param Amplada Amplada a mostrar
 * \param color
 * \param tipus
 * \param Escala
 */
void Objecte::novaInfo(informacio *info, float Radi,float Alcada,float Amplada,QString color,QString tipus, float Escala){
    this->setRadi(Radi);
    this->setAlcada(Alcada);
    this->setAmplada(Amplada);
    this->setColor(color);
    this->setEscala(Escala);
}

/*!
 * \brief Objecte::mostraPunts
 * \param a
 * Mostra o oculta els punts per redimensionar les formes.
 */
void Objecte::mostraPunts(bool a){
    QVariant variante = true;
    if(a){
        obj->children().at(1)->setProperty("visible",variante);
        obj->children().at(2)->setProperty("visible",variante);
    }else{
        variante = false;
        obj->children().at(1)->setProperty("visible",variante);
        obj->children().at(2)->setProperty("visible",variante);
    }
}
