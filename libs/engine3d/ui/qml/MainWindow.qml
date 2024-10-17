// Copyright (C) 2023 twyleg
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts

import "./items"

ApplicationWindow
{
    id: app

    visible: true
    width: 1920
    height: 1080
    title: qsTr("Minimal Qml Live Image Viewer")

    Row {
        width: parent.width
        height: parent.height

        Column {
            width: 400
            spacing: 10

            Item {
                width: parent.width
                height: cameraContent.visible ? 400 : 50

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "#dddddd"
                    border.color: "black"
                    border.width: 1
                    id: cameraContentRectangle

                    Text {
                        text: "Camera System Settings"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: cameraContent.visible = !cameraContent.visible
                    }

                }

                GridLayout {

                    id: cameraContent
                    visible: false

                    anchors.bottom: cameraContentRectangle.bottom;
                        
                    columns: 1
                    rowSpacing: 0
                    anchors.fill : parent
                    anchors.topMargin: 50
 
                    AdvancedSlider {
                        id: cameraSystemTranslationX
                        width: parent.width
                        name: "cameraSystemTranslationX"
                        from: 0
                        to: 20000
                        value: parameterModel.cameraSystemTranslationX
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemTranslationX = value
                    }    

                    AdvancedSlider {
                        id: cameraSystemTranslationY
                        width: parent.width
                        name: "cameraSystemTranslationY"
                        from: 0
                        to: 20000
                        value: parameterModel.cameraSystemTranslationY
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemTranslationY = value
                    }

                    AdvancedSlider {
                        id: cameraSystemTranslationZ
                        width: parent.width
                        name: "cameraSystemTranslationZ"
                        from: 0
                        to: 20000
                        value: parameterModel.cameraSystemTranslationZ
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemTranslationZ = value
                    }

                    AdvancedSlider {
                        id: cameraSystemRotationRoll
                        width: parent.width
                        name: "cameraSystemRotationRoll"
                        from: 0
                        to: 3600
                        value: parameterModel.cameraSystemRotationRoll
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemRotationRoll = value
                    }

                    AdvancedSlider {
                        id: cameraSystemRotationPitch
                        width: parent.width
                        name: "cameraSystemRotationPitch"
                        from: 0
                        to: 3600
                        value: parameterModel.cameraSystemRotationPitch
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemRotationPitch = value
                    }

                    AdvancedSlider {
                        id: cameraSystemRotationYaw
                        width: parent.width
                        name: "cameraSystemRotationYaw"
                        from: 0
                        to: 3600
                        value: parameterModel.cameraSystemRotationYaw
                        stepSize: 1
                        onValueChanged: parameterModel.cameraSystemRotationYaw = value
                    }
                }
            }



            Item {
                width: parent.width
                height: cubeContent.visible ? 400 : 50

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "#dddddd"
                    border.color: "black"
                    border.width: 1
                    id: cubeContentRectangle

                    Text {
                        text: "Cube System Settings"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: cubeContent.visible = !cubeContent.visible
                    }

                }

                GridLayout {

                    id: cubeContent
                    visible: false

                    anchors.bottom: cubeContentRectangle.bottom;
                        
                    columns: 1
                    rowSpacing: 0
                    anchors.fill : parent
                    anchors.topMargin: 50

                    AdvancedSlider {
                        id: cubeSystemTranslationX
                        width: parent.width
                        name: "cubeSystemTranslationX"
                        from: 0
                        to: 20000
                        value: parameterModel.cubeSystemTranslationX
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemTranslationX = value
                    }

                    AdvancedSlider {
                        id: cubeSystemTranslationY
                        width: parent.width
                        name: "cubeSystemTranslationY"
                        from: 0
                        to: 20000
                        value: parameterModel.cubeSystemTranslationY
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemTranslationY = value
                    }

                    AdvancedSlider {
                        id: cubeSystemTranslationZ
                        width: parent.width
                        name: "cubeSystemTranslationZ"
                        from: 0
                        to: 20000
                        value: parameterModel.cubeSystemTranslationZ
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemTranslationZ = value
                    }

                    AdvancedSlider {
                        id: cubeSystemRotationRoll
                        width: parent.width
                        name: "cubeSystemRotationRoll"
                        from: 0
                        to: 3600
                        value: parameterModel.cubeSystemRotationRoll
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemRotationRoll = value
                    }

                    AdvancedSlider {
                        id: cubeSystemRotationPitch
                        width: parent.width
                        name: "cubeSystemRotationPitch"
                        from: 0
                        to: 3600
                        value: parameterModel.cubeSystemRotationPitch
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemRotationPitch = value
                    }

                    AdvancedSlider {
                        id: cubeSystemRotationYaw
                        width: parent.width
                        name: "cubeSystemRotationYaw"
                        from: 0
                        to: 3600
                        value: parameterModel.cubeSystemRotationYaw
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemRotationYaw = value
                    }

                    AdvancedSlider {
                        id: cubeSystemScale
                        width: parent.width
                        name: "cubeSystemScale"
                        from: 0
                        to: 5
                        value: parameterModel.cubeSystemScale
                        stepSize: 1
                        onValueChanged: parameterModel.cubeSystemScale = value
                    }
 
                }
            }


            Item {
                width: parent.width
                height: drawContent.visible ? 200 : 50

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "#dddddd"
                    border.color: "black"
                    border.width: 1
                    id: drawContentRectangle

                    Text {
                        text: "Draw System Settings"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: drawContent.visible = !drawContent.visible
                    }

                }

                GridLayout {

                    id: drawContent
                    visible: false

                    anchors.bottom: drawContentRectangle.bottom;
                        
                    columns: 1
                    rowSpacing: 0
                    anchors.fill : parent
                    anchors.topMargin: 50

                    AdvancedSwitch {
                        name: "cubeSystemNormals"
                        width: parent.width
                        onValueChanged: parameterModel.cubeSystemNormals = value
                    }


                    AdvancedSwitch {
                        name: "cubeSystemPoints"
                        width: parent.width
                        onValueChanged: parameterModel.cubeSystemPoints = value
                    }

                    AdvancedSwitch {
                        name: "cubeSystemFaces"
                        width: parent.width
                        onValueChanged: parameterModel.cubeSystemFaces = value
                    }

                }
            }


            Item {
                width: parent.width
                height: curveContent.visible ? 550 : 50

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "#dddddd"
                    border.color: "black"
                    border.width: 1
                    id: curveContentRectangle

                    Text {
                        text: "Curve System Settings"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: curveContent.visible = !curveContent.visible
                    }

                }

                GridLayout {

                    id: curveContent
                    visible: false

                    anchors.bottom: curveContentRectangle.bottom;
                        
                    columns: 1
                    rowSpacing: 0
                    anchors.fill : parent
                    anchors.topMargin: 50

                    AdvancedSwitch {
                        name: "showCurve"
                        width: parent.width
                        onValueChanged: parameterModel.showCurve = value
                    }

                    AdvancedSlider {
                        id: curve_radius
                        width: parent.width
                        name: "curve_radius"
                        from: 0.01
                        to: 50
                        value: parameterModel.curve_radius
                        stepSize: 0.01
                        onValueChanged: parameterModel.curve_radius = value
                    }

                    AdvancedSlider {
                        id: track_width
                        width: parent.width
                        name: "track_width"
                        from: 0.01
                        to: 20
                        value: parameterModel.track_width
                        stepSize: 0.01
                        onValueChanged: parameterModel.track_width = value
                    }

                    AdvancedSlider {
                        id: dashed_length
                        width: parent.width
                        name: "dashed_length"
                        from: 0.01
                        to: 50
                        value: parameterModel.dashed_length
                        stepSize: 0.01
                        onValueChanged: parameterModel.dashed_length = value
                    }

                    AdvancedSlider {
                        id: dashed_space
                        width: parent.width
                        name: "dashed_space"
                        from: 0.01
                        to: 50
                        value: parameterModel.dashed_space
                        stepSize: 0.01
                        onValueChanged: parameterModel.dashed_space = value
                    }

                    AdvancedSlider {
                        id: line_width
                        width: parent.width
                        name: "line_width"
                        from: 0.01
                        to: 3
                        value: parameterModel.line_width
                        stepSize: 0.01
                        onValueChanged: parameterModel.line_width = value
                    }

                    AdvancedSlider {
                        id: curved_angle_start
                        width: parent.width
                        name: "curved_angle_start"
                        from: 0
                        to: 360
                        value: parameterModel.curved_angle_start
                        stepSize: 1
                        onValueChanged: parameterModel.curved_angle_start = value
                    }

                    AdvancedSlider {
                        id: curved_angle_end
                        width: parent.width
                        name: "curved_angle_end"
                        from: 0
                        to: 360
                        value: parameterModel.curved_angle_end
                        stepSize: 1
                        onValueChanged: parameterModel.curved_angle_end = value
                    }

                    AdvancedSwitch {
                        name: "dashed_middle"
                        width: parent.width
                        onValueChanged: parameterModel.dashed_middle = value
                    }


                    AdvancedSwitch {
                        name: "dashed_outer"
                        width: parent.width
                        onValueChanged: parameterModel.dashed_outer = value
                    }

                    AdvancedSlider {
                        id: subdivisions
                        width: parent.width
                        name: "subdivisions"
                        from: 0
                        to: 100
                        value: parameterModel.subdivisions
                        stepSize: 1
                        onValueChanged: parameterModel.subdivisions = value
                    }

                }
            }



            Item {
                width: parent.width
                height: straightContent.visible ? 400 : 50

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "#dddddd"
                    border.color: "black"
                    border.width: 1
                    id: straightContentRectangle

                    Text {
                        text: "Straight System Settings"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: straightContent.visible = !straightContent.visible
                    }

                }

                GridLayout {

                    id: straightContent
                    visible: false

                    anchors.bottom: straightContentRectangle.bottom;
                        
                    columns: 1
                    rowSpacing: 0
                    anchors.fill : parent
                    anchors.topMargin: 50

                    AdvancedSwitch {
                        name: "showStraight"
                        width: parent.width
                        onValueChanged: parameterModel.showStraight = value
                    }

                    AdvancedSlider {
                        id: length
                        width: parent.width
                        name: "length"
                        from: 0.01
                        to: 1
                        value: parameterModel.length
                        stepSize: 0.01
                        onValueChanged: parameterModel.length = value
                    }

                    AdvancedSlider {
                        id: width
                        width: parent.width
                        name: "width"
                        from: 0.01
                        to: 1
                        value: parameterModel.width
                        stepSize: 0.01
                        onValueChanged: parameterModel.width = value
                    }

                    AdvancedSlider {
                        id: stripeNum
                        width: parent.width
                        name: "stripeNumber"
                        from: 2
                        to: 25
                        value: parameterModel.stripeNumber
                        stepSize: 1
                        onValueChanged: parameterModel.stripeNumber = value
                    }

                    AdvancedSlider {
                        id: stripeLength
                        width: parent.width
                        name: "stripeLength"
                        from: 0.01
                        to: 1
                        value: parameterModel.stripeLength
                        stepSize: 0.01
                        onValueChanged: parameterModel.stripeLength = value
                    }

                    AdvancedSlider {
                        id: lineDistance
                        width: parent.width
                        name: "lineDistance"
                        from: 0.01
                        to: 5
                        value: parameterModel.lineDistance
                        stepSize: 0.01
                        onValueChanged: parameterModel.lineDistance = value
                    }

                    AdvancedSwitch {
                        name: "leftLine"
                        width: parent.width
                        onValueChanged: parameterModel.leftLine = value
                    }

                    AdvancedSwitch {
                        name: "stripedLine"
                        width: parent.width
                        onValueChanged: parameterModel.stripedLine = value
                    }

                    AdvancedSwitch {
                        name: "rightLine"
                        width: parent.width
                        onValueChanged: parameterModel.rightLine = value
                    }
                }
            }

        }

        Image {
            id: testImage
            width: 1280
            height: 960
            cache: false
            source: "image://stream/" + id
            property int id: 0

            function reload() {
                id++;
            }
        }
    }

    Connections {
        target: imageModel

        function onImageChanged() {
            testImage.reload()
        }
    }

}
