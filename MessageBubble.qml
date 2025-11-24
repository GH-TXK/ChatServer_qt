// import QtQuick 2.15

// Item {

// }


import QtQuick
import QtQuick.Controls

Rectangle {
    property string text: ""
    property bool isSelf: false

    width: parent.width
    height: implicitHeight
    color: isSelf ? "#d0f0c0" : "#f0f0f0"
    radius: 8
    anchors.horizontalCenter: parent.horizontalCenter
    border.color: "#cccccc"

    Text {
        text: parent.text
        wrapMode: Text.Wrap
        anchors.margins: 8
        anchors.fill: parent
        color: "#333333"
    }
}
