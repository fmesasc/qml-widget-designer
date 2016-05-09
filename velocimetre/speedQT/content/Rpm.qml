import QtQuick 2.0

Rectangle {
    width: 400
    height: 400
    property real angle : 0
    property real rpm : 0
    onRpmChanged: contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
    objectName: "Rpm"
    color: "transparent"
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
        Image {
                id: cursor
                x:80
                y:181
                source: "qrc:/img/rpm_04div_agulla.png"
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
            console.log(km)
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
            console.log(rpm)
            c//onsole.log(angle)
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
                    console.log(rpm)
                }else if (event.key == Qt.Key_Z) {
                    rpm=rpm-10
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                    console.log(rpm)
                }else if (event.key == Qt.Key_V) {
                    rpm=rpm+20
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                    console.log(rpm)
                }else if (event.key == Qt.Key_C) {
                    rpm=rpm-20
                    if(rpm<0 ){
                        rpm=0
                    }else if(rpm>8000){
                        rpm=8000
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (280*rpm)/8000)
                    angle = contenidorCursor.rotation
                    console.log(rpm)
                }
            }


        focus: true
}
