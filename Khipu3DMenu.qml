import QtQuick 2.2
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
Item {
    Layout.minimumWidth: menuOptions.visible ? 350 : hideMenu.width

    Rectangle {
        id: background
        anchors.fill: parent
    }

    ColumnLayout {
        id: menu3d
        anchors.fill: parent
        KhipuMenu {
            id: hideMenu
            Layout.alignment: Qt.AlignRight
            onClicked: {
                menuOptions.visible = !menuOptions.visible
            }
        }

        KhipuMenuOptions {
            id: menuOptions
            Layout.minimumWidth: 350
            Layout.maximumWidth: 350
            Layout.fillHeight: true
            /*ColumnLayout {
                Text {
                    color: "white"
                    text: "\nBuild a cartesian surface"
                }

                RowLayout {
                    Button {
                        id: graph3d
                        text: "Graph"
                        contentItem: Text {
                            text: graph3d.text
                            font: graph3d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }

                    Button {
                        id: implicit3d
                        text: "Implicit"
                        contentItem: Text {
                            text: implicit3d.text
                            font: implicit3d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }

                    Button {
                        id: parametric3d
                        text: "Parametric"
                        contentItem: Text {
                            text: parametric3d.text
                            font: parametric3d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                Text {
                    color: "white"
                    text: "\nBuild a cylindrical surface"
                }

                Button {
                    id: cylindrical3d
                    text: "Graph"
                    contentItem: Text {
                        text: cylindrical3d.text
                        font: cylindrical3d.font
                        color: "#000000"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                }

                Text {
                    color: "white"
                    text: "\nBuild a space curve"
                }

                Button {
                    id: spacecurve
                    text: "Parametric"
                    contentItem: Text {
                        text: spacecurve.text
                        font: spacecurve.font
                        color: "#000000"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                }

                Rectangle {
                    color: "white"
                    height: 100
                    width: 1
                }
            }*/
        }
        Item {
            Layout.fillHeight: true
        }
    }
}
