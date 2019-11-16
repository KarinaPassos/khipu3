import QtQuick 2.2
import QtQuick.Controls 2.12
import org.kde.analitza 1.1

/*
    This file represents the 2d and 3d space visualization, and manages what will appear on the screen
*/

Rectangle {
    id: plotscreen
    signal changeScreen()

    function addFunction(str){
            proxyModel.sourceModel.currentSpace.addPlot(proxyModel.sourceModel.functionFixing(str))
    }

    Graph2D{
        id: space2d
        anchors.fill: parent
        model: proxyModel.sourceModel.currentSpace ? proxyModel.sourceModel.currentSpace.model() : null
        visible: proxyModel.sourceModel.currentSpace ? proxyModel.sourceModel.currentSpace.type === "2D" : false
    }
    Graph3D{
        id: space3d
        anchors.fill: parent
        model: proxyModel.sourceModel.currentSpace ? proxyModel.sourceModel.currentSpace.model() : null
        visible: proxyModel.sourceModel.currentSpace ? proxyModel.sourceModel.currentSpace.type === "3D" : false
        onModelChanged: resetViewport()
    }
}
