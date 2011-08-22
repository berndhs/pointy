#ifndef GEUZEN_DEVICE_INFO_H
#define GEUZEN_DEVICE_INFO_H

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

#include <QSystemDeviceInfo>

QTM_USE_NAMESPACE

namespace geuzen
{

class DeviceInfo  : public QObject
{
Q_OBJECT
public:

  DeviceInfo (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
  Q_INVOKABLE int batteryLevel ();
  Q_INVOKABLE int batteryStatus ();
  
signals:

  void batteryLevelChanged (int batteryLevel);
  void batteryStatusChanged (int batteryStatus);
  
private slots:

  void getBatteryLevel (int);
  void getBatteryStatus (QSystemDeviceInfo::BatteryStatus  batteryStatus);
  void collectInfo ();
  
private:

  QSystemDeviceInfo   sdi;
  
};

} // namespace

#endif // DEVICEINFO_H
