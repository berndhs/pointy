#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QSensor>
#include <QDebug>
#include "sensor-bucket.h"
#include <qdeclarative.h>

QTM_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    const char uri[] = "moui.experiment.static";
    
    qmlRegisterType<experiment::AccelSense>(uri,1,0,"AccelSense");
    qmlRegisterType<experiment::GyroSense>(uri,1,0,"GyroSense");
    qmlRegisterType<experiment::AmbientLightSense>(uri,1,0,"AmbientLightSense");
    qmlRegisterType<experiment::LuxSense>(uri,1,0,"LuxSense");
    qmlRegisterType<experiment::CompassSense>(uri,1,0,"CompassSense");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/pointy/main.qml"));
    viewer.showExpanded();


    return app.exec();
}
