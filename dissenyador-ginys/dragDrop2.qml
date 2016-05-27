import QtQuick 2.6
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

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
                //validat = true;
                console.log("[Droparea] entered");
                // Ensure at least one file is supported before accepted the drag
                for(var i = 0; i < drag.urls.length; i++)
                    if(validateFileExtension(drag.urls[i])){
                        console.log(drag.urls[i]);
                    }
                drag.urls
                //drop.enabled = false
               /* console.log("No valid files, refusing drag event")
                drag.accept()
                drop.enabled = false*/
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
    Text {
            id: textDrop
            anchors.centerIn: parent
            text: "Please drag element"
        }



    Repeater {
        model: 3
        delegate: delegateItem
    }

    Component {
        id: delegateItem

        Item {
            id: cell
            width: 100
            height: 100
            x: Math.random() * root.width
            y: Math.random() * root.height
            Rectangle {
                id: content
                property bool handleOnTop: true
                property bool lastConfig: true
                anchors.top: handle.top
                anchors.bottom: cell.bottom
                width: parent.width
                color: contentMouseArea.pressed ? "orange" : "blue"

                MouseArea {
                    id: contentMouseArea
                    anchors.fill: parent
                    drag.target: cell
                    onWheel: {
                        if (wheel.modifiers & Qt.ControlModifier) {
                            content.rotation += wheel.angleDelta.y / 120 * 5;
                            if (Math.abs(content.rotation) < 4)
                                content.rotation = 0;
                        } else {
                            content.rotation += wheel.angleDelta.x / 120;
                            if (Math.abs(content.rotation) < 0.6)
                                content.rotation = 0;
                            var scaleBefore = content.scale;
                            content.scale += content.scale * wheel.angleDelta.y / 120 / 10;
                        }
                    }
                }

                onHandleOnTopChanged: {
                    if (handleOnTop) {
                        anchors.top = handle.top;
                        anchors.bottom = cell.bottom;
                    } else {
                        anchors.bottom = handle.bottom;
                        anchors.top = cell.bottom;
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

            }

            Rectangle {
                id: handle
                width: parent.width
                height: 20
                color: handleMouseArea.pressed ? "orange" : "red"

                MouseArea {
                    id: handleMouseArea
                    anchors.fill: parent
                    drag.target: handle
                    drag.axis: Drag.YAxis
                }
            }



        }
    }
    Component.onCompleted: {
        /*Qt.createQmlObject(
                    "import QtQuick 2.0;
                    Rectangle {
                    x:" + 50 + ";
                    y:" + 50 + ";
                    width: 100;
                    height: 100" +";
                    color: \"blue\""
                    +";"

                    +"}"
                    ,handle );*/

        //FUNCIONAL
        /*
        Qt.createQmlObject(
                    "import QtQuick 2.0;
                           Rectangle {
                           x:" + 50 + ";
                           y:" + 50 + ";
                           z:1;
                           width: 100;
                           height: 100" +";
                           color: \"pink\""
                           +";"

                           +"}"
                           , cell);
        */
        //PRUEBA:
        Qt.createQmlObject(
               'Rectangle {
                id: content;
                property bool handleOnTop: true;
                property bool lastConfig: true;
                anchors.top: handle.top;
                width: parent.width;
                color: contentMouseArea.pressed ? "orange" : "blue";

                MouseArea {
                    id: contentMouseArea;
                    //anchors.fill: parent;
                    /*drag.target: cell;
                    onWheel: {
                        if (wheel.modifiers & Qt.ControlModifier) {
                            content.rotation += wheel.angleDelta.y / 120 * 5;
                            if (Math.abs(content.rotation) < 4)
                                content.rotation = 0;
                        } else {
                            content.rotation += wheel.angleDelta.x / 120;
                            if (Math.abs(content.rotation) < 0.6)
                                content.rotation = 0;
                            var scaleBefore = content.scale;
                            content.scale += content.scale * wheel.angleDelta.y / 120 / 10;
                        }
                    }*/
                }
               }'
                    , root);




        /*
        if (component.status == Component.Ready)
                finishCreation();
            else
                component.statusChanged.connect(finishCreation);*/

    }
    function createNewRectangle(){
        Qt.createQmlObject(
            "import QtQuick 2.0;
                   Rectangle {
                   x:" + 50 + ";
                   y:" + 50 + ";
                   z:1;
                   width: 100;
                   height: 100" +";
                   color: \"pink\""
                   +";"

                   +"}"
                   , parent);
    }


    /*
    function finishCreation() {
        if (component.status == Component.Ready) {
            sprite = component.createObject(root, {"x": 50, "y": 50});
            if (sprite == null) {
                // Error Handling
                console.log("Error creating object");
            }
        } else if (component.status == Component.Error) {
            // Error Handling
            console.log("Error loading component:", component.errorString());
        }
    }*/
}
