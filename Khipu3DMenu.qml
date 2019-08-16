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
        KhipuHideMenuButton {
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
            /*
              3D Options
            */
        }
    }
}
