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
    id: menu3d
    height: parent.height; width: 350; color: "#393939"
    radius:5
    ColumnLayout{
        id: menu3dOptions
        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle{color: menu3d.color; height: 10; width: 30; radius: 15}
        Rectangle {
            height: 350; width: 305; color: "black"; radius: 3
            Text {
                text: qsTr(" Current plots")
                color: "white"
            }
        }

        spacing: 30

        ColumnLayout{
            Text{ color: "white"; text: "\nBuild a cartesian surface" }
            RowLayout{
                Button {
                    id: graph3d
                    text: "Graph"
                    contentItem: Text {
                        text: graph3d.text
                        font: graph3d.font
                        color: "#000000"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                }
                Button {
                    id: implicit3d
                    text: "Implicit"
                    contentItem: Text {
                        text: implicit3d.text
                        font: implicit3d.font
                        color: "#000000"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                }
                Button {
                    id: parametric3d
                    text: "Parametric"
                    contentItem: Text {
                        text: parametric3d.text
                        font: parametric3d.font
                        color: "#000000"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                }
            }
            Text{ color: "white"; text: "\nBuild a cylindrical surface" }
            Button {
                id: cylindrical3d
                text: "Graph"
                contentItem: Text {
                    text: cylindrical3d.text
                    font: cylindrical3d.font
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
            }
            Text{ color: "white"; text: "\nBuild a space curve" }
            Button {
                id: spacecurve
                text: "Parametric"
                contentItem: Text {
                    text: spacecurve.text
                    font: spacecurve.font
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
            }
            Rectangle{color:menu3d.color; height:100; width:1}
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
                    target: menu3d
                    property: "width"
                    duration: 200
                    from: 50
                    to: 350
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    id: hideAnimation
                    target: menu3d
                    property: "width"
                    duration: 200
                    from: 350
                    to: 50
                    easing.type: Easing.InOutQuad
                }

                onClicked:
                    if (menu3d.width==50){
                        showAnimation.start()
                    }
                    else if (menu3d.width=350){
                        hideAnimation.start()
                    }
            }

        }
    }
}
