import QtQuick 2.12
import QtQuick.Controls 2.12
import org.kde.analitza 1.1

Rectangle {
    id: plotscreen
    signal changeScreen()
    color: "black"

    Graph2D{
        id: space2d
        anchors.fill: parent
        model: functionModel.functionsModel()
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "2D" : false
        Button {
            text: "2d button"
            onClicked: {
                //input.selectAll()
                space2d.addFunction("y=x**2", functionModel.variables)
                space2d.addFunction("y=x", functionModel.variables)
            }
        }
    }
    Graph3D{
        id: space3d
        anchors.fill: parent
        model: functionModel.functionsModel()
        visible: khipuModel.currentSpace ? khipuModel.currentSpace.type === "3D" : false
        Button {
            text: "3d button"
            onClicked: {
                var err = space3d.addFunction("x**2+y**2", functionModel.variables)
                if (err.length>0)
                    console.warn("errors:", err)
            }
        }
    }
}
