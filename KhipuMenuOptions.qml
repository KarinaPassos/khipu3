import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

ColumnLayout {
    spacing: 30

    RowLayout {
        Layout.alignment : Qt.AlignHCenter
        Text {
            text: qsTr("Add a function: ")
        }
        TextField {
            id: consoleInput
            onAccepted: {
                blackscreen.addFunction(text)
                consoleInput.text = ""
            }
        }
    }

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        ListView{
            id: plotView
            anchors.fill: parent
            model: khipuModel.currentSpace ? khipuModel.currentSpace.model() : null
            currentIndex: 0
            delegate:
                Item{
                    height: 20
                    width: parent.width
                    Text{ text: "  " + description }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            plotView.currentIndex = index
                        }
                    }
                }
            highlight: Rectangle {
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
            }
        }
        Button{
            Text{
                anchors.centerIn: parent
                text: "Remove"
            }
            onClicked: khipuModel.removeFunction(plotView.currentIndex);
        }
    }

    /* you can put here future dimensional options, like:
        item2d{
            visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "2D" : false
            (...)
        }
        item3d{
            visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "3D" : false
            (...)
        }
    */
}
