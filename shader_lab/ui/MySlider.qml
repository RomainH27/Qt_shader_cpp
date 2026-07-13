import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import hello

Item{
    id : root
    property url imageUrl : ""
    // property color frameColor
    // property string someString : ""

    // Rectangle{
    //     width: root.width
    //     height: root.height
    //     // color: "red"
    //     border.color: "black"

    //     Image{
    //         anchors.fill: parent
    //         anchors.margins: 30
    //         source: root.imageUrl
    //     }
    // }

    ColumnLayout {
        anchors.fill: parent

        layer.effect: ShaderEffect {
            Layout.fillHeight: true
            Layout.fillWidth: true
            property variant src: test_scan.GetData()
            property variant shader_opacity: slider_one.value
            vertexShader: " ://shaders/custom_shader.vert.qsb"
            fragmentShader: " ://shaders/custom_shader.frag.qsb"
        }

        Slider{
            id: slider_one
            Layout.fillWidth: true
            Layout.preferredHeight: 20

            from: 0
            to: 1
       }
    }
    

    ScanObject{
        id: test_scan
        
        Component.onCompleted: {
                test_scan.ComputeData();
                console.log("Done eheh");
        }
    }

}