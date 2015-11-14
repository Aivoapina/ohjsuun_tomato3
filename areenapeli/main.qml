import QtQuick 2.3

Rectangle {
    visible: true
    height: 660 ; width: 420
    /*Image {
        y: 122
        height: 300; anchors.horizontalCenterOffset: -43; width: 300
        source: "assets/grass_texture.jpg"
    }*/
    Component{
        id: square
        Rectangle{
            id: wrapper
            width: 60
            height: 60
            Text{
                text: display
            }
        }
    }

    Rectangle {
        id: arena;
        width: 420
        height: 660

        GridView {
            id: gridModel
            x: 10; y: 10;
            width: 400; height:640;
            cellWidth: 40; cellHeight: 40
            model: myModel
            delegate: Rectangle { width: 40; height: 40; color: display }
        }
    }
}
