import QtQuick 2.3
GridView {

    width: 500; height: 500;
    model: myModel
    delegate: Rectangle {
        width: 50; height: 50;
        color: color_

    }

<<<<<<< HEAD
=======
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
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
}

