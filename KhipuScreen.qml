import QtQuick 2.12

Rectangle {
    id: plotscreen
    signal changeScreen(string menu_type)
    color: "black"
    //height: 500 ; width: 500
    height: maximumHeight
    width: maximumWidth
}
