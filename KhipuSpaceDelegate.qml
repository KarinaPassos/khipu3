import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick 2.2

/*
    This file represents the informations that will appear in the list view when you create a space
*/

MouseArea {
    width: parent.width
    height: 70
    RowLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            width: 5
            height: 70
        }

        Rectangle {
            width: 40
            height: 40
            radius: 50
        }

        ColumnLayout {
            RowLayout{
                Text {
                    text: 'Name:'
                    visible: !renameSpace.visible
                    font.bold: true
                }
                Text {
                    text: name
                    visible: !renameSpace.visible
                }
            }
            TextField{
                id: renameSpace
                height: 25
                visible: false
                onAccepted: { khipuModel.rename(renameSpace.text,spacesList.currentIndex); renameSpace.visible = false }
                text: "new space name"
                focus: true
            }
            RowLayout{
                Text {
                    text: 'Type:'
                    font.bold: true
                }
                Text {
                    text: type
                }
            }
        }
    }
    onClicked: {
        spacesList.currentIndex = index
    }
    onDoubleClicked: {
        renameSpace.visible = true
    }
}

