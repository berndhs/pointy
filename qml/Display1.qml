import QtQuick 2.3

Rectangle {
  id: unitBox
  width: 100
  height: childrenRect.height
  color: "red"
  property real value: -1
  property alias title: titleText.text
  property real localRowHeight:  32
  property int precision:  4
  property int pointSize:  20
  property string valueLabel:  "value: "
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
      width:  unitBox.width
      height: childrenRect.height
      color: unitBox.color
      Text {
        font.pointSize: unitBox.pointSize
        width: parent.width
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        text: unitBox.valueLabel + unitBox.value
      }
    }
  }
}
