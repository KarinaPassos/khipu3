import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import org.kde.analitza 1.1

Window {
    width: maximumWidth
    height: maximumHeight
    color: "#04060E"
    RowLayout{
        Rectangle{
            color: "#393939"
            width: 330
            height: maximumHeight
            ColumnLayout{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20
                RowLayout{
                    Text{ color: "white"; text: "Select dimension: "}
                    ComboBox{
                        model: ["2D examples","3D examples"]
                        //ComboBoxStyle{/*textColor: "black"*/}
                        onCurrentIndexChanged: dictModel.currentSpace = dictModel.spaceAt(currentIndex)
                    }
                }
                Rectangle{
                    color: "black"
                    height: maximumHeight
                    width: 300
                    ListView{
                        id: dictionaries
                        model: dictModel.currentSpace.model()
                        currentIndex: 0
                        delegate:
                            Item{
                                height: 20
                                width: parent.width
                                Text{ color: "white"; text: "  " + description }
                            }
                        highlight: Rectangle {
                            color: "lightsteelblue"
                        }
                        highlightFollowsCurrentItem: true
                        focus: true
                    }
                }
            }
        }
        /*KhipuScreen {
            id: screen
            color: "black"
            height: 1000
            width: 1000
        }*/
        /*Graph2D{
            id: dict2d
            anchors.fill: parent
            model: dictModel.currentSpace.model()
            visible: dictModel.currentSpace ? dictModel.currentSpace.type === "2D" : false
        }
        Graph3D{
            id: dict3d
            anchors.fill: parent
            model: dictModel.currentSpace.model()
            visible: dictModel.currentSpace ? dictModel.currentSpace.type === "3D" : false
            onModelChanged: resetViewport()
        }*/
    }
}
