import QtQuick 2.3

Rectangle {
    id: item
    visible: true
    height: 660; width: 420
    GridView {
        id: grid
        x: 10; y: 10
        width: 400; height: 640
        cellWidth: 40; cellHeight: 40
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
        model: myModel
        delegate: square
        Component.onCompleted: grid.currentIndex = -1
    }

    Keys.onRightPressed: {
        myModel.liikuJohonkin("right", grid.currentIndex)
        grid.moveCurrentIndexRight()
    }
    Keys.onLeftPressed: {
        myModel.liikuJohonkin("left", grid.currentIndex)
        grid.moveCurrentIndexLeft()
    }
    Keys.onUpPressed: {
        myModel.liikuJohonkin("up", grid.currentIndex)
        grid.moveCurrentIndexUp()
    }
    Keys.onDownPressed: {
        myModel.liikuJohonkin("down", grid.currentIndex)
        grid.moveCurrentIndexDown()
    }
    focus: true

}

