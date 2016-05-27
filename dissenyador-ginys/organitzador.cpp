#include "organitzador.h"
#include <QVariant>
#include <QErrorMessage>
#include <QMessageBox>

Organitzador::Organitzador(QObject *objecte)
{
    rootElement = objecte;
}

/*!
 * \brief Organitzador::setOrganitzadorRootElement
 * \param objecte
 * Selecciona l'objecte qml que simbolitza el element root de l'organitzador.
 */
void Organitzador::setOrganitzadorRootElement(QObject *objecte){
    rootElement = objecte;
}

/*!
 * \brief Organitzador::addObjecte
 * \param InstruccioQML
 * \param obj
 * Afegeix un objecte a partir d'una instrucció qml.
 */
void Organitzador::addObjecte(QString InstruccioQML, Objecte *obj)
{
    QVariant returnedValue;
    QVariant msg = (QVariant) InstruccioQML;
    QMetaObject::invokeMethod(rootElement, "createNewRectangle",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
    QObject *qObj = qvariant_cast<QObject *>(returnedValue);
    obj->setObject(qObj);
    objectes.append(obj);
    obj->getColor();
}

/*!
 * \brief Organitzador::addText
 * \param id
 * \param text
 * \param color
 * \param family
 * \param tamany
 * \param negreta
 * \param cursiva
 * Afegeix un text amb les seves propietats
 */
void Organitzador::addText(QString id,QString text,QString color,QString family,QString tamany,bool negreta, bool cursiva){
    if(exist(id)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Aquesta id ja existeix.");
        msgBox.exec();
        return;
    }
    QString tipus = "Text";
    Objecte *obj;
    obj = new Objecte(new QObject());
    obj->setID(id);
    obj->setTipus(tipus);
    QString bold = QString::number(negreta)=="1"? "true" : "false";
    QString italic = QString::number(cursiva)=="1"? "true" : "false";

    QString instruccio =
            "import QtQuick 2.0; "
            "Text{"
            "id: 'txt"+id+"';"
            "text: '"+ text +"';"
            "font.family:'" + family + "';"
            "font.pointSize :" + tamany + ";"
            "color : '" + color + "';"
                                  "font.bold : " + bold + ";"
                                  "font.italic: " + italic + ";"
            "MouseArea {"
                "id: txtcontentMouseArea"+ id +";"
                "anchors.fill: parent;"
                "drag.target: txt"+ id + ";"
                "onWheel: {"
                    "if (wheel.modifiers & Qt.ControlModifier) {"
                        "txt"+ id + ".rotation += wheel.angleDelta.y / 120 * 5;"
                        "if (Math.abs(txt"+id+".rotation) < 4){"
                            "txt"+id+".rotation = 0;"
                        "}"
                    "}"
                "}"
            "}"
        "}";
    addObjecte(instruccio,obj);
}

/*!
 * \brief Organitzador::addRectangle
 * \param id
 * \param width
 * \param height
 * \param Color
 * \param tipus
 * Afegeix una forma del tipus indicat amb les seves dades (en cas de ser rodona, width i height són el mateix)
 */
void Organitzador::addForma(QString id, float width, float height, QString Color, QString tipus){
    if(exist(id)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Aquesta id ja existeix.");
        msgBox.exec();
        return;
    }
    Objecte *obj;
    obj = new Objecte(new QObject());
    obj->setID(id);
    obj->setTipus(tipus);
    QString radi ="";
    if(tipus=="Cercle"){
        radi = "radius: width*0.5;";
    }else if(tipus=="Rectangle"){
        radi = "radius: 1;";
    }
    QString instruccio;
        instruccio =
            "import QtQuick 2.0; "
            "Item "
                "{"
                    "id: item" + id + ";"
                    "width: "+ QString::number(width) +";"
                    "height: " + QString::number(height) +";"
                    "signal showInfo();"
                    "Rectangle {"
                        "id: contingut" + id + ";"
                        "property bool handleOnTop" + id +": true;"
                        "property bool lastConfig" + id +": true;"
                        "property bool handleOnRight" + id +": true;"
                        "property bool lastConfigR" + id +": true;"
                        "anchors.top: handle"+ id + ".top;"
                        "anchors.right: handleCostats"+ id + ".right;"
                        "anchors.left: item"+ id + ".left" + ";"
                        "anchors.bottom: item"+ id + ".bottom" + ";"
                        "width: "+ "parent.width" +";"
                        "height: "+ QString::number(width) +";"
                        "color: contentMouseArea" + id + ".pressed ? 'orange' : '" +Color+ "';"
                        +radi+
                        "MouseArea {"
                            "id: contentMouseArea" + id + ";"
                            "anchors.fill: parent;"
                            "drag.target: item" + id + ";"
                            "onWheel:{"
                                "if(wheel.modifiers & Qt.ControlModifier){"
                                    "item"+ id + ".rotation += wheel.angleDelta.y / 120 * 5;"
                                    "if(Math.abs(item" + id + ".rotation)<4){"
                                        "item" + id + ".rotation = 0;"
                                    "}"
                                "}else{"
                                    "item"+ id + ".rotation += wheel.angleDelta.x / 120;"
                                    "if(Math.abs(item" + id + ".rotation)<0.6){"
                                        "item" + id + ".rotation = 0;"
                                    "}"
                                    "var scaleBefore = " + "item" + id + ".scale;"
                                    "item" + id + ".scale += " + "item" + id + ".scale" + "*" + "wheel.angleDelta.y / 120 / 10;"
                                "}"
                            "}"
                            "onDoubleClicked: {"
                                //"color='blue'"
                                "item" + id +".showInfo();"
                            "}"
                        "}"
                        "onHandleOnTop" + id + "Changed: {"
                            "if(HandleOnTop" + id + "){"
                                "anchors.top = handle" + id + ".top;"
                                "anchors.bottom = item" + id + ".bottom;"
                            "}else {"
                                "anchors.bottom = handle" + id + ".bottom;"
                                "anchors.top = item" + id + ".bottom;"
                            "}"
                        "}"
                        "onHandleOnRight" + id + "Changed: {"
                            "if(handleOnRight" + id + "){"
                                "anchors.right = handle" + id + ".right;"
                                "anchors.left = item" + id + ".left;"
                            "}else {"
                                "anchors.left = handle" + id + ".left;"
                                "anchors.right = item" + id + ".left;"
                            "}"
                        "}"
                        "onHeightChanged: {"
                            "if(height <= 0 && lastConfig"+id+"=== handleOnTop" + id + "){"
                                "handleOnTop" + id + "= !handleOnTop" + id+ ";"
                                "lastConfig" + id + "= handleOnTop" + id+ ";"
                            "}"
                        "}"
                        "onWidthChanged: {"
                            "if(width <= 0 && lastConfigR"+id+"=== handleOnRight" + id + "){"
                                "handleOnRight" + id + "= !handleOnRight" + id+ ";"
                                "lastConfigR" + id + "= handleOnRight" + id + ";"
                            "}"
                        "}"
                    "}"
                    "Rectangle{"
                        "id: handle" + id +";"
                        "width: 20;"
                        "height: 20;"
                        "color: handleMouseArea" + id + ".pressed ? 'orange' : 'red' ;"
                        "x: contingut" + id + ".width/2 - width/2;"
                        "radius: width*0.5;"
                        "MouseArea{"
                            "id: handleMouseArea" + id + ";"
                            "anchors.fill: parent;"
                            "drag.target: handle" + id + ";"
                            "drag.axis: Drag.YAxis"
                        "}"
                    "}"
                    "Rectangle{"
                        "id: handleCostats" + id +";"
                        "width: 20;"
                        "height: 20;"
                       "color: handleCostatsMouseArea" + id + ".pressed ? 'orange' : 'red' ;"
                        "x: contingut" + id + ".width - width;"
                        "y: item" + id + ".height - contingut"+ id +".height/2 - height/2;"
                        "radius: width*0.5;"
                        "MouseArea{"
                            "id: handleCostatsMouseArea" + id + ";"
                            "anchors.fill: parent;"
                            "drag.target: handleCostats" + id + ";"
                            "drag.axis: Drag.XAxis;"
                        "}"
                    "}"

               "}";
    addObjecte(instruccio,obj);
    QObject::connect(obj->getObject(), SIGNAL(showInfo()),obj, SLOT(mostraInfo()));
}

/*!
 * \brief Organitzador::exist
 * \param id
 * \return En cas de que existeixi un objecte amb aquesta id retornarà true.
 * Comprova si existeix una ID.
 */
bool Organitzador::exist(QString id){
    foreach (Objecte *o, objectes) {
        if(!QString::compare(o->getID(), id, Qt::CaseInsensitive)){
            return true;
        }
    }
    return false;
}

/*!
 * \brief Organitzador::addRectanglePreDef
 * Crea un rectangle predefinit.
 */
void Organitzador::addRectanglePreDef(){
    int randomValue = qrand() % 100000000;
    addForma(QString::number(randomValue),100.0,100.0,"black","Rectangle");
}

/*!
 * \brief Organitzador::addCerclePreDef
 * Crea un cercle predefinit.
 */
void Organitzador::addCerclePreDef(){
    int randomValue = qrand() % 100000000;
    addForma(QString::number(randomValue),100.0,100.0,"black","Cercle");
}

/*!
 * \brief Organitzador::PuntsTamany
 * \param a
 * Mostra o oculta els punts de tamany dels objectes.
 */
void Organitzador::PuntsTamany(bool a){
    foreach (Objecte *o, objectes) {
        if(o->getTipus()!="Text"){
            o->mostraPunts(a);
        }
    }
}
