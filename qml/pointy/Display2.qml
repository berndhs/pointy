import QtQuick 1.0

Rectangle {
  id: unitBox
  width: 100
  height: 62
  color: "red"
  property real value1: -1
  property real value2: -1
  property alias title: titleText.text
  property real localRowHeight:  32
  property int precision1:  4
  property int precision2:  4
  property int pointSize:  20
  property string value1Label:  "value1: "
  property string value2Label:  "value2: "
  Text {
    id: titleText
    font.pointSize: unitBox.pointSize + 2
    anchors { top: parent.top; horizontalCenter: parent.horizontalCenter }
    text:  "title"
  }
  Text {
    font.pointSize: unitBox.pointSize
    anchors { bottom: parent.bottom; left: parent.left }
    text: unitBox.value1Label + unitBox.value1.toFixed(unitBox.precision1) + " " +
          unitBox.value2Label + unitBox.value2.toFixed(unitBox.precision2)
  }
}
