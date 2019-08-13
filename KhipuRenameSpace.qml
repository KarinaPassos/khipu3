import QtQuick 2.2
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Window {
    id: renameWindow
    width: 250
    maximumWidth: 250
    height: 250
    maximumHeight: 250
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 20
        Text { text: "Edit selected space name"; color: "white" }
        ColumnLayout{
            Text {
                color: "#FFFFFF"
                text: "Space name:"
            }
            TextField {
                id: spaceName
                textColor: "#000000"
            }
        }
        Button {
            Text{
                color: "black"
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