import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: button
    color: "#4C59D8"
    border.color: "white"
    border.width: 2
    Layout.alignment: Qt.AlignCenter
    radius: 15
    visible: true
    property alias text: text.text
    function onClick() { }
    Text {
        id: text
        font.pointSize: 18
        color: "White"
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
    }
    MouseArea {
        id: mouse
        anchors.fill: parent
        hoverEnabled: true
        onEntered: { button.color = "#7984EC" }
        onExited: { button.color = "#4C59D8" }
        onClicked: { button.onClick() }
    }
}
