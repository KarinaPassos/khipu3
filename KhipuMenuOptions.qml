import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

/*
    This file represents the menu options that appear on the menu
*/

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
            model: proxyModel.sourceModel.currentSpace ? proxyModel.sourceModel.currentSpace.model() : null
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
                            proxyModel.sourceModel.setPlotCurrentIndex(plotView.currentIndex)
                            editExpressionDialog.colorChecker = 0
                        }
                        onDoubleClicked: {
                            editExpressionDialog.visible = true
                        }
                    }
                }
            highlight: Rectangle { color: "lightsteelblue" }
            highlightFollowsCurrentItem: true
            focus: true
        }
    }
    KhipuEditPlotDialog{
        id: editExpressionDialog
    }

    RowLayout {
        Layout.alignment : Qt.AlignHCenter
        Button{
            Text{
                anchors.centerIn: parent
                text: "Remove"
            }
            onClicked: proxyModel.sourceModel.removeFunction(plotView.currentIndex);
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
