import QtQuick 2.3

Rectangle {
    id: arena;
    width: 420
    height: 660

    Grid {
        id: gridModel
        x: 10; y: 10;
        width: 450; height: 550;
        rows: 16; columns: 10; spacing: 0;

        Repeater{
            model: 160;
            Rectangle {
                id: square
                width: 40; height: 40; color: "pink";
                border.color: "black";
                MouseArea {
                    anchors.fill: parent;
                    onClicked: { parent.color = "blue"; }
                }
                //Image {
                //    source: "../../areenatiedostot/kuvat/bullmentula_ingame.png"
                //    anchors.fill: parent
                //}
            }
        }
    }
}
