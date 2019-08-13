import QtQuick 2.2
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

Window {
    id: addWindow
    width: 250
    maximumWidth: 250
    height: 250
    maximumHeight: 250
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 20
        Text { text: "Add a space" }
        ColumnLayout{
            Text {
                text: "Space name:"
            }
            TextField {
                id: spaceName
                onAccepted: {
                    khipuModel.addSpace(text,"2D")
                    close()
                }
            }
        }
        ColumnLayout{
            Text {
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
