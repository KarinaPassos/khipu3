import QtQuick 2.2
import QtQuick.Controls 2.13

/*
    This file represents the button that makes the space menu open or close
*/

Button {
    id: hideshow
    text: "≡"

    background: Rectangle {
    }

    contentItem: Text {
        text: hideshow.text
        font: hideshow.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
}

