import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    Rectangle {
        color: parent.parent.color
        height: 30
        width: 30
        radius: 15
    }

    Rectangle {
        height: 350
        width: 305
        color: "black"
        radius: 3
        ListView{
            width: parent.width
            height: parent.height
            model: plotModel
            delegate: Text{color: "white"; text: "expression: " + expression}
        }
    }
}
