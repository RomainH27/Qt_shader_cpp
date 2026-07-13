import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import hello

Item {
    id: root

    property url imageUrl: ""

    ColumnLayout {
        anchors.fill: parent

        Slider {
            id: slider_one

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            from: 0
            to: 1
        }

        Image {
            id: scanImage

            source: "image://scanProvider/test"
            visible: false
        }

        ShaderEffect {
            property variant src: scanImage
            property real slider_test: slider_one.value

            Layout.fillHeight: true
            Layout.fillWidth: true
            vertexShader: "qrc:/shaders/custom_shader.vert.qsb"
            fragmentShader: "qrc:/shaders/custom_shader.frag.qsb"
        }

    }

    ScanObject {
        id: test_scan

        Component.onCompleted: {
            test_scan.ComputeData();
            console.log("Done eheh");
        }
    }

}
