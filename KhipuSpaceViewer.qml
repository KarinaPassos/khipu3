import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Rectangle {
    id: bg
    width: 300
    height: parent.height
    color: "#0D1A24"
    radius: 15

    function insertSpace(type) {
        khipuModel.addSpace(type + " space",type,khipuModel.rowCount())
    }

    function changeBlackscreen(item) {
        blackscreen.changeScreen(item.name)
    }

    ColumnLayout {
        spacing: 20
        Rectangle {
            color: bg.color
            height: 10
            width: bg.width
            radius: 15
        }
        Rectangle {
            color: bg.color
            radius: bg.radius
            width: bg.width
            height: 30
            TextField {
                anchors.centerIn: parent
                height: 35
                width: bg.width - 20
                placeholderText: qsTr("Search")
                textColor: "#3982B8"
            }
        }

        ListView {
            id: spacesList
            width: 300
            height: 600
            model: khipuModel

            delegate: Component {
                Item {
                    width: bg.width
                    height: 60
                    Column {
                        RowLayout {
                            spacing: 10
                            Rectangle {
                                width: 5
                                height: 60
                                color: bg.color
                            }
                            Rectangle {
                                width: 40
                                height: 40
                                color: "white"
                                radius: 50
                            }
                            ColumnLayout {
                                Text {
                                    color: "white"
                                    text: '<b>Name:</b> ' + name
                                }
                                RowLayout{
                                    spacing: 10
                                    Text {
                                        color: "white"
                                        text: '<b>Type:</b> ' + type
                                    }
                                    Text {
                                        color: "white"
                                        text: '  <b>ID:</b> ' + id
                                    }
                                }
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            spacesList.currentIndex = index
                            changeBlackscreen(spacesList.currentIndex)
                        }
                    }
                }
            }

            highlight: Rectangle {
                color: "lightsteelblue"
            }
            highlightFollowsCurrentItem: true
            focus: true
        }

        Rectangle {
            color: bg.color
            width: bg.width
            height: 50
            RowLayout {
                anchors.centerIn: parent
                Button {
                    Text {
                        text: "Rename"
                        color: "#000000"
                        anchors.centerIn: parent
                    }
                }
                Button {
                    Text {
                        text: "Remove"
                        color: "#000000"
                        anchors.centerIn: parent
                    }
                    onClicked: khipuModel.removeSpace(spacesList.currentIndex)
                }
            }
        }
    }
}
