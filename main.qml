import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick 2.2
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: appwindow
    visible: true
    visibility: "Maximized"
    menuBar: MenuBar {
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
                onTriggered: khipuModel.save("testejson") //deveria estar abrindo um dialog
            }
            Action {
                text: qsTr("&Save as...")
                onTriggered: khipuModel.save("testejson2") //deveria estar abrindo um dialog
            }
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
                text: qsTr("&Show menubar")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Theme")
            }
            Action {
                text: qsTr("&Grid")
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
            Action {
                text: qsTr("&Switch application language")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&About Khipu")
            }
            Action {
                text: qsTr("&About KDE")
            }
        }
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a .json file"
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrl)
            khipuModel.load(fileUrl)
        }
        onRejected: {
            console.log("Canceled")
            fileDialog.close()
        }
    }
    /*FileDialog {
        id: saveDialog
        title: "Please choose a .json file"
        onAccepted: {
        }
        onRejected: {
        }
    }*/
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
                id: addSpace
                text: qsTr("Add Space")

                contentItem: Text {
                    text: addSpace.text
                    font: addSpace.font
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    height: 40
                }
                property string typeSpace: "2D"
                onClicked: {
                    addWindow.visible = true
                }
            }
        }
    }
    KhipuAddSpace{
        id: addWindow
    }
    footer: TabBar {
        Text {
            // ...
        }
    }

    RowLayout {
        anchors.fill: parent
        Rectangle {
        }

        KhipuSpaceViewer {
            id: mySpace
            Layout.fillHeight: true
            Layout.maximumWidth: 300
            model: khipuModel
        }

        Khipu2DMenu {
            Layout.fillHeight: true
            visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "2D" : false
        }

        Khipu3DMenu {
            Layout.fillHeight: true
            visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "3D" : false
        }

        KhipuScreen {
            id: blackscreen
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
