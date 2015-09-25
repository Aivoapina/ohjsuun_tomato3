import QtQuick 2.0

Rectangle {
    id: fightingscene;
    width: 420
    height: 660

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#f6f6f6" }
        GradientStop { position: 1.0; color: "#d7d7d7" }
    }

    Grid {
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
                    onClicked: { parent.color = "blue"}
                }
            }
        }
    }
}

