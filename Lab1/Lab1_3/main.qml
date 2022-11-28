import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12

Window {
    width: 740
    height: 580
    visible: true
    title: qsTr("Console UI")
    color: "#2E3784"
    ColumnLayout
    {
        id: menu
        visible: false
        RowLayout {
            spacing: 2
            MenuButton {
                text: "<-"
                width: 70
                height: 70
                function onClick() {
                    navigationButtons.visible = true;
                    menu.visible = false;
                    friends.visible = false;
                    settings.visible = false;
                    library.visible = false;
                }
            }
            Text {
                id: menuText
                font.pointSize: 18
                color: "White"
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
            }
        }

        FriendsTab
        {
            id: friends
            visible: false
        }
        SettingsTab
        {
            id: settings
            visible: false
        }
        LibraryTab
        {
            id: library
            visible: false
        }
    }
    RowLayout {
        id: navigationButtons
        anchors.fill: parent
        spacing: 2
        MenuButton
        {
            text: "Библиотека"
            width: 200
            height: 200
            function onClick() { navigationButtons.visible = false; library.visible = true; menu.visible = true; menuText.text = "Библиотека" }
        }
        MenuButton
        {
            text: "Настройки"
            width: 200
            height: 200
            function onClick() { navigationButtons.visible = false; settings.visible = true; menu.visible = true; menuText.text = "Настройки" }
        }
        MenuButton
        {
            text: "Друзья"
            width: 200
            height: 200
            function onClick() { navigationButtons.visible = false; friends.visible = true; menu.visible = true; menuText.text = "Друзья" }
        }

    }
}


