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

        RowLayout {
            spacing: 0

            Image {
                id: scanImageLeft

                sourceSize.width: root.width / 2
                sourceSize.height: (root.width / 2) / ScanSettings.ratio
                source: "image://scanProvider/left"
                visible: false
            }

            Image {
                id: scanImageRight

                sourceSize.width: root.width / 2
                sourceSize.height: (root.width / 2) / ScanSettings.ratio
                source: "image://scanProvider/right"
                visible: false
            }

            ShaderEffect {
                id: shaderEffectLeft

                // aspect ratio of the source image
                readonly property real imgAspect: scanImageLeft.sourceSize.height > 0 ? scanImageLeft.sourceSize.width / scanImageLeft.sourceSize.height : 1
                readonly property real containerAspect: shaderContainer.height > 0 ? (shaderContainer.width / 2) / shaderContainer.height : 1
                property variant src: scanImageLeft
                property int isLeft: 1

                Layout.preferredWidth: containerAspect > imgAspect ? shaderContainer.height * imgAspect : (shaderContainer.width / 2)
                Layout.preferredHeight: containerAspect > imgAspect ? shaderContainer.height : (shaderContainer.width / 2) / imgAspect
                Layout.margins: 0
                opacity: slider_one.value
                vertexShader: "qrc:/shaders/custom_shader.vert.qsb"
                fragmentShader: "qrc:/shaders/custom_shader.frag.qsb"
            }

            ShaderEffect {
                id: shaderEffectRight

                // aspect ratio of the source image
                readonly property real imgAspect: scanImageRight.sourceSize.height > 0 ? scanImageRight.sourceSize.width / scanImageRight.sourceSize.height : 1
                readonly property real containerAspect: shaderContainer.height > 0 ? (shaderContainer.width / 2) / shaderContainer.height : 1
                property variant src: scanImageRight
                property int isLeft: 0

                Layout.preferredWidth: containerAspect > imgAspect ? shaderContainer.height * imgAspect : (shaderContainer.width / 2)
                Layout.preferredHeight: containerAspect > imgAspect ? shaderContainer.height : (shaderContainer.width / 2) / imgAspect
                Layout.margins: 0
                opacity: slider_one.value
                vertexShader: "qrc:/shaders/custom_shader.vert.qsb"
                fragmentShader: "qrc:/shaders/custom_shader.frag.qsb"
            }

        }

        Slider {
            id: slider_one

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            value: 0.5
            from: 0
            to: 1
        }

        Slider {
            id: slider_two

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            from: 0
            to: 1
        }

        Slider {
            id: slider_three

            Layout.fillWidth: true
            Layout.preferredHeight: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            from: 0
            to: 1
        }

    }

}
