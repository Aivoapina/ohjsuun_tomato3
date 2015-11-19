import QtQuick 2.3
GridView {

    width: 500; height: 500;
    model: myModel
    delegate: Rectangle {
        width: 50; height: 50;
        color: color_

    }

}

