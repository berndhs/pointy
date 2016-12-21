import QtQuick 2.3

Rectangle {
  id: unitBox
  width: 100
  height: childrenRect.height
  color: "red"
  property real dx: -1
  property real dy: -1
  property real dz: -1
  property alias title: titleText.text
  property real localRowHeight:  32
  property int precision:  4
  property int pointSize:  20
  Column {
    Rectangle {
      id: titleBox
      width: unitBox.width
      height: childrenRect.height
      color: unitBox.color
      Text {
        id: titleText
        font.pointSize: unitBox.pointSize + 2
        width: parent.width
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        text:  "title"
      }
    }
    Rectangle {
      id: valueBox
      width: unitBox.width
      height: childrenRect.height
      color: unitBox.color
      Text {
        font.pointSize: unitBox.pointSize
        width: parent.width
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        text: "dx: " + dx.toPrecision (unitBox.precision) +
              " dy: " + dy.toPrecision (unitBox.precision) +
              " dz: " + dz.toPrecision (unitBox.precision)
      }
    }
  }
}
