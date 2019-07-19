import QtQuick 2.12
import org.kde.analitza 1.1

Rectangle {
    id: plotscreen
    signal changeScreen()
    color: "black"

    Graph2D{
        id: space2d
        anchors.fill: parent
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "2D" : false
    }
    Graph3D{
        id: space3d
        anchors.fill: parent
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "3D" : false
    }
}
