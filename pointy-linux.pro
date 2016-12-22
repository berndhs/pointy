
#!/usr/bin/qmake
# this is for Qt5

PROJECT = pointy
TEMPLATE = app
TARGET = $$PROJECT

INSTALL_TARGET_DIR = /usr/local


QT += core gui quick
QT += widgets
QT += qml
QT += bluetooth
QT += multimedia
QT += sensors


RESOURCES = pointy.qrc

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ./include

SOURCES += \
    src/main.cpp \
    src/viewer.cpp \
    src/sensor-bucket.cpp \
    src/orientation.cpp \ 
    src/device-info.cpp

HEADERS += \
    include/viewer.h \
    include/sensor-bucket.h \
    include/orientation.h \
    include/device-info.h

MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/obj
RCC_DIR = tmp/rcc

target.path = $${INSTALL_TARGET_DIR}/bin
INSTALLS += target

desktopfile.files = linux/$${TARGET}.desktop
desktopfile.path = $${INSTALL_TARGET_DIR}/share/applications
INSTALLS += desktopfile

icon.files = pointy.png
icon.path = $${INSTALL_TARGET_DIR}/share/icons/hicolor/64x64/apps
INSTALLS += icon




