import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import QtQuick 2.0


    ApplicationWindow {
        visible: true
        menuBar: MenuBar {
                  Menu {
                      title: qsTr("&File")
                      Action { text: qsTr("&New") }
                      Action { text: qsTr("&Open...") }
                      Action { text: qsTr("&Open recent") }
                      MenuSeparator { }
                      Action { text: qsTr("&Save") }
                      Action { text: qsTr("&Save as...") }
                      MenuSeparator { }
                      Action { text: qsTr("&Quit") }
                  }
                  Menu {
                      title: qsTr("&Settings")
                      Action { text: qsTr("&Show menubar") }
                      Action { text: qsTr("&Show statusbar") }
                      MenuSeparator { }
                      Action { text: qsTr("&Theme") }
                      Action { text: qsTr("&Grid") }
                      MenuSeparator { }
                      Action { text: qsTr("&Configure shortcurts") }
                  }
                  Menu {
                      title: qsTr("&Help")
                      Action { text: qsTr("&Khipu Handbook") }
                      Action { text: qsTr("&What's this?") }
                      MenuSeparator { }
                      Action { text: qsTr("&Report bug") }
                      MenuSeparator { }
                      Action { text: qsTr("&Donate") }
                      MenuSeparator { }
                      Action { text: qsTr("&Switch application language") }
                      MenuSeparator { }
                      Action { text: qsTr("&About Khipu") }
                      Action { text: qsTr("&About KDE") }
                  }
        }
        header: ToolBar {
            RowLayout{
                id: buttons
                Button {
                  text: "Plot dictionaries"
                }
                Button {
                  text: "Add 2d Space"
                }
                Button {
                  text: "Add 3d Space"
                }
            }
        }
        footer: TabBar {
            Text {
               // ...
            }
        }
        RowLayout{
            id: layout
            spacing: 250
            ColumnLayout{
                RowLayout{
                    Text{
                        text: "     Search: "
                    }
                    TextInput {
                        maximumLength: 25
                        text: "type space name or number"
                        cursorVisible: false
                    }
                }
                ListModel {
                    id: spacesModel
                    ListElement {
                        name: "2D Space"
                        number: 0
                    }
                    ListElement {
                        name: "2D Space 1"
                        number: 1
                    }
                    ListElement {
                        name: "3D Space"
                        number: 2
                    }
                    ListElement {
                        name: "2D Space 2"
                        number: 3
                    }
                }
                ListView {
                    width: 180; height: 200
                    model: spacesModel
                    delegate: Text {
                        text: "name: " + name + "\nnumber: " + number
                    }
                }
            }
            Text {
               text: "screen"
            }
        }
    }