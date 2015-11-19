import QtQuick 2.3


    GridView {
        id: gridView
        x: 10; y: 10;
        width: 450; height: 550;
        model: myModel
        delegate: Rectangle {color: color}
    }

/*
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
    }*/


