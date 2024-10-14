// Copyright (C) 2024 twyleg
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {
    id: advancedSwitch

    property alias name: nameText.text
    property double value: 0.0

    Text {
        id: nameText
        Layout.alignment: Qt.AlignCenter
        Layout.preferredWidth: parent.width * 0.6
        clip: true
        color: "white"
    }

    Switch {
        id: slider

        Layout.fillWidth: true

        position: advancedSwitch.value

        onPositionChanged: {
            if(position != advancedSwitch.value) {
                advancedSwitch.value = position
            }
        }
    }


}
