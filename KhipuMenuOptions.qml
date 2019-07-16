import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    anchors.fill: parent
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    Rectangle {
        color: "pink"
        Layout.minimumHeight: 10
        Layout.fillWidth: true
    }

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "black"
        ListView{
            anchors.fill: parent
            model: plotModel
            delegate: Text{color: "white"; text: "expression: " + expression}
        }
    }
}
