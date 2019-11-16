import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.0

/*
    This file represents the space manager that will be on the left of the screen+
*/

ColumnLayout {
    id: bg
    spacing: 20

    property alias currentIndex: spacesList.currentIndex
    property alias model : spacesList.model

    TextField {
        id: searchContent
        Layout.fillWidth: true
        placeholderText: qsTr("Search")
        onTextChanged: {
            proxyModel.setFilterRegExp(text)
            if (proxyModel.rowCount() === 0){
                text = ""
                proxyModel.setFilterRegExp(text)
            }
        }
    }

    ListView {
        id: spacesList
        currentIndex: 0

        Layout.fillHeight: true
        Layout.fillWidth: true

        onCurrentIndexChanged: {
            if (searchContent === ""){
                proxyModel.sourceModel.currentSpace = proxyModel.sourceModel.spaceAt(currentIndex)
            } else {
                proxyModel.sourceModel.currentSpace = proxyModel.sourceModel.spaceAt(proxyModel.mapToSource
                                                             (proxyModel.index(currentIndex,0)).row)
            }
        }

        delegate: KhipuSpaceDelegate {
        }

        highlightFollowsCurrentItem: true
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        //focus: true
    }

    Button {
        Text {
            text: "Remove"
            anchors.centerIn: parent
        }
        onClicked: {
            proxyModel.sourceModel.removeSpace(proxyModel.mapToSource
                                               (proxyModel.index(spacesList.currentIndex,0)).row)
            if (proxyModel.rowCount() === 0){
                searchContent.text = ""
            } else if (proxyModel.rowCount() === 0) {
                spacesList.currentIndex = proxyModel.rowCount() - 1
                proxyModel.sourceModel.currentSpace = proxyModel.sourceModel.spaceAt(currentIndex)
            }
        }
    }
}
