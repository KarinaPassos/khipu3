import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.0


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
        focus: true
    }

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        Layout.fillWidth: true
        Button {
            Text {
                text: "Rename"
                anchors.centerIn: parent
            }
            onClicked: {
                if (khipuModel.rowCount() > 0)
                    renameWindow.visible = true
            }
        }
        Button {
            Text {
                text: "Remove"
                anchors.centerIn: parent
            }
            onClicked: {
                khipuModel.removeSpace(spacesList.currentIndex)
                if (currentIndex>0)
                    currentIndex=currentIndex-1
            }
        }
    }
    KhipuRenameSpace{
        id: renameWindow
    }
}
