
PROJECT = pointy
# Add more folders to ship with the application, here
folder_01.source = qml/pointy
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
CONFIG += mobility
MOBILITY += sensors
MOBILITY += systeminfo

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ./include

SOURCES += \
    src/main.cpp \
    src/sensor-bucket.cpp \
    src/orientation.cpp \ 
    src/device-info.cpp

HEADERS += \
    include/sensor-bucket.h \
    include/orientation.h \
    include/device-info.h

MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/obj
RCC_DIC = tmp/rcc

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

