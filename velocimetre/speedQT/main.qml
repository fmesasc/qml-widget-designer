import QtQuick 2.2
import QtQuick.Window 2.1
import "content"

Window {
    visible: true
    width: 1200
    height: 700
    Rectangle{
        width: parent.width; height: parent.height
        Image{
            id : fons
            width: parent.width; height: parent.height
            anchors.centerIn: parent
            source: "qrc:/img/tramontana_Background_01.png"
        }
        /*
        gradient: Gradient {

            GradientStop { position: 1.0; color: "white" }
            GradientStop { position: 0.0; color: "black" }
        }*/
        //color: "#c0c0c0"

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            spacing: 5

            Rectangle {
                width: 500;
                //height: 500
                Velocimeter{
                    anchors.centerIn: parent
                    angle: 50
                }
            }

            Rectangle {
                width: -500;
                /*Velocimeter{
                    anchors.centerIn: parent
                    angle: 50
                }*/
                Rpm{
                    anchors.centerIn: parent
                }
            }
        }
        focus: true
    }
}
