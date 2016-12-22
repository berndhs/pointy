import QtQuick 2.0
import QtQuick.Controls 1.4

Menu {
    id: bigMenu;
    title: "Options"


    MenuItem: {
        title: "Restart"
        shortcut: "Ctrl+R"
        onTriggered: {
            console.log("would restart here if we could")
            bigMenu.visible = false;
        }
    }
}
