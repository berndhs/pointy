import QtQuick 1.0
import moui.experiment.static 1.0

Rectangle {
  id: mainBox
  width: 360
  height: 360
  rotation: 0
  property real rowHeight: 32
  property real mainWidth: width
  property real mainHeight: height
  
  AccelSense {
    id: accelSensor
    onMeasurement: {
      accelDisplay.dx = dx;
      accelDisplay.dy = dy;
      accelDisplay.dz = dz;
    }
  }
  GyroSense {
    id: gyroSensor
    onMeasurement: {
      gyroDisplay.dx = dx;
      gyroDisplay.dy = dy;
      gyroDisplay.dz = dz;
    }
  }
  AmbientLightSense {
    id: ambientSensor
    onMeasurement: {
      ambientDisplay.value = level;
    }
  }
  LuxSense {
    id: luxSensor
    onMeasurement: {
      luxDisplay.value = lux;
    }
  }
  CompassSense {
    id: compassSensor
    onMeasurement: {
      compassDisplay.value1 = degrees
      compassDisplay.value2 = calibration
    }
  }

  Rectangle {
    id: titleBox
    anchors {top: mainBox.top; horizontalCenter: mainBox.horizontalCenter }
    width: mainWidth
    height: rowHeight
    Text {
      font.pointSize:  28
      text: "Sensor Test"
      anchors { centerIn: titleBox }
    }
    MouseArea {
      anchors.fill: parent
      onClicked: {
        console.log ("clicked")
        Qt.quit();
      }
    } 
  }
  
  Column {
    anchors { top: titleBox.bottom; horizontalCenter:  titleBox.horizontalCenter }
    Display3 {
      id: accelDisplay
      title: "Linear Acceleration"
      width: mainWidth
      height: 2.0 * rowHeight
      localRowHeight: rowHeight
      pointSize: 24
      color: "lightgreen"
    }
    Display3 {
      id: gyroDisplay
      title: "Angular Velocity"
      width: mainWidth
      height: 2.0 * rowHeight
      localRowHeight: rowHeight
      pointSize: 24
      color: "lightblue"
    }
    Row {
      Display1 {
        id: ambientDisplay
        title: "Ambient Light"
        width: 0.5* mainWidth
        height: 2.0 * rowHeight
        localRowHeight: rowHeight
        pointSize: 24
        color: "#d0ff70"
      }
      Display1 {
        id: luxDisplay
        title: "Lux"
        width: 0.5*mainWidth
        height: 2.0 * rowHeight
        localRowHeight: rowHeight
        pointSize: 24
        color: "#c0e0f0"
      }
    }
    Display2 {
      id: compassDisplay
      title: "Compass"
      width: mainWidth
      height: 2.0 * rowHeight
      localRowHeight: rowHeight
      pointSize: 24
      value1Label: "azimuth: "
      value2Label: "calibration: "
      color: "#f0d0a0"
    }
  }

  Component.onCompleted: {
    console.log ("load completed, calling start routines")
    accelSensor.start ()
    gyroSensor.start()
    ambientSensor.start()
    luxSensor.start()
    compassSensor.start()
  }
}
