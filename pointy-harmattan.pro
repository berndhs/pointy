
PROJECT = pointy
TARGET = pointy

TEMPLATE = app
QT += gui declarative

CONFIG += mobility
MOBILITY += sensors
MOBILITY += systeminfo

QMAKE_CXXFLAGS += -std=c++0x

DEFINES += MEEGO_EDITION_HARMATTAN=1

INCLUDEPATH += ./include

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += \
    src/main.cpp \
    src/sensor-bucket.cpp \
    src/orientation.cpp \ 
    src/device-info.cpp \
    src/viewer.cpp

HEADERS += \
    include/sensor-bucket.h \
    include/orientation.h \
    include/device-info.h \
    include/viewer.h

RESOURCES += pointy.qrc

MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/obj
RCC_DIR = tmp/rcc

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qml/pointy/Display3.qml


message ("meego edition $$MEEGO_EDITION")
message ("m_e_h $$MEEGO_EDITION_HARMATTAN")

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/pointy/bin
    INSTALLS += target
}

contains(MEEGO_EDITION,harmattan) {
    desktopfile.files = harmattan/$${TARGET}.desktop
    desktopfile.path = /usr/share/applications
    INSTALLS += desktopfile
}

contains(MEEGO_EDITION,harmattan) {
    icon.files = pointy.png
    icon.path = /usr/share/icons/hicolor/64x64/apps
    INSTALLS += icon
}


