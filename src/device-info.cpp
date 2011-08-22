#include <QDebug>
#include <QTimer>


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

#include "device-info.h"


namespace geuzen
{
DeviceInfo::DeviceInfo (QObject *parent)
  :QObject (parent),
   sdi (this)
{
  connect (&sdi, SIGNAL (batteryLevelChanged (int)),
            this, SLOT (getBatteryLevel (int)));
  connect (&sdi, SIGNAL (batteryStatusChanged (QSystemDeviceInfo::BatteryStatus)),
            this, SLOT (getBatteryStatus (QSystemDeviceInfo::BatteryStatus)));
}

void
DeviceInfo::start ()
{
  QTimer::singleShot (750,this, SLOT (collectInfo()));
}

void
DeviceInfo::collectInfo ()
{
  int level = batteryLevel ();
  int status = batteryStatus ();
  emit batteryStatusChanged (status);
  emit batteryLevelChanged (level);
}

int
DeviceInfo::batteryLevel ()
{
  int newLevel = sdi.batteryLevel();
  return newLevel;
}

int
DeviceInfo::batteryStatus ()
{
  int newStatus = int (sdi.batteryStatus());
  return newStatus;
}

void
DeviceInfo::getBatteryLevel (int level)
{
  qDebug () << __PRETTY_FUNCTION__ << level;
  emit batteryLevelChanged (level);
}

void
DeviceInfo::getBatteryStatus (QSystemDeviceInfo::BatteryStatus status)
{
  qDebug () << __PRETTY_FUNCTION__ << status;
  emit batteryStatusChanged (status);
}

} // namespace
