
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick 2.12

Item {
    width: parent.width
    height: 60
    RowLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            width: 5
            height: 60
            color: "#04060E"
        }

        Rectangle {
            width: 40
            height: 40
            color: "white"
            radius: 50
        }

        ColumnLayout {
            Text {
                color: "white"
                text: '<b>Name:</b> ' + name
            }
            RowLayout{
                spacing: 10
                Text {
                    color: "white"
                    text: '<b>Type:</b> ' + type
                }
                Text {
                    color: "white"
                    text: '  <b>ID:</b> ' + id
                }
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            spacesList.currentIndex = index
        }
    }
}

