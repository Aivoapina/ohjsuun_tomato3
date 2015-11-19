import QtQuick 2.5

Component{
    id: square
    Rectangle {
        id: wrapper
        width: grid.cellWidth; height: grid.cellHeight

        MouseArea {
            anchors.fill: parent
            onClicked: grid.currentIndex = index
        }

        states: [
            State {
                name: "none"
                when: (grid.currentIndex == -1)
            },
            State {
                name: "selected"
                when: wrapper.GridView.isCurrentItem
                PropertyChanges {
                    target: picborder
                    border.color: "black"
                }
            }
        ]
        Image{ height: 40; width: 40; source: decoration }
        Image{ anchors.fill: parent; height: 40; width: 40; source: display }
        Rectangle{
            id: picborder
            anchors.fill: parent
            height: 40; width: 40;
            color: "transparent"
            border.color: "transparent"
        }
    }
}

