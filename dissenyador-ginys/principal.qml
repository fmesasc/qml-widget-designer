import QtQuick 2.0

Rectangle {
    id: root
    width: 500
    height: 500
    color: "transparent"

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        enabled: !drop.enabled
        onContainsMouseChanged: drop.enabled = true
    }
    DropArea {
        id: drop
        anchors.fill: parent

        onEntered: {
            console.log("[Droparea] entered");
            for(var i = 0; i < drag.urls.length; i++)
                if(validateFileExtension(drag.urls[i])){
                    console.log(drag.urls[i]);
                }
            drag.urls
        }

        onDropped: {
            for(var i = 0; i < drag.urls.length; i++)
                if(validateFileExtension(drag.urls[i])){
                    console.log(drag.urls[i]);
                }
            console.log("[Droparea] dropped")

        }

        // Only MP3s
        function validateFileExtension(filePath) {
            return filePath.split('.').pop() == "mp3"
        }

    }
/*
    Text{
        id: txt;
        text: "hola";
        font.family: "arial";
        font.pointSize : 10;
        font.bold: true;
        font.italic: true;
        MouseArea {
            id: txtcontentMouseArea
            anchors.fill: parent
            drag.target: txt
            onWheel: {
                if (wheel.modifiers & Qt.ControlModifier) {
                    txt.rotation += wheel.angleDelta.y / 120 * 5;
                    if (Math.abs(txt.rotation) < 4){
                        txt.rotation = 0;
                    }
                }
            }
        }
    }*/
/*
    Item {
        id: cell
        width: 100
        height: 100
        //x: Math.random() * root.width
        //y: Math.random() * root.height
        Rectangle {
            id: content
            property bool handleOnTop: true
            property bool lastConfig: true
            property bool handleOnRight: true
            property bool lastConfigR: true
            anchors.top: handle.top
            anchors.right: handleCostats.right
            anchors.left: cell.left
            anchors.bottom: cell.bottom
            width: 100
            height: 100
            radius: width*0.5;
            color: contentMouseArea.pressed ? "orange" : "blue"
            signal getID(string id);
            signal getRadi(string radi);
            signal getAlcada(string alcada);
            signal getAmplada(string amplada);
            signal getColor(string color);
            signal getTipus(string tipus);
            signal getEscala(string escala);
            MouseArea {
                id: contentMouseArea
                anchors.fill: parent
                drag.target: cell
                onWheel: {
                    if (wheel.modifiers & Qt.ControlModifier) {
                        cell.rotation += wheel.angleDelta.y / 120 * 5;
                        //handle.rotation += wheel.angleDelta.y / 120 * 5;
                        if (Math.abs(cell.rotation) < 4){
                            cell.rotation = 0;
                            //handle.rotation = 0;
                        }
                    } else {
                        cell.rotation += wheel.angleDelta.x / 120;
                        //handle.rotation += wheel.angleDelta.x / 120;
                        if (Math.abs(cell.rotation) < 0.6){
                            cell.rotation = 0;
                            //handle.rotation = 0;
                        }
                        var scaleBefore = cell.scale;
                        cell.scale += cell.scale * wheel.angleDelta.y / 120 / 10;
                        //handle.scale += handle.scale * wheel.angleDelta.y / 120 / 10;
                    }
                }
                onDoubleClicked: {
                    mostrar();

                }
                function mostrar(){
                    console.log("hola");
                    content.getID(id);
                }//http://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html

            }



            onHandleOnTopChanged: {
                if (handleOnTop) {
                    anchors.bottom = handle.bottom;
                    anchors.top = cell.bottom;
                } else {
                    anchors.top = handle.top;
                    anchors.bottom = cell.bottom;
                }
            }

            onHandleOnRightChanged: {
                if (handleOnRight) {
                    //anchors.right = handleCostats.right ;

                    anchors.left = cell.left - handleCostats.width;
                    anchors.right = anchors.left + handleCostats.width;
                } else {
                    anchors.left = handleCostats.left;
                    anchors.right = cell.left;
                }
            }

            onHeightChanged: {
                // the lastConfig flag is a workaround to avoid the slot
                // onHandleOnTopChanged tobe executed more than one time
                // when the mouse is moved too fast during the dragging.
                if (height <= 0 && lastConfig === handleOnTop) {
                    handleOnTop = !handleOnTop;
                    lastConfig = handleOnTop;
                }
            }


            onWidthChanged: {
                if (width <= 0 && lastConfigR === handleOnRight) {
                    handleOnRight = !handleOnRight;
                    lastConfigR = handleOnRight;
                }
            }
        }

        Rectangle {
            id: handle
            width: 20//parent.width
            height: 20
            color: handleMouseArea.pressed ? "orange" : "red"
            //anchors.centerIn: content
            x: content.width/2 - width/2;
            y: content.y
            MouseArea {
                id: handleMouseArea
                anchors.fill: parent
                drag.target: handle
                drag.axis: Drag.YAxis
            }
            //visible: false
        }
        Rectangle {
            id: handleCostats
            width: 20//parent.width
            height: 20
            color: handleCostatsMouseArea.pressed ? "orange" : "red"
            //x: parent.height/2 - width;
            //x: content.width - width/2;
            //y: content.height/2
            //y: content.height/2 - height/2;
            x: content.width - width/2
            y: content.lastConfig ? (cell.height - content.height / 2) : (cell.height + content.height / 2)
            //y: cell.height - content.height / 2;
            MouseArea {
                id: handleCostatsMouseArea
                anchors.fill: parent
                drag.target: handleCostats
                drag.axis: Drag.XAxis

            }

            //visible: false
        }
    }*/
   /* Item {
        width: 200; height: 200
        Loader {
            source:"/home/francisco/Projecte/Ejercicios/20160507/speedQT/content/Velocimeter.qml";
        }
    }*/
    Component.onCompleted: {
        //createNewRectangle();
        //createNewRectangle();
    }
    function createNewRectangle(string){
        return Qt.createQmlObject(string,root);


        //Qt.createComponent("Rectangle.qml").createObject(root, {"x": 100, "y": 100});



    }

    /*onCreateNew(){

    }*/
}
