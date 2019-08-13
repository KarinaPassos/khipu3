import QtQuick 2.2
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

Window {
    id: renameWindow
    width: 250
    maximumWidth: 250
    height: 250
    maximumHeight: 250
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 20
        Text { text: "Edit selected space name" }
        ColumnLayout{
            Text {
                text: "Space name:"
            }
            TextField {
                id: spaceName
            }
        }
        Button {
            Text{
                text: "Save"
                anchors.centerIn: parent
            }
            onClicked: {
                khipuModel.rename(spaceName.text)
                renameWindow.close()
            }
        }
    }
}