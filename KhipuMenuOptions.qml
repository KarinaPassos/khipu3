import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    Rectangle {
        color: parent.parent.color
    }

    Rectangle {
        color: "black"
        ListView{
            model: plotModel
            delegate: Text{color: "white"; text: "expression: " + expression}
        }
    }
}
