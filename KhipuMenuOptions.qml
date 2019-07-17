import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 30

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "black"
        ListView{
            anchors.fill: parent
            model: plotModel
            delegate: Text{ color: "white"; text: "expression: " + expression }
        }
    }
}
