import QtQuick 1.0

Rectangle {
  id: unitBox
  width: 100
  height: 62
  color: "red"
  property real dx: -1
  property real dy: -1
  property real dz: -1
  property alias title: titleText.text
  property real localRowHeight:  32
  property int precision:  4
  property int pointSize:  20
  Text {
    id: titleText
    font.pointSize: unitBox.pointSize + 2
    anchors { top: parent.top; horizontalCenter: parent.horizontalCenter }
    text:  "title"
  }
  Text {
    font.pointSize: unitBox.pointSize
    anchors { bottom: parent.bottom; left: parent.left }
    text: "dx: " + dx.toPrecision (unitBox.precision) +
          " dy: " + dy.toPrecision (unitBox.precision) +
          " dz: " + dz.toPrecision (unitBox.precision)
  }
}
