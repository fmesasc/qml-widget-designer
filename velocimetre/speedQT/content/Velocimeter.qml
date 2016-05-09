import QtQuick 2.0

Item {
    width: 400
    height: 400
    property real angle : 0
    property real km : 0
    onKmChanged: contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
    objectName: "Velocimetre"
    Image {
        id : fons
        anchors.centerIn: parent
        source: "qrc:/img/vel_04div_background.png"
    }

    Rectangle{
        id: contenidorCursor
        width: parent.width
        height: parent.height
        color: "transparent"
        Image {
                id: cursor
                x:55
                y:181
                source: "qrc:/img/vel_04div_agulla.png"
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
            km=km-1
            if(km<0 ){
                km=0
            }else if(km>200){
                km=200
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
            //console.log(km)
        }
        Keys.onRightPressed: {
            km=km+1
            if(km<0 ){
                km=0
            }else if(km>200){
                km=200
            }
            contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
            angle = contenidorCursor.rotation
            //console.log(km)
        }
        Keys.onPressed: {
                if (event.key == Qt.Key_X) {
                    km=km+10
                    if(km<0 ){
                        km=0
                    }else if(km>200){
                        km=200
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
                    angle = contenidorCursor.rotation
                    console.log(km)
                }else if (event.key == Qt.Key_Z) {
                    km=km-10
                    if(km<0 ){
                        km=0
                    }else if(km>200){
                        km=200
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
                    angle = contenidorCursor.rotation
                    console.log(km)
                }else if (event.key == Qt.Key_V) {
                    km=km+20
                    if(km<0 ){
                        km=0
                    }else if(km>200){
                        km=200
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
                    angle = contenidorCursor.rotation
                    console.log(km)
                }else if (event.key == Qt.Key_C) {
                    km=km-20
                    if(km<0 ){
                        km=0
                    }else if(km>200){
                        km=200
                    }
                    contenidorCursor.rotation = (contenidorCursor.rotation = (251*km)/200)
                    angle = contenidorCursor.rotation
                    console.log(km)
                }
            }

}
