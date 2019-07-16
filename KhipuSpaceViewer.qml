import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

ColumnLayout {
    id: bg
    spacing: 20

    property alias currentIndex: spacesList.currentIndex
    property alias model : spacesList.model

    function insertSpace(type) {
        khipuModel.addSpace(type + " space",type)
    }

    TextField {
        Layout.fillWidth: true
        placeholderText: qsTr("Search")
        textColor: "#3982B8"
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
            color: "lightsteelblue"
        }

        highlightFollowsCurrentItem: true
        focus: true
    }

    RowLayout {
        Layout.fillWidth: true
        Button {
            Text {
                text: "Rename"
                color: "#000000"
                anchors.centerIn: parent
            }
        }
        Button {
            Text {
                text: "Remove"
                color: "#000000"
                anchors.centerIn: parent
            }
            onClicked: {
                khipuModel.removeSpace(spacesList.currentIndex)
                currentIndex=currentIndex-1
            }
        }
    }
}
