#include <QGuiApplication>
#include <QSensor>
#include <QDebug>
#include "sensor-bucket.h"
#include "device-info.h"
#include "orientation.h"
#include "viewer.h"
#include <QQuickView>

/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2011,
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/


int main(int argc, char *argv[])
{
  int again(0);
  do {
      QGuiApplication app(argc, argv);

      const char uri[] = "moui.experiment.static";
      const char utilUri[] = "moui.geuzen.utils.static";

      qmlRegisterType<experiment::AccelSense>(uri,1,0,"AccelSense");
      qmlRegisterType<experiment::GyroSense>(uri,1,0,"GyroSense");
      qmlRegisterType<experiment::AmbientLightSense>(uri,1,0,"AmbientLightSense");
      qmlRegisterType<experiment::LuxSense>(uri,1,0,"LuxSense");
      qmlRegisterType<experiment::CompassSense>(uri,1,0,"CompassSense");
      qmlRegisterType<experiment::ProximitySense>(uri,1,0,"ProximitySense");
      qmlRegisterType<geuzen::DeviceInfo>(utilUri,1,0,"GeuzenDeviceInfo");
      qmlRegisterType<geuzen::OrientationWatcher>(utilUri, 1, 0,
                                                  "GeuzenOrientation");

      PointyViewer viewer;

      QObject::connect (&viewer,SIGNAL(quit()), &app, SLOT(quit()));
      viewer.runQrc ("main.qml");

      again = app.exec();
    } while (again == 42);
}
