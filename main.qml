import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import QtQuick 2.0


ApplicationWindow {
    color: "#393939"
    visible: true
    visibility: "Maximized"
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
              text: "Add 2D Space"
              property var typeSpace: "2D"
              onClicked: {
                mySpace.insertSpace(typeSpace)
              }
            }
            Button {
              text: "Add 3D Space"
              property var typeSpace: "3D"
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

    RowLayout{
        Rectangle { width: 5; color: "#393939" }
        SpaceViewer {
            id: mySpace
        }
        KhipuScreen {
            id: screen
        }
    }

}
