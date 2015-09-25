import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    width: 420;
    height: 660;

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#f6f6f6" }
        GradientStop { position: 1.0; color: "#d7d7d7" }
    }

    GridView {
        id: arena;
        x: 10; y: 10;
        width: 400; height: 550;
        //rows: 16; columns: 10; spacing: 0;
        cellHeight: 40; cellWidth: 40;
        model: gridModel;

        delegate: Component{
            Rectangle {
                id: square
                width: arena.cellWidth; height: arena.cellHeight; color: "pink";
                border.color: "black";
                Text{ anchors.centerIn: parent; text: value }
                MouseArea {
                    anchors.fill: parent;
                    onClicked: { arena.currentItem.color = "pink"; parent.color = "blue"; arena.currentIndex = index }


                }
            }
        }
    }
    ListModel {
        id: gridModel
        ListElement {value: 1}
        ListElement {value: 2}
        ListElement {value: 3}
        ListElement {value: 4}
        ListElement {value: 5}
        ListElement {value: 6}
        ListElement {value: 7}
        ListElement {value: 8}
        ListElement {value: 9}
        ListElement {value: 10}
        ListElement {value: 11}
        ListElement {value: 12}
        ListElement {value: 13}
        ListElement {value: 14}
        ListElement {value: 15}
        ListElement {value: 16}
        ListElement {value: 17}
        ListElement {value: 18}
        ListElement {value: 19}
        ListElement {value: 20}
        ListElement {value: 21}
        ListElement {value: 22}
        ListElement {value: 23}
        ListElement {value: 24}
        ListElement {value: 25}
        ListElement {value: 26}
        ListElement {value: 27}
        ListElement {value: 28}
        ListElement {value: 29}
        ListElement {value: 30}
        ListElement {value: 31}
        ListElement {value: 32}
        ListElement {value: 33}
        ListElement {value: 34}
        ListElement {value: 35}
        ListElement {value: 36}
        ListElement {value: 37}
        ListElement {value: 38}
        ListElement {value: 39}
    }
    Keys.onRightPressed: {
        gridModel.move(arena.currentIndex, arena.currentIndex+1, 1)
    }
    Keys.onLeftPressed: {
        gridModel.move(arena.currentIndex, arena.currentIndex-1, 1)
    }
    Keys.onUpPressed: {
        gridModel.move(arena.currentIndex, arena.currentIndex-10, 1)
        gridModel.move(arena.currentIndex-9, arena.currentIndex, 1)
    }
    Keys.onDownPressed: {
        gridModel.move(arena.currentIndex, arena.currentIndex+10, 1)
        gridModel.move(arena.currentIndex+9, arena.currentIndex, 1)
    }

    focus: true;
}

