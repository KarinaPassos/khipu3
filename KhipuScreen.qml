import QtQuick 2.2
import QtQuick.Controls 2.12
import org.kde.analitza 1.1

Rectangle {
    id: plotscreen
    signal changeScreen()
    color: "black"

    function addFunction(str){
            khipuModel.currentSpace.addPlot(khipuModel.functionFixing(str))
    }

    Graph2D{
        id: space2d
        anchors.fill: parent
        model: khipuModel.currentSpace.model()
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "2D" : false
    }
    Graph3D{
        id: space3d
        anchors.fill: parent
        model: khipuModel.currentSpace.model()
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "3D" : false
        onModelChanged: resetViewport()
    }
}
