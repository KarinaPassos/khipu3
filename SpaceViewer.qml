import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import QtQuick 2.0
import QtQuick.Controls 1.4


Rectangle {
    id: background
    color: "#393939"
    width: 250; height: parent.height

    function insertSpace(type) {
          spacesModel.insert(spacesModel.count, {"name": type + " Space", "number": spacesModel.count})
    }

    ListModel {
        id: spacesModel
    }

    ColumnLayout{
        spacing: 20
        Rectangle{ height: 2; color: "#393939" }
        RowLayout{
            Text{
                text: "   Search: "
                color: "#FFFFFF"
            }
            TextField {
                placeholderText: qsTr("Enter space identification")
                textColor: "#000000"
            }
        }

        RowLayout{
            Rectangle{ width: 10; height: 10; color: "#393939" }
            Text {
                text: " Spaces "
                color: "white"
            }
        }

        ListView {
            id: spacesList
            width: 180; height: 600;
            model: spacesModel

            delegate: Component {
                Item {
                    width: 180; height: 45
                    Column {
                        RowLayout{
                            Rectangle{ width: 5; height: 45; color: "#393939" }
                            spacing: 10
                            Rectangle{ width: 30; height: 30; color: "white" }
                            ColumnLayout{
                                Text { color: "white"; text: '<b>Name:</b> ' + name }
                                Text { color: "white"; text: '<b>Number:</b> ' + number }
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: spacesList.currentIndex = index
                    }
                }
            }

            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            highlightFollowsCurrentItem: true
            focus: true

            add: Transition {
                NumberAnimation { properties: "x,y"; from: 100; duration: 100 }
            }
        }

        RowLayout{
            Button {
                Text{
                    text: "     Rename"
                    color: "#000000"
                }
            }
            Button {
                Text{
                    text: "     Remove"
                    color: "#000000"
                }
            }
        }
    }

}
