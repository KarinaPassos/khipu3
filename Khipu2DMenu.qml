import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Item {
    Layout.minimumWidth: menuOptions.visible ? 350 : hideMenu.width

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#393939"
    }

    ColumnLayout {
        id: menu2d
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
                    text: "\nBuild a cartesian curve"
                }

                RowLayout {
                    Button {
                        id: graph2d
                        text: "Graph"
                        contentItem: Text {
                            text: graph2d.text
                            font: graph2d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                    Button {
                        id: implicit2d
                        text: "Implicit"
                        contentItem: Text {
                            text: implicit2d.text
                            font: implicit2d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                    Button {
                        id: parametric2d
                        text: "Parametric"
                        contentItem: Text {
                            text: parametric2d.text
                            font: parametric2d.font
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                Text {
                    color: "white"
                    text: "\nBuild a polar curve"
                }

                Button {
                    id: polar2d
                    text: "Graph"
                    contentItem: Text {
                        text: polar2d.text
                        font: polar2d.font
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
