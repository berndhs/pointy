import QtQuick 2.3
import QtQuick.Controls 1.4
import moui.experiment.static 1.0
import moui.geuzen.utils.static 1.0
		

Rectangle {
  id: mainBox
  width:600
  height:600
  rotation: 0
  clip: false
  x: isPortrait ? (isInverted ? (width - height) * 0.5 : (height - width) * 0.5) : 0
  property bool isPortrait: false
  property bool isInverted: false
  property real rowHeight: 32
  property real mainWidth: isPortrait ? height : width
  property real mainHeight: isPortrait ? width : height
  
  GeuzenOrientation {
    id: orientationWatcher
    onRotationChange: {
      mainBox.isPortrait = portrait
      mainBox.rotation = rotation
      mainBox.isInverted = inverted
      console.log ("orientation port " + mainBox.isPortrait)
      console.log ("main box x " + mainBox.x + " y " + mainBox.y)
      console.log ("rect size: " + mainBox.width + ", " + mainBox.height)
      console.log ("my size  : " + mainWidth + ", " + mainHeight)
    }
    Component.onCompleted: {
      console.log ("have Orientation Watcher")
      console.log ("orientation port " + mainBox.isPortrait)
      console.log ("main box x " + mainBox.x + " y " + mainBox.y)
      console.log ("rect size: " + mainBox.width + ", " + mainBox.height)
      console.log ("my size  : " + mainWidth + ", " + mainHeight)
    }
  }

  GeuzenDeviceInfo {
    id: devInfo;
  }

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
  ProximitySense {
    id: proximitySensor
    onMeasurement: {
      proximityDisplay.value = isClose ? "close" : "far"
    }
  }
  
  GeuzenDeviceInfo {
    id: deviceInfo
//    onBatteryLevelChanged: {
//      battDisplay.value1 = batteryLevel
//    }
//    onBatteryStatusChanged: {
//      battDisplay.value2 = batteryStatus
//    }
  }

  Rectangle {
    id: titleBox
    anchors {top: mainBox.top; horizontalCenter: mainBox.horizontalCenter }
    width: mainWidth
    height: rowHeight * 1.5
    Text {
      font.pointSize:  18
      text: "Sensor Demo"
      anchors { centerIn: titleBox }
    }
    MouseArea {
      anchors.fill: parent
      onClicked: {
        console.log ("clicked")
        Qt.quit();
      }
    } 
    Button {
      id: pointyButton;
      height: titleBox.height -2;
      width: height;
      anchors {
          left: titleBox.left
          top: titleBox.top;
      }

      tooltip: "Restart";
      Image {
          anchors.centerIn: pointyButton;
          width: pointyButton.width;
          height: pointyButton.height;
          source: "/pointy.png"
      }
      onClicked: {
        //reload
          console.log("clicked on "+pointyButton.iconName+" / "+pointyButton.iconSource)
      }
    }
    Button {
        id: optionsButton;
        height: titleBox.height-2;
        width: height;
        anchors {
            left: pointyButton.right
            leftMargin: 2;
            top: titleBox.top;
        }

        tooltip: "Options"
        Image {
            anchors.centerIn: optionsButton;
            width: optionsButton.width;
            height: optionsButton.height/3;
            source: "/options.png"
        }

        onClicked: {
            // popup options
          console.log("clicked on "+optionsButton.iconName+" / "+optionsButton.iconSource)
        }
      }
  }
  Flickable {
    id: displayColumnFlick
    clip: true
    interactive: true
    height: mainHeight - titleBox.height
    width: mainWidth
    contentWidth: contentItem.childrenRect.width
    contentHeight: contentItem.childrenRect.height
    boundsBehavior: Flickable.DragAndOvershootBounds
    anchors { top:  titleBox.bottom; horizontalCenter: mainBox.horizontalCenter }
    Column {
      id: displayColumn

      Display3String {
        id: sysDisplay
        title: "System"
        width: mainWidth
        localRowHeight: rowHeight
        pointSize: 12
        value1Label: "OS "
        value2Label: "CPU "
        value3Label: "Kernel "
        value1: devInfo.sysName
        value2: devInfo.cpu
        value3: devInfo.kernel
        color: "#dfdfd0"
      }
      Display3 {
        id: accelDisplay
        title: "Linear Acceleration"
        width: mainWidth
        localRowHeight: rowHeight
        pointSize: 24
        color: "lightgreen"
      }
      Display3 {
        id: gyroDisplay
        title: "Angular Velocity"
        width: mainWidth
        localRowHeight: rowHeight
        pointSize: 24
        color: "lightblue"
      }
      Row {
        Display1 {
          id: ambientDisplay
          title: "Ambient Light"
          width: 0.5* mainWidth
          localRowHeight: rowHeight
          pointSize: 24
          color: "#d0ff70"
        }
        Display1 {
          id: luxDisplay
          title: "Lux"
          width: 0.5*mainWidth
          localRowHeight: rowHeight
          pointSize: 24
          color: "#c0e0f0"
        }
      }
      Display2 {
        id: compassDisplay
        title: "Compass"
        width: mainWidth
        localRowHeight: rowHeight
        pointSize: 24
        value1Label: "azimuth: "
        value2Label: "calibration: "
        color: "#f0d0a0"
      }
      Display1String {
        id: proximityDisplay
        title: "Proximity"
        width: mainWidth * 0.5
        localRowHeight: rowHeight
        pointSize: 24
        valueLabel:  "Distance: "
      }
    }
  }

  Component.onCompleted: {
    console.log ("load completed, calling start routines")
    orientationWatcher.start ()
    accelSensor.start ()
    gyroSensor.start()
    ambientSensor.start()
    luxSensor.start()
    compassSensor.start()
    deviceInfo.start ()
    proximitySensor.start()
    console.log ("all started")
  }
}

