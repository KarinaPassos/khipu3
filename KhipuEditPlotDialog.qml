import QtQuick 2.2
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

/*
    This file represents the dialog window that opens when the user want to edit a plot
*/

Window {
    title: "Edit your plot"
    minimumHeight: 175
    minimumWidth: 310
    property var colorChecker: 0
    ColumnLayout{
        spacing: 30
        anchors.centerIn: parent
        RowLayout{
            Text{ text: "Expression: " }
            TextField{
                id: editExpression
            }
        }
        RowLayout{
            spacing: 30
            RowLayout{
                Text{ text: "Color" }
                Button {
                    text: "select"
                    onClicked: plotColorDialog.visible = true
                }
            }
            RowLayout{
                Text{ text: "Visibility: " }
                CheckBox{
                    id: setVisibility
                    checked: true
                }
            }
        }
        Button{
            text: "Send changes"
            onClicked: {
                proxyModel.sourceModel.setVisibility(setVisibility.checked)
                if (editExpression.text != ""){
                    proxyModel.sourceModel.setExpression(editExpression.text)
                }
                if (colorChecker === 1){
                    proxyModel.sourceModel.setColor(plotColorDialog.color)
                }
            }
        }

        ColorDialog{
            id: plotColorDialog
            visible: false
            onAccepted: {
                colorChecker = 1
                plotColorDialog.close()
            }
        }
    }
}
