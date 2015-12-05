import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: directionKeys
    width: 150; height: 150
    Button {
        id: up
        x: 75; y: 25
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 270 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("up", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }

    Button {
        id: upright
        x: 125; y: 25
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 315 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("upright", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: right
        x: 125; y: 75
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 0}
            }
        }
        onClicked: {
            myModel.liikuJohonkin("right", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: downright
        x: 125; y: 125
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 45 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("downright", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: down
        x: 75; y: 125
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 90 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("down", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: downleft
        x: 25; y: 125
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 135 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("downleft", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: left
        x: 25; y: 75
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 180 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("left", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
    Button {
        id: upleft
        x: 25; y: 25
        width: 50; height: 50
        style: ButtonStyle {
            background: Image {
                source: "assets/arrow.png"
                anchors.fill: parent
                transform: Rotation{ origin.x: 25; origin.y: 25; angle: 225 }
            }
        }
        onClicked: {
            myModel.liikuJohonkin("upleft", grid.currentIndex)
            grid.currentIndex = myModel.m_index
        }
    }
}
