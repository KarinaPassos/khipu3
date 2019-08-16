import QtQuick 2.2
import QtQuick.Controls 2.13


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

