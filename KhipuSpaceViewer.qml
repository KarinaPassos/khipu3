import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

ColumnLayout {
    id: bg
    spacing: 20

    property var currentIndex: spacesList.currentIndex
    property QtObject currentSpace

    function insertSpace(type) {
        khipuModel.addSpace(type + " space",type)
        if (currentIndex == 0){
            blackscreen.changeScreen()
        }
    }

    function getCurrentIndex() {
        return currentIndex
    }

    function getCurrentSpace() {
        return currentSpace
    }

    TextField {
        placeholderText: qsTr("Search")
        textColor: "#3982B8"
    }

    ListView {
        id: spacesList
        model: khipuModel
        currentIndex: 0

        Layout.fillHeight: true
        Layout.fillWidth: true

        onCurrentIndexChanged: {
            currentSpace = khipuModel.spaceAt(currentIndex)
            plotModel.setPlotList(currentSpace)
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
