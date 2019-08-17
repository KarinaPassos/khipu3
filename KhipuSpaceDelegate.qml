import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick 2.2

/*
    This file represents the informations that will appear in the list view when you create a space
*/

Item {
    width: parent.width
    height: 60
    RowLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            width: 5
            height: 60
        }

        Rectangle {
            width: 40
            height: 40
            radius: 50
        }

        ColumnLayout {
            Text {
                text: '<b>Name:</b> ' + name
                visible: !renameSpace.visible
            }
            TextField{
                id: renameSpace
                height: 25
                visible: false
                onAccepted: { khipuModel.rename(renameSpace.text); renameSpace.visible = false }
                text: "new space name"
            }
            Text {
                text: '<b>Type:</b> ' + type
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            spacesList.currentIndex = index
        }
        onDoubleClicked: {
            renameSpace.visible = true
        }
    }
}

