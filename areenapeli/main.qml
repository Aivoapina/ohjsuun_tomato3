import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: item
    visible: true
    height: 660; width: 620
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
                    onClicked: {
                        grid.currentIndex = index
                        myModel.playerChangedIndex(index)
                    }
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
        Component.onCompleted: grid.currentIndex = myModel.m_index
    }
    Keys.onRightPressed: {
        myModel.liikuJohonkin("right", grid.currentIndex)
        grid.currentIndex = myModel.m_index
    }
    Keys.onLeftPressed: {
        myModel.liikuJohonkin("left", grid.currentIndex)
        grid.currentIndex = myModel.m_index
    }
    Keys.onUpPressed: {
        myModel.liikuJohonkin("up", grid.currentIndex)
        grid.currentIndex = myModel.m_index
    }
    Keys.onDownPressed: {
        myModel.liikuJohonkin("down", grid.currentIndex)
        grid.currentIndex = myModel.m_index
    }
    Button {
        id: endTurn
        x: 420; y: 230
        width: 270
        text: "Lopeta vuoro"
        onClicked: {
            myModel.endTurn()
            grid.currentIndex = myModel.m_index
        }
    }
    Dirbuttons{
        x: 460; y: 300
    }



    /*Connections {
        target: myModel
        onM_indexChanged: {
            grid.currentIndex = myModel.m_index
            grid.currentItem.picborder.border.color = "black"
        }

    }*/

    focus: true

}

