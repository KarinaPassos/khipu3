import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

ColumnLayout {
    spacing: 30

    RowLayout {
        Layout.alignment : Qt.AlignHCenter
        Text {
            text: qsTr("Add a function: ")
            color: "white"
        }
        TextField {
            id: consoleInput
            textColor: "#393939"
            onAccepted: {
                blackscreen.addFunction(text)
                consoleInput.text = ""
            }
        }
    }

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "black"
        ListView{
            id: plotView
            anchors.fill: parent
            model: plotModel
            currentIndex: 0
            delegate:
                Item{
                    height: 20
                    width: parent.width
                    Text{ color: "white"; text: "  " + expression }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            plotView.currentIndex = index
                        }
                    }
                }
            highlight: Rectangle {
                color: "lightsteelblue"
            }
            highlightFollowsCurrentItem: true
            focus: true
        }
    }

    RowLayout {
        Layout.alignment : Qt.AlignHCenter
        Button{
            Text{
                anchors.centerIn: parent
                text: "Edit"
                color: "#000000"
            }
        }
        Button{
            Text{
                anchors.centerIn: parent
                text: "Remove"
                color: "#000000"
            }
        }
    }
}
