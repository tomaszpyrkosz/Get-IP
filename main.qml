import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import getip 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Get IP")

    GetIP {
        id: getip
    }

    Button {
        x: 270
        y: 220
        text: qsTr("Get IP")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: getip.load()
    }

    Text {
        id: ip
        y: 143
        height: 32
        text: getip.ip;
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        font.pixelSize: 27
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenterOffset: -75
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        font.bold: true
    }
}

/*##^##
Designer {
    D{i:2}D{i:3}
}
##^##*/
