import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: menu2d
    height: parent.height; width: 300; color: "grey"
    Button {
        text: "plot a curve"
        width: 200
        height: 100
        y: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }
}