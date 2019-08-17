import QtQuick 2.0
import QtQuick.Window 2.13
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

/*
    This file represents the window that opens when you click on MenuBar > Settings > Grid Settings
*/

Window {
    minimumHeight: 150
    minimumWidth: 200
    ColumnLayout{
        spacing: 20
        anchors.centerIn: parent
        RowLayout{
            Text{
                text: "Grid style"
            }
            ComboBox{
                model: ["None","Lines","Polar"]
            }
        }
        RowLayout{
            Text {
                text: "Grid Color"
            }
            Button {
                text: "select"
                onClicked: colorDialog.visible = true
            }
        }
    }
    ColorDialog{
        id: colorDialog
        visible: false
        onAccepted: {
            console.log("You chose: " + colorDialog.color)
            colorDialog.close()
        }
    }
}
