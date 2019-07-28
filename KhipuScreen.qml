import QtQuick 2.12
import QtQuick.Controls 2.12
import org.kde.analitza 1.1

Rectangle {
    id: plotscreen
    signal changeScreen()
    color: "black"

    function addFunction(str){
        if (khipuModel.currentSpace.type === "2D"){
            space2d.addFunction(khipuModel.functionFixing(str), khipuModel.variables)
        }
        if (khipuModel.currentSpace.type === "3D"){
            space3d.addFunction(khipuModel.functionFixing(str), khipuModel.variables)
        }
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
