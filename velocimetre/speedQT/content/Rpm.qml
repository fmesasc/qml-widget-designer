import QtQuick 2.0

Rectangle {
    id: idrpm
    width: 400
    height: 400
    property real angle : 0
    property real rpm : 0
    onRpmChanged: contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
    objectName: "Rpm"
    color: "transparent"

    transform: Rotation {
        id: rot
        origin.x: contenidorCursor.width/2;
        origin.y: contenidorCursor.height/2;
        axis.x:0; axis.y:1; axis.z:0
        angle:90

        Behavior on angle {
            SpringAnimation {
                spring: .70
                damping: .5
                duration: 1000
            }
        }
    }

    function showFront() {
        rot.angle=0;
    }

    function showBack() {
        rot.angle=90;
    }
    Image {
        id : fons
        anchors.centerIn: parent
        source: "qrc:/img/rpm_04div_background.png"
    }
    Rectangle{
        id: contenidorCursor
        width: parent.width
        height: parent.height
        color: "transparent"
        anchors.centerIn: parent.Center

        Image {
                id: cursor

                anchors.centerIn: parent
                source: "qrc:/img/rpm_05div_agulla.png"

        }
        Behavior on rotation {
            SpringAnimation {
                spring: .90
                damping: .10
                duration: 125
            }
        }
    }

        Keys.onLeftPressed:{
            rpm=rpm-1
            if(rpm<0 ){
                km=0
            }else if(rpm>8000){
                km=200
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
        }
        Keys.onRightPressed: {
            rpm=rpm+1
            if(rpm<0){
                rpm=0
            }else if(rpm>8000){
                km=8000
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
            angle = contenidorCursor.rotation
        }
        Keys.onPressed: {
                if (event.key == Qt.Key_X) {
                    rpm=rpm+10
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                }else if (event.key == Qt.Key_Z) {
                    rpm=rpm-10
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                }else if (event.key == Qt.Key_V) {
                    rpm=rpm+20
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                }else if (event.key == Qt.Key_C) {
                    rpm=rpm-20
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                }
            }
        focus :true

}
