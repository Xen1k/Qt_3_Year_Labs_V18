import QtQuick 2.0
import QtQuick.Layouts 1.3

MenuButton
{
    text: "Выход"
    width: 150
    height: 150
    function onClick() { Qt.quit() }
}
