
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick 2.12

ApplicationWindow {
    id: appwindow
    color: "#04060E"
    visible: true
    visibility: "Maximized"
    menuBar: MenuBar {
        background: Rectangle {
            color: appwindow.color
        }
        delegate: MenuBarItem {
            id: menuBarItem
            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                opacity: enabled ? 1.0 : 0.3
                color: menuBarItem.highlighted ? "#000000" : "#FFFFFF"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 40
                implicitHeight: 40
                opacity: enabled ? 1 : 0.3
                color: menuBarItem.highlighted ? "white" : "#04060E"
            }
        }
        Menu {
            title: {
                qsTr("File")
            }

            Action {
                text: qsTr("&New")
            }
            Action {
                text: qsTr("&Open...")
            }
            Action {
                text: qsTr("&Open recent")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Save")
            }
            Action {
                text: qsTr("&Save as...")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Quit")
            }
        }
        Menu {
            title: qsTr("Settings")
            Action {
                text: qsTr("&Show menubar")
            }
            Action {
                text: qsTr("&Show statusbar")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Theme")
            }
            Action {
                text: qsTr("&Grid")
            }
            MenuSeparator {
            }
            Action {
                text: qsTr("&Configure shortcurts")
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
    header: ToolBar {
        height: 40
        background: Rectangle {
            color: appwindow.color
        }
        RowLayout {
            id: buttons
            Button {
                id: plotdict
                text: qsTr(" Plot Dictionaries")

                contentItem: Text {
                    text: plotdict.text
                    font: plotdict.font
                    opacity: enabled ? 1.0 : 0.3
                    color: plotdict.down ? "grey" : "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    color: "#04060E"
                    height: 40
                }
            }
            Button {
                id: add2d
                text: qsTr("Add 2D Space")

                contentItem: Text {
                    text: add2d.text
                    font: add2d.font
                    opacity: enabled ? 1.0 : 0.3
                    color: add2d.down ? "grey" : "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    color: "#04060E"
                    height: 40
                }
                property string typeSpace: "2D"
                onClicked: {
                    mySpace.insertSpace(typeSpace)
                }
            }
            Button {
                id: add3d
                text: qsTr("Add 3D Space")

                contentItem: Text {
                    text: add3d.text
                    font: add3d.font
                    opacity: enabled ? 1.0 : 0.3
                    color: add3d.down ? "grey" : "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    color: "#04060E"
                    height: 40
                }
                property string typeSpace: "3D"
                onClicked: {
                    mySpace.insertSpace(typeSpace)
                }
            }
        }
    }
    footer: TabBar {
        Text {
            // ...
        }
    }

    RowLayout {
        anchors.fill: parent
        Rectangle {
            color: appwindow.color
        }

        KhipuSpaceViewer {
            id: mySpace
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Khipu2DMenu {
            visible: false // khipuModel.currentSpaceIs2d
        }

        Khipu3DMenu {
            visible: false // khipuModel.currentSpaceIs2d
        }

        KhipuScreen {
            id: blackscreen
            Layout.fillWidth: true
            Layout.fillHeight: true

        }
    }
}
