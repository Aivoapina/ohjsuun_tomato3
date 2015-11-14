import QtQuick 2.3

Rectangle {
    visible: true
    height: 660; width: 420
    Component{
        id: square
        Item {
            width: grid.cellWidth; height: grid.cellHeight
            Image{ height: 40; width: 40; source: decoration }
            Image{ anchors.fill: parent ;height: 40; width: 40; source: display }
        }
    }
    GridView {
        id: grid
        x: 10; y: 10;
        width: 400; height:640;
        cellWidth: 40; cellHeight: 40
        model: myModel
        delegate: square
        highlight: Rectangle { color: "red"; radius: 5 }
        focus: true
    }
}
