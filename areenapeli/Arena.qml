import QtQuick 2.3

Rectangle {
    id: arena;
    width: 420
    height: 660

    GridView {
        id: gridModel
        x: 10; y: 10;
        width: 450; height: 550;
        cellWidth: 70; cellHeight: 70
        model: myModel
        delegate: Rectangle { color: decoration }

    }
}


