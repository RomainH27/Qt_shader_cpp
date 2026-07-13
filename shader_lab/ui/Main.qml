import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window


Window {
    visible: true
    width: 1000
    height: 600
    title: "Shader Lab"

    ColumnLayout {
        anchors.fill: parent

        MySlider{
            // Layout.fillWidth: true
            // Layout.fillHeight: true
            width: 600
            height : 600
            imageUrl: "qrc:/qt/qml/hello/resources/images.jpg"
            // someString: "red"
        }

      

    }

}
