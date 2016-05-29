import QtQuick 2.0;

Item {
    id: velocimetre;
    transform: Rotation {
        id: rot;
        origin.x: contenidorCursor.width/2;
        origin.y: contenidorCursor.height/2;
        axis.x:0; axis.y:1; axis.z:0;
        angle:90;
        Behavior on angle {
            SpringAnimation {
                spring: .70;
                damping: .5;
                duration: 1000;
            }
        }
    }
    function showFront() {
        rot.angle=0;
    }

    function showBack() {
        rot.angle=90;
    }
    anchors.centerIn:parent;
    property real angle : 0;
    property real km : 0;
    onKmChanged: contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
    objectName: "Velocimetre";
    Image {
        id : fons;
        anchors.centerIn: parent;
        source: "qrc:/img/vel_05div_background.png";
    }

    Rectangle{
        id: contenidorCursor;
        width: parent.width;
        height: parent.height;
        anchors.centerIn: parent.Center;
        color: "transparent";
        Image {
                id: cursor;
                anchors.centerIn: parent;
                source: "qrc:/img/vel_05div_agulla.png";
        }
        Behavior on rotation {
            SpringAnimation {
                spring: .90;
                damping: .10;
                duration: 125;
            }
        }
    }

        Keys.onLeftPressed:{
            km=km-1;
            if(km<0 ){
                km=0;
            }else if(km>200){
                km=200;
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
        }
        Keys.onRightPressed: {
            km=km+1;
            if(km<0 ){
                km=0;
            }else if(km>200){
                km=200;
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
            angle = contenidorCursor.rotation;
        }
        Keys.onPressed: {
                if (event.key == Qt.Key_X) {
                    velocimetre.showBack();
                    km=km+10;
                    if(km<0 ){
                        km=0;
                    }else if(km>200){
                        km=200;
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
                    angle = contenidorCursor.rotation;
                }else if (event.key == Qt.Key_Z) {
                    velocimetre.showFront();
                    km=km-10;
                    if(km<0 ){
                        km=0;
                    }else if(km>200){
                        km=200;
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
                    angle = contenidorCursor.rotation;
                }else if (event.key == Qt.Key_V) {
                    km=km+20;
                    if(km<0 ){
                        km=0;
                    }else if(km>200){
                        km=200;
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
                    angle = contenidorCursor.rotation;
                }else if (event.key == Qt.Key_C) {
                    km=km-20;
                    if(km<0 ){
                        km=0;
                    }else if(km>200){
                        km=200;
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200);
                    angle = contenidorCursor.rotation;
                }
            }
}
