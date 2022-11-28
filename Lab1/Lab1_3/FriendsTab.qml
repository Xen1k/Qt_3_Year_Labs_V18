import QtQuick 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    Layout.alignment: Qt.AlignCenter
    Text {
        id: text
        font.pointSize: 18
        color: "White"
        text: "Name1: 1h ago\nName2: 3d ago"
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
    }
}
