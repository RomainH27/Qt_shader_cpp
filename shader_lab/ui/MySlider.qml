import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import hello

Item {
    id: root

    property url imageUrl: ""

    ColumnLayout {
        id: shaderContainer

        anchors.fill: parent

        Image {
            id: scanImage

            sourceSize.width: root.width
            sourceSize.height: root.height / 1.5
            source: "image://scanProvider/test"
            visible: false
        }

        ShaderEffect {
            id: shaderEffect

            // aspect ratio of the source image
            readonly property real imgAspect: scanImage.sourceSize.height > 0 ? scanImage.sourceSize.width / scanImage.sourceSize.height : 1
            readonly property real containerAspect: shaderContainer.height > 0 ? shaderContainer.width / shaderContainer.height : 1
            property variant src: scanImage
            property real slider_test: 1

            Layout.preferredWidth: containerAspect > imgAspect ? shaderContainer.height * imgAspect : shaderContainer.width
            Layout.preferredHeight: containerAspect > imgAspect ? shaderContainer.height : shaderContainer.width / imgAspect
            opacity: slider_one.value
            vertexShader: "qrc:/shaders/custom_shader.vert.qsb"
            fragmentShader: "qrc:/shaders/custom_shader.frag.qsb"
        }

        Slider {
            id: slider_one

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            from: 0
            to: 1
        }

        Slider {
            id: slider_two

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            from: 0
            to: 1
        }

        Slider {
            id: slider_three

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            from: 0
            to: 1
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
