import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick.Window 2.13
import QtQuick 2.2
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: appwindow
    visible: true
    visibility: "Maximized"
    menuBar: MenuBar {
        id: khipuMenuBar
        background: Rectangle {
        }
        delegate: MenuBarItem {
            id: menuBarItem
            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                opacity: enabled ? 1.0 : 0.3
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 40
                implicitHeight: 40
                opacity: enabled ? 1 : 0.3
            }
        }
        Menu {
            title: {
                qsTr("File")
            }

            Action {
                text: qsTr("&Open...")
                onTriggered: fileDialog.visible = true
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Save")
                onTriggered: saveDialogBar.visible = true //deveria estar abrindo um dialog
            }
            /*Action {
                text: qsTr("&Save as...")
                onTriggered: saveDialogBar.visible = true //deveria estar abrindo um dialog
            }*/
            MenuSeparator {
            }
            Action {
                text: qsTr("&Quit")
                onTriggered: close()
            }
        }
        Menu {
            title: qsTr("Settings")
            Action {
                text: qsTr("&Hide menubar")
                onTriggered: {
                    khipuMenuBar.visible = false
                    menuBarAlert.visible = true
                }
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Grid settings")
                onTriggered: gridSettings.visible = true
            }
        }
        Menu {
            title: qsTr("Help")
            Action {
                text: qsTr("&Khipu Handbook")
            }
            Action {
                text: qsTr("&What's this?")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Report bug")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Donate")
            }
            MenuSeparator {
            }
            /*Action {
                text: qsTr("&Switch application language")
            }
            MenuSeparator {
            }*/
            Action {
                text: qsTr("&About Khipu")
            }
            Action {
                text: qsTr("&About KDE")
            }
        }
    }
    Keys.onPressed: {
        if (event.key === Qt.Key_F1) {
            console.log("entrou aqui")
            khipuMenuBar.visible = true
        }
    }
    Window{
        id: menuBarAlert
        visible: false
        minimumHeight: 50
        minimumWidth: 300
        Text{ anchors.centerIn: parent; text: "press F1 to show Menu Bar again" }
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a .json file"
        onAccepted: {
            //console.log("You chose: " + fileDialog.fileUrl)
            khipuModel.load(fileUrl)
        }
        onRejected: {
            console.log("Canceled")
            fileDialog.close()
        }
    }
    Khipu2DGridSettings {
        id: gridSettings
        visible: false
    }
    header: ToolBar {
        height: 40
        background: Rectangle {
        }
        RowLayout {
            id: buttons
            Button {
                id: plotdict
                text: qsTr(" Plot Examples")

                contentItem: Text {
                    text: plotdict.text
                    font: plotdict.font
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    height: 40
                }

                onClicked: {
                    khipuModel.plotDict()
                }
            }
            Button {
                id: add2DSpace
                text: qsTr("Add 2D Space")

                contentItem: Text {
                    text: add2DSpace.text
                    font: add2DSpace.font
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    height: 40
                }
                onClicked: {
                    khipuModel.addSpace("2D Space","2D")
                    khipuModel.currentSpace = khipuModel.spaceAt(khipuModel.rowCount() - 1)
                    khipuMenu.visible = true
                }
            }
            Button {
                id: add3DSpace
                text: qsTr("Add 3D Space")

                contentItem: Text {
                    text: add3DSpace.text
                    font: add3DSpace.font
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    height: 40
                }
                onClicked: {
                    khipuModel.addSpace("3D Space","3D")
                    khipuModel.currentSpace = khipuModel.spaceAt(khipuModel.rowCount() - 1)
                    khipuMenu.visible = true
                }
            }
        }
    }
    footer: TabBar {
        Text {
            // ...
        }
    }
    ColumnLayout{
        anchors.fill: parent
        RowLayout {
            id: saveDialogBar
            visible: false
            TextField{
                id: saveInput
                text: "Type file name here"
                width: parent.width
                onAccepted: {
                    khipuModel.save(text)
                    text = ""
                    saveDialogBar.visible = false
                }
            }
            Button{
                text: "Save"
                onClicked: {
                    khipuModel.save(saveInput.text)
                    saveDialogBar.visible = false
                }
            }
            Button{
                text: "Cancel"
                onClicked: saveDialogBar.visible = false
            }
        }
        RowLayout {
            Rectangle {
            }

            KhipuSpaceViewer {
                id: mySpace
                Layout.fillHeight: true
                Layout.maximumWidth: 300
                model: proxyModel
            }

            KhipuMenu {
                id: khipuMenu
                Layout.fillHeight: true
                visible: false
            }

            KhipuScreen {
                id: blackscreen
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
