import QtQuick 2.3

Rectangle {
  id: unitBox
  width: 100
  height: childrenRect.height
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
      color:  unitBox.color
      Text {
        font.pointSize: unitBox.pointSize
        width: parent.width
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        text: unitBox.value1Label + unitBox.value1.toFixed(unitBox.precision1) + " " +
              unitBox.value2Label + unitBox.value2.toFixed(unitBox.precision2)
      }
    }
  }
}
