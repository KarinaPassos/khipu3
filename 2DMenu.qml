import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick 2.12
import QtQuick 2.6
import QtQuick.Controls 2.1

Rectangle {
    id: menu2d
    height: parent.height; width: 350; color: "#393939"
    radius: 5

    ColumnLayout{
        id: menu2dOptions
        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle{color: menu2d.color; height: 10; width: 30; radius: 15}
        Rectangle {
            height: 350; width: 305; color: "black"; radius: 3
            Text {
                text: qsTr(" Current plots")
                color: "white"
            }
        }

        spacing: 50

        ColumnLayout{
            Text{ color: "white"; text: "\nBuild a cartesian curve" }
            RowLayout{
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
            Text{ color: "white"; text: "\nBuild a polar curve" }
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

            Rectangle{color:menu2d.color; height:100; width:1}
            Button {
                id: hideshow
                text: "Hide/Show menu"
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
                    target: menu2d
                    property: "width"
                    duration: 200
                    from: 50
                    to: 350
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    id: hideAnimation
                    target: menu2d
                    property: "width"
                    duration: 200
                    from: 350
                    to: 50
                    easing.type: Easing.InOutQuad
                }

                onClicked:
                    if (menu2d.width==50){
                        showAnimation.start()
                    }
                    else if (menu2d.width=350){
                        hideAnimation.start()
                    }
            }

        }
    }
}
