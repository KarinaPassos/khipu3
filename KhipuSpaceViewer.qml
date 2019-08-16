import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.0

/*
    This file represents the space manager that will be on the left of the screen
*/

ColumnLayout {
    id: bg
    spacing: 20

    property alias currentIndex: spacesList.currentIndex
    property alias model : spacesList.model

    TextField {
        Layout.fillWidth: true
        placeholderText: qsTr("Search")
        onTextChanged: {
            khipuModel.searchSpace("text")
        }
    }

    ListView {
        id: spacesList
        currentIndex: 0

        Layout.fillHeight: true
        Layout.fillWidth: true

        onCurrentIndexChanged: {
            khipuModel.currentSpace = khipuModel.spaceAt(currentIndex)
        }

        delegate: KhipuSpaceDelegate {
        }

        highlight: Rectangle {
        }

        highlightFollowsCurrentItem: true
        //focus: true
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Remove"
            anchors.centerIn: parent
        }
        onClicked: {
            khipuModel.removeSpace(spacesList.currentIndex)
            if (currentIndex>0){
                currentIndex=currentIndex-1
            }
        }
    }
}
