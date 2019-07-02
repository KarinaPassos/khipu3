import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: menu
    height: parent.height
    width: 350
    color: "#393939"
    radius: 5

    Button {
        id: hideshow
        text: "≡"
        x: 305
        y: 15

        background: Rectangle {
            color: "grey"
            width: 30
            height: 30
        }

        contentItem: Text {
            text: hideshow.text
            font: hideshow.font
            color: "#000000"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        NumberAnimation {
            id: showAnimation
            target: menu
            property: "width"
            duration: 200
            from: 60
            to: 350
            easing.type: Easing.InOutQuad
        }

        NumberAnimation {
            id: hideAnimation
            target: menu
            property: "width"
            duration: 200
            from: 350
            to: 60
            easing.type: Easing.InOutQuad
        }

        NumberAnimation {
            id: buttonShowAnimation
            target: hideshow
            property: "x"
            duration: 200
            from: 15
            to: 305
            easing.type: Easing.InOutQuad
        }

        NumberAnimation {
            id: buttonHideAnimation
            target: hideshow
            property: "x"
            duration: 200
            from: 305
            to: 15
            easing.type: Easing.InOutQuad
        }

        onClicked: {
            if (menu.width == 60) {
                buttonShowAnimation.start()
                showAnimation.start()
                menuOptions.visible = true
            } else if (menu.width == 350) {
                buttonHideAnimation.start()
                hideAnimation.start()
                menuOptions.visible = false
            }
        }
    }
}
