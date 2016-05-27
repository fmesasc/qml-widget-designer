import QtQuick 2.0

Item {
    anchors.fill: parent;
    MouseArea {
        id: contentMouseArea;
        anchors.fill: parent;
        drag.target: cell;
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
/*
    onHandleOnTopChanged: {
        if (handleOnTop) {
            anchors.top = handle.top;
            anchors.bottom = cell.bottom;
        } else {
            anchors.bottom = handle.bottom;
            anchors.top = cell.bottom;
        }
    }*/

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
