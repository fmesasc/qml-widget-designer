import QtQuick 2.2;
import QtQuick.Window 2.1;
import "content";

Item {
    visible: true;
    width: 1200;
    height: 700;
    Rectangle{
        width: parent.width; height: parent.height;
        Image{
            id : fons;
            width: parent.width; height: parent.height;
            anchors.centerIn: parent;
            source: "qrc:/img/Background_01.png";
        }
        transitions: Transition {
                AnchorAnimation { duration: 1000; }
        }
        Row {
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            spacing: 5;
            Rectangle {
                width: 500;
                id : recta;
                Velocimeter{
                    id: vel;
                    angle: 50;
                    anchors.centerIn: parent;
                }
            }

            Rectangle {
                width: -500;
                Rpm{
                    id: rpm;
                    anchors.centerIn: parent;
                }
            }
        }
    }

    Component.onCompleted: {
        vel.showFront();
        rpm.showFront();
    }

}
