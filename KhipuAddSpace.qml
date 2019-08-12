import QtQuick 2.2
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Window {
    id: addWindow
    width: 250
    maximumWidth: 250
    height: 250
    maximumHeight: 250
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 20
        Text { text: "Add a space"; color: "white" }
        ColumnLayout{
            Text {
                color: "#FFFFFF"
                text: "Space name:"
            }
            TextField {
                id: spaceName
                textColor: "#000000"
                onAccepted: {
                    khipuModel.addSpace(text,"2D")
                    close()
                }
            }
        }
        ColumnLayout{
            Text {
                color: "#FFFFFF"
                text: "Dimension:"
            }
            ComboBox {
                id: dimension
                width: 200
                model: ["2D", "3D"]
            }
        }
        Button {
            Text{
                color: "black"
                text: "Add"
                anchors.centerIn: parent
            }
            onClicked: {
                khipuModel.addSpace(spaceName.text,dimension.currentText)
                addWindow.close()
            }
        }
    }
}
