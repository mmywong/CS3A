import QtQuick 2.0

Rectangle {
    id: page
    width: 360
    height: 360
    color: "#343434"

    Image {
        id: icon
        x: 0
        y: 20
        width: 80
        height: 73
        source: "miku.png"
    }

    Rectangle {
        id: topLeftRect
        width: 64
        height: 64
        color: "#00000000"
        radius: 6
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "#808080"

        MouseArea {
            anchors.fill: parent
            onClicked: page.state = ''
        }
    }

    Rectangle {
        id: middleRightRect
        x: 6
        y: -6
        width: 64
        height: 64
        color: "#00000000"
        radius: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        border.color: "#808080"
        MouseArea {
            anchors.fill: parent
            onClicked: page.state = 'State1'
        }
    }

    Rectangle {
        id: bottomLeftRect
        x: 4
        y: 0
        width: 64
        height: 64
        color: "#00000000"
        radius: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        border.color: "#808080"
        anchors.left: parent.left
        anchors.leftMargin: 10
        MouseArea {
            anchors.fill: parent
            onClicked: page.state = 'State2'
        }
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: icon
                x: 280
                y: 144
            }
        },
        State {
            name: "State2"

            PropertyChanges {
                target: icon
                x: 2
                y: 272
            }
        }
    ]
}

/*
import QtQuick 2.0

Rectangle {
    id: page
    width: 360
    height: 360
    color: "#61c2ab"

    Rectangle {
        id: topLeftRect
        width: 138
        height: 136
        color: "#00000000"
        anchors.leftMargin: 49
        anchors.topMargin: 34
        border.color: "#00000000"

        MouseArea {
            id: mouseArea1
            onClicked: page.state = ''
        }
    }

    Rectangle {
        id: middleRightRect
        x: 222
        y: 121
        width: 138
        height: 136
        color: "#00000000"
        anchors.right: parent.right
        anchors.rightMargin: 10
        border.color: "#00000000"
        MouseArea {
            anchors.left: parent.left
            anchors.leftMargin: 138
            anchors.top: parent.top
            anchors.topMargin: 136
            onClicked: page.state = 'State1'
        }
    }

    Rectangle {
        id: bottomLeftRect
        x: 0
        y: 224
        width: 138
        height: 136
        color: "#00000000"
        anchors.right: parent.right
        anchors.rightMargin: 222
        border.color: "#00000000"
        MouseArea {
            anchors.fill: parent
            onClicked: page.state = 'State2'
        }
    }

    Image {
        id: image2
        x: 0
        y: 0
        width: 138
        height: 136
        source: "miku.png"
    }
    states: [
            State {
                name: "State1"

                PropertyChanges {
                    target: icon
                    x: middleRightRect.x
                    y: middleRightRect.y
                }

                PropertyChanges {
                    target: image2
                    x: 49
                    y: 181
                }
            },

            State {
                name: "State2"

                PropertyChanges {
                    target: icon
                    x: bottomLeftRect.x
                    y: bottomLeftRect.y
                    fillMode: "Stretch"
                }

                PropertyChanges {
                    target: image2
                    x: 193
                    y: 94
                }

                PropertyChanges {
                    target: topLeftRect
                    anchors.topMargin: 34
                    anchors.leftMargin: 49
                }

                PropertyChanges {
                    target: mouseArea1
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                }
            }
        ]

        transitions: [
            Transition {
                  from: "*"; to: "State1"
                  NumberAnimation {
                      easing.type: Easing.OutBounce
                      properties: "x,y";
                      duration: 1000
                  }
            },

            Transition {
                   from: "*"; to: "State2"
                   NumberAnimation {
                       properties: "x,y";
                       easing.type: Easing.InOutQuad;
                       duration: 2000
                   }
            },

            Transition {
                NumberAnimation {
                    properties: "x,y";
                    duration: 200
                }
            }
        ]

}
*/
