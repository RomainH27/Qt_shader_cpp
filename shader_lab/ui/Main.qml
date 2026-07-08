import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

Window {
    visible: true
    width: 640
    height: 480
    title: "Shader Lab"

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "red"
        }

        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            // onClicked: model.submit()
            text: "Ok"
        }

    }

}
